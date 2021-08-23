#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*
	int my_array[2];
	my_array[0] = 0;
	my_array[1] = 1;

	int my_array2[3] = { 0, 1, 2 };
	int my_array3[3] { 4 };
	int my_array4[]{7,7,7};
	int my_array5[4]{};

	cout << my_array3[2] << endl;
*/
	/*
	int array_2d[2][3];
	array_2d[0][0] = 1;
	array_2d[1][2] = 6;
*/
	/*
	char a[] = "asdf";
	char b[5] = "asdf";
	char c[]{ 'a','b','\0'};
	char d[]{ 'a','b','\0','c','\0' };

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
*/

	cout << sizeof(string) << endl;
	cout << sizeof(char) << endl;

	string cee = "cee";
	string plus = "plus";

	cee.swap(plus);
	cout << cee << endl;
	cout << plus << endl;
	cout << cee.size() << endl;
	cout << cee.find('p') << endl;
	cout << cee[2] << endl;
	string x = cee + plus;
	plus += cee;

	cout << plus << endl;
	cout << x << endl;

	char my_array[]{ "abcdef" };

	cout << my_array << endl;


	string y;
	getline(cin, y);

	return 0;
}