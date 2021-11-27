#if 0
#include <iostream>
#include <cstring>

using namespace std;

//vscode ����ʹ�� strcpy
class String
{

public:
    String(const char* str = nullptr);
    String(const String& other);
    ~String();
    String& operator=(const String& other);

    char* getdata() const;

    void push_back(const char& ch);

private:
    char* m_data;
    int capacity;
    int idx;
};
ostream& operator<<(ostream& cout, String& p)
{
    cout << p.getdata();

    return cout;
}
void test01()
{
    String str("hello");

    cout << str << endl;

    str.push_back('a');
    str.push_back('b');
    str.push_back('c');
    str.push_back('d');
    str.push_back('e');

    cout << str << endl;

    String str2 = str;
    cout << "str2=" << str2 << endl;

    // const char *str="wenjx";
    // char *mystr = new char[10];

    // strcpy(mystr,str);
    // cout<<mystr<<endl;

    // mystr[5]='u';
    // cout<<mystr<<endl;

}

int main()
{
    test01();

    return 0;
}

String::String(const char* str)
{
    this->capacity = 10;
    this->idx = 0;
    if (!str)
    {
        this->m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        if (this->capacity < length)
            capacity = length * 2;
        m_data = new char[capacity];
        //strcpy_s��Ҫ�Ĳ�����(char *,const char *),����������ߵ�m_data ������char *String::����
        //strcpy(m_data, str);
        for (int i = 0; i < length; ++i)
            this->m_data[i] = str[i];
        this->idx = length;
    }
}

String::String(const String& other)
{
    //int length = strlen(other.m_data);
    this->capacity = other.capacity;
    m_data = new char[capacity];
    this->idx = other.idx;
    for (int i = 0; i < other.idx; ++i)
        this->m_data[i] = other.m_data[i];
    //strcpy(m_data, other.m_data);
}

String::~String()
{
    delete[] m_data;
}

String& String::operator=(const String& other)
{
    if (this == &other)
        return *this; //����Ը�ֵ
    delete[] m_data;

    this->capacity = other.capacity;
    m_data = new char[capacity];
    this->idx = other.idx;
    for (int i = 0; i < this->idx; ++i)
        this->m_data[i] = other.m_data[i];
    //strcpy(m_data, other.m_data);
    return *this;
    // TODO: �ڴ˴����� return ���
}
char* String::getdata() const
{
    return this->m_data;
}
void String::push_back(const char& ch)
{
    //if (idx == capacity)
    //{
    //    capacity *= 2;
    //}
    //char* temp = new char[idx + 2];
    //strcpy(temp, this->m_data);
    //delete[] m_data;

    //m_data = new char[capacity];
    //strcpy(m_data, temp);

    //delete[] temp;

    //this->m_data[idx] = ch;
    //++idx;
    if (idx == capacity)
        capacity *= 2;
    char* temp = new char[idx + 2];
    for (int i = 0; i < idx; ++i)
        temp[i] = this->m_data[i];

    delete[] this->m_data;
    this->m_data = new char[capacity];

    for (int i = 0; i < idx; ++i)
        this->m_data[i] = temp[i];
    delete[] temp;
    this->m_data[idx++] = ch;
}
#endif
