#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*
	int a(5);
	int* p1(&a);
	int* p2(p1);

	cout << &a << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << *&a << endl;
	cout << *p1 << endl;
    */
	/*
	int a[]{ 1,2,3 };
	int* p1(&a[0]);

	cout << *p1 << endl;
	cout << p1[0] << endl;
	cout << p1[1] << endl;
	cout << p1[2] << endl;
	cout << ' ' << endl;
	cout << a << endl;
	cout << p1 << endl;
	cout << p1 + 1 << endl;
	cout << &p1[1] << endl;

	int b(777);
	int* p2(&b);

	cout << p2[0] << endl;
	*/

	int a1(5),
		a2(6),
		a3(7);

	int* p1(&a1),
		*p2(&a2),
		*p3(&a3);

	int* pa[]{ p1,p2,p3 };

	cout << pa << endl;
	cout << *pa << endl;
	cout << **pa << endl;
	cout << pa[0] << endl;
	cout << *pa[0] << endl;
	cout << pa[0][0] << endl;

	cout << ' ' << endl;
	
	cout << pa << endl;
	cout << &pa[1] << endl;
	cout << pa + 1 << endl;
	cout << &pa[2] << endl;
	cout << pa + 2 << endl;


	string y;
	getline(cin, y);

	return 0;
}