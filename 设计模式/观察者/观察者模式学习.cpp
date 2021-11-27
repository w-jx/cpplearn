#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#define OBSERVER_TRADITIIONAL 0
#define OBSERVER_INTERFACE 0
#define OBSERVER_INTERFACE_SHARED_PTR 1
//知乎上的例子


#if OBSERVER_TRADITIIONAL
//传统的模式
//弊端：比如关心我的人很多，有1000个人，岂不是在Me要加1000个对象
class Son{
public:
    void DoSomething(){
        std::cout<<"爸爸回来了，赶紧去写作业"<<std::endl;
    }
};

class Wife{
public:
    void DoSomething(){
        std::cout<<"老公回来了，去做饭"<<std::endl;
    }
};

class Me{
public:
    void Gohome(){
        wife.DoSomething();
        son.DoSomething();
    }
private:
    Wife wife;
    Son son;
};

void Test_OBSERVER_TRADITIIONAL(){
    Me me;
    me.Gohome();
}
#endif

#if OBSERVER_INTERFACE
//观察者接口
class ObserverInterface{
public:
    virtual void dosomething()=0;
    virtual ~ObserverInterface(){}
};
//被观察者接口
class SubjectInterface{
public:
    virtual void Add(ObserverInterface* obr)=0;
    virtual void Remove(ObserverInterface* obr)=0;
    virtual void Notify()=0;

    virtual ~SubjectInterface(){}
};
//我自己
class Me:public SubjectInterface{
public:
    void Add(ObserverInterface* obr) override{
        observers.push_back(obr);
    }

    void Remove(ObserverInterface* obr) override{
        auto pos=std::find(observers.begin(),observers.end(),obr);
        if(pos!=observers.end()){
            observers.erase(pos);
        }
    }

    void Notify() override{
        for(const auto& obs:observers){
            obs->dosomething();
        }
    }

private:
    std::vector<ObserverInterface*> observers;
};

class Wife:public ObserverInterface{
public:
    void dosomething() override{
        std::cout<<"老公快回来了，开始做饭"<<std::endl;
    }
};

class Son:public  ObserverInterface{
public:
    void dosomething() override {
        std::cout<<"爸爸快回来了，不能玩游戏了"<<std::endl;
    }
};

void TEST_OBSERVER_INTERFACE()
{
    Me me;
    // ObserverInterface* wife=new Wife;
    // ObserverInterface* son=new Son;
    Wife *wife = new Wife;
    Son *son = new Son;//两种都可以的
    me.Add(wife);
    me.Add(son);
    me.Notify();
    delete wife;
    delete son;
} 
#endif 


//利用shared_ptr 代替普通指针
#if OBSERVER_INTERFACE_SHARED_PTR
class ObserverInterface{
public:
    virtual void dosomething()=0;

    //virtual ~ObserverInterface(){}
};
using pObserverInterface=std::shared_ptr<ObserverInterface>;
class SubjectInterface{
public:
    virtual void Add(pObserverInterface obr)=0;
    virtual void Remove(pObserverInterface obr)=0;
    virtual void Notify()=0;

    //virtual ~SubjectInterface(){}
};

class Me:public SubjectInterface{
public:
    void Add(pObserverInterface obr) override{
        observers.push_back(obr);
    }

    void Remove(pObserverInterface obr) override{
        auto pos=std::find(observers.begin(),observers.end(),obr);
        if(pos!=observers.end()){
            observers.erase(pos);
        }
    }

    void Notify() override{
        for(const auto& obs:observers){
            obs->dosomething();
        }
    }

private:
    std::vector<pObserverInterface> observers;//vector存的是智能指针变量
};

class Wife:public ObserverInterface{
public:
    void dosomething() override{
        std::cout<<"老公快回来了，开始做饭"<<std::endl;
    }

};

class Son:public  ObserverInterface{
public:
    void dosomething() override {
        std::cout<<"爸爸快回来了，不能玩游戏了"<<std::endl;
    }
};

void TEST_OBSERVER_INTERFACE_SHARED_PTR()
{
    Me me;
    auto wife=std::make_shared<Wife>();
    auto son=std::make_shared<Son>();
    me.Add(wife);
    me.Add(son);
    me.Notify();
}
#endif 



int main(){
    //Test_OBSERVER_TRADITIIONAL();
    //TEST_OBSERVER_INTERFACE();
    TEST_OBSERVER_INTERFACE_SHARED_PTR();
    return 0;
}
