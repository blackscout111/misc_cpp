#ifndef cplxnum_h
#define cplxnum_h

#include <iostream>
#include <cmath>
using namespace std;

class cplxnum
{
public:
	double real,img;

	cplxnum();
	cplxnum(int, double);
	cplxnum(double, int);
	cplxnum(int, int);
	cplxnum(double, double);

	void disp();	// prints the value of a cplxnum on the consol window
	double mag();	// returns the magnitude of the a cplxnum
	double angle();	// returns the phase angle of a cplxnum in radians
	cplxnum conj();	// returns the complex conjugate of a cplxnum

	cplxnum operator +(const cplxnum&);	// allows for the addition of a cplxnum
	cplxnum operator -(const cplxnum&);	// allows for the subtraction of a cplxnum
	cplxnum operator *(const cplxnum&);	// allows for the multiplication of a cplxnum
	cplxnum operator /(const cplxnum&);	// allows for the division of a cplxnum
};

#endif
