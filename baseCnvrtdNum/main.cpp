#include <iostream>
#include <iomanip>
#include "baseCnvrtdNum.h"

using namespace std;


int main(int argc, char* argv[])
{
	// Checks to see if there are the right number of arguments
	if (argc != 3)
	{
		cout 	<< "Wrong number of arguments!"
			<< endl
			<< "--------------------------"
			<< endl
			<< "Please only enter values for: "
			<< "num, base (in that order)"
			<< endl
			<< endl
			<< "Press ENTER to continue...";

		cin.get();

		return -1;
	}


	int 	num = atof(argv[1]),
		base = atof(argv[2]);

	baseCnvrtdNum object1;

	object1.print();
	cout << endl << endl;

	object1 = baseCnvrtdNum(num, base);

	object1.print();
	cout << endl << endl;

	cout << "object1[2] = " << object1[2];

	cout	<< endl << endl;
	cout << "Press ENTER to continue..." << endl;
	cin.get();

	return 0;
}
