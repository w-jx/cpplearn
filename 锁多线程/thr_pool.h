#pragma once
#ifndef THREAD_POOL_THREADPOOL_H
#define THREAD_POOL_THREADPOOL_H

#include <functional>
#include <future>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include "SafeQueue.h"

using task = std::function<void()>;

class ThreadPool {
public:
    ThreadPool(size_t thread_num = std::thread::hardware_concurrency()) : m_threads(
        std::vector<std::thread>(thread_num)), m_shutdown(false) {
    }

    void init() {
        for (int i = 0; i < m_threads.size(); ++i) {
            m_threads[i] = std::thread(WorkerThread(this, i));
        }
    }

    void shutdown() {
        m_shutdown = true;
        m_condition_variable.notify_all();
        for (int i = 0; i < m_threads.size(); ++i) {
            if (m_threads[i].joinable()) {
                m_threads[i].join();
            }
        }
    }


    std::future<void> submit(task t) {
        auto p_task = std::make_shared<std::packaged_task<void()>>(t);
        task wrapper_task = [p_task]() {
            (*p_task)();
        };
        m_queue.enqueue(wrapper_task);
        m_condition_variable.notify_one();
        return p_task->get_future();
    }

private:
    class WorkerThread {
    private:
        int m_id;
        ThreadPool* m_pool;
    public:
        WorkerThread(ThreadPool* pool, int id) : m_pool(pool), m_id(id) {

        }

        void operator()() {
            task func;
            bool dequeued;
            while (!m_pool->m_shutdown) {
                std::unique_lock<std::mutex> lock(m_pool->m_mutex);
                if (m_pool->m_queue.empty()) {
                    m_pool->m_condition_variable.wait(lock);
                }
                dequeued = m_pool->m_queue.dequeue(func);
                if (dequeued) {
                    func();
                }
            }
        }
    };

    bool m_shutdown;
    SafeQueue<task> m_queue;
    std::vector<std::thread> m_threads;
    std::mutex m_mutex;
    std::condition_variable m_condition_variable;

};

#endif //THREAD_POOL_THREADPOOL_H