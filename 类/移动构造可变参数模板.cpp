#include "../wjxHeaders.h"

//虽然是移动构造，但是因为没有可变参数模板，导致，构造的时候必须用std::move来转成右值
class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int age, int height) {

		cout << "有参构造函数!" << endl;

		m_age = age;
		m_height = new int(height);

	}

    //如果给定移动构造，不会默认有拷贝构造
	//移动构造函数  
    template<typename Args>
	Person(Args&&args) {
        constructor(std::forward<Args>(args));
	}

	//析构函数
	~Person() {
		cout << "析构函数!" << endl;
		if (m_height != NULL)
		{
			delete m_height;
		}
	}
public:
	int m_age;
	int* m_height;
private:
    void constructor(Person &p) {
        this->m_age = p.m_age;
        this->m_height = new int(*p.m_height);
        cout<<"copy constructor\n";
    }
    void constructor(Person && p) {
        this->m_age = p.m_age;
        this->m_height = p.m_height;
        p.m_height=nullptr;
        cout<<"move constructor\n";
    }
};
ostream& operator<<(ostream &out,Person &p) {
    cout<<"age:"<<p.m_age<<",height:"<<*p.m_height<<std::endl;
    return out;
}
int main()
{
    Person p1(10,170);
    
    //Person p2(p1);

    Person p2(p1);
	
}