#include <iostream>
#include <string>
using namespace std;


int main()
{
	/*
	if (1) 
		cout << "ham";
	if (-1) 
		cout << " sandwhich";
	if ('a') 
		cout << " with";
	if (5 > 4)
	{
		cout << " butter,";
		cout << " cheese,";
		cout << " lettuce,";
	}
	if (5 >= 4)
		cout << " tomatoes,";
	if (3 != 3)
		cout << " pickles,";
	if (3 == 3)
		cout << " on wheat";

	if (3 && 3)
		cout << " with";
	if (0 || -1)
		cout << " orange juice";
	*/
	/*
	if (4 > 5)
		cout << "You'll never see this message.";
	else
		cout << "Pork belly is yummy!\n";

	if (0)
		cout << "nope, won't see this either m8";
	else if (1)
		cout << "Witches are best in sand.";
	*/
	/*
	5 > 4 ? cout << "True\n" : cout << "False\n";
	int x(5 > 4 ? 1 : 2);
	
	cout << x << endl;
	*/

	switch (1)
	{
	case 1:
		cout << "at 1" << endl;
		break;
	case 2:
		cout << "at 2" << endl;
		break;
	case 3:
		cout << "at 3" << endl;
		break;
	}


	string z;
	getline(cin, z);

	return 0;
}