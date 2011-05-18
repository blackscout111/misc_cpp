#include <iostream>
#include "cplxnum.h"

using namespace std;

int main()
{
	cplxnum n[7];

	n[0] = cplxnum(1.4,2);
	n[1] = cplxnum(3,4);
	n[2] = cplxnum(6,0);
	n[3] = n[0] + n[1];
	n[4] = n[2] - n[3];
	n[5] = n[1]*n[2];
	n[6] = n[1]/n[2];

	for (int i = 0; i < 7; i++)
	{
		// displays n[i],n[i]*,|n[i]|,angle(n[i])
		cout << "n[" << i << "] = ";
		n[i].disp();
		cout << endl << endl;

		cout << "n[" << i << "]* = ";
		n[i].conj().disp();
		cout << endl << endl;

		cout << "|n[" << i << "]| = " << n[i].mag() << endl << endl;

		cout << "angle(n[" << i << "]) = " << n[i].angle() << endl << endl;
		
		cout << "-------------------------------" << endl << endl;
	}



	cout << "Press ENTER to continue..." << endl;
	cin.get();

	return 0;
}

