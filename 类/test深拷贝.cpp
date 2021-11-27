#include <iostream>
using namespace std;

class Hasptr{
	public:
		Hasptr():d(new int(0)){}
		//Hasptr(const Hasptr &h):d(new int(*h.d)){}
		~Hasptr(){
			delete d;}

		void print(){
			cout<<*d<<endl;}

	private:
		int *d;

};
int main()
{
	Hasptr a;
	Hasptr d(a);
	a.print();
	d.print();

}
