#if 0
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Stack {

private:

	std::vector<T> elems; // 存储元素的容器

public:

	void push(T const&);// 压入元素

	void pop();// 弹出元素

	T top() const;// 返回栈顶元素

	bool empty() const {// 返回栈是否为空

		return elems.empty();
	}

};

template <typename T>
void Stack<T>::push(T const& elem)
{

	elems.push_back(elem);// 把elem的拷贝附加到末尾

}

template<typename T>
void Stack<T>::pop()
{

	if (elems.empty()) {

		throw std::out_of_range("Stack<>::pop(): empty stack");

	}

	elems.pop_back();//删除最后一个元素

}

template <typename T>
T Stack<T>::top() const
{

	if (elems.empty()) {

		throw std::out_of_range("Stack<>::top(): empty stack");

	}

	return elems.back(); // 返回最后一个元素的拷贝

}
// 模板特化
template<>
class Stack<std::string> {
private:
	std::deque<std::string> elems;//包含元素的容器
public:
	inline void push(std::string&& elm)
	{
		this->elems.push_back(elm);
	}
	inline void pop() {;// 弹出元素
		
	if (elems.empty()) {

		throw std::out_of_range("Stack<>::pop(): empty stack");

	}

	elems.pop_back();//删除最后一个元素
	}

	inline std::string top() const {// 返回栈顶元素
		std::cout << "this is std::string\n";
		if (elems.empty()) {
			throw std::out_of_range

			("Stack<std::string>::top(): empty stack");
		}
		return elems.back();// 返回末端元素的拷贝
	}

	inline  bool empty() const {// 返回栈是否为空

		return elems.empty();
	}
};


int main()
{
	Stack<int > intStack;
	intStack.push(1);
	std::cout << intStack.top() << std::endl;


	using IntStack = Stack<int >;
	IntStack intstack2;
	intstack2.push(3);
	std::cout << intstack2.top() << std::endl;


	typedef Stack<std::string> StringStack;
	StringStack strStack;
	strStack.push("hello\n");
	std::cout << strStack.top() << std::endl;

	std::vector<int> v{ 1,2,3,4,5 };
	std::transform(v.begin(), v.end(),v.begin(), [=](int const& x)->int {return x + 5; });

	[=]() {
		for (auto const &  iter : v) {
			std::cout << iter << " ";
		}
		std::cout << std::endl;;
	}();

}



#endif