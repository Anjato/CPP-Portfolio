#include <iostream>
#include <string>
using namespace std;

int main()
{
	//INPUT
	/*
	string x;

	cout << "Please enter an int: ";
	cin >> x;
	cout << "Thank you!" << endl;
	cin >> x;
	*/
	/*
	char x, y;
	int max_num_char(100);
	char stop_at(' ');

	x = cin.get();
	cin.ignore(max_num_char, stop_at);
	y = cin.get();
	cin.ignore(max_num_char, '\n');
	cout << x << y << endl;

	string z;
	getline(cin, z);
*/
	/*
	string y;
	cout << "Plus Type:";
	getline(cin, y);
	cout << "Creating " << y;
	cout << " plus." << endl;
	cout << "Press enter to exit...";
	getline(cin, y);
*/



	//OPERATORS
	/*
	cout << 5 + 4 << endl;
	cout << 5 - 4 << endl;
	cout << 5 * 4 << endl;
	cout << 5 / 4.0 << endl;
	cout << 5 % 4 << endl;

	int base(100);
	base += 8;
	cout << base << endl;
*/
	/*
	int wounds(0);

	wounds++;
	++wounds;

	cout << wounds << endl;
	wounds--;
	cout << wounds << endl;
*/

	cout << !true << endl;
	cout << (5 == 4) << endl;
	cout << (5 != 4) << endl;
	cout << (5 < 4) << endl;
	cout << (5 > 4) << endl;
	cout << (5 <= 4) << endl;
	cout << (5 >= 4) << endl;
	cout << (true && true) << endl;
	cout << (true || false) << endl;


	string y;
	getline(cin, y);

	return 0;
}