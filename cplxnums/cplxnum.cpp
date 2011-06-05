#include "cplxnum.h"

/* Private Functions*/


/* Public Functions*/
cplxnum::cplxnum()
{
	real = 0;
	img = 0;
}

cplxnum::cplxnum(int a, int b)
{
	real = a;
	img = b;
}

cplxnum::cplxnum(int a, double b)
{ 
	real = a;
	img = b;
}

cplxnum::cplxnum(double a, int b)
{ 
	real = a;
	img = b;
}

cplxnum::cplxnum(double a, double b)
{
	real = a;
	img = b;
}

void cplxnum::disp()
{
	if (img > 0)
		cout << real << " + " << img << "i";

	else if (img < 0)
		cout << real << " - " << -img << "i";

	else
		cout << real;
}

cplxnum cplxnum::conj()
{ 
	return cplxnum(real,-img);
}

double cplxnum::mag()
{
	double m;

	m = sqrt(real*real + img*img);

	return m;
}

double cplxnum::angle()
{
	double angle;

	angle = atan(img/real);

	return angle;
}

cplxnum cplxnum::operator +(const cplxnum& z)
{ 
	return cplxnum((real + z.real),(img + z.img));
}

cplxnum cplxnum::operator -(const cplxnum& z)
{
	return cplxnum((real - z.real),(img - z.img));
}

cplxnum cplxnum::operator *(const cplxnum& z)
{
	cplxnum prod;
	
	prod.real = real*z.real - (img*z.img);
	prod.img = real*z.img + img*z.real;

	return prod;
}

cplxnum cplxnum::operator /(const cplxnum& z)
{
	cplxnum quot;
	double devisor = (z.real*z.real - z.img*z.img);

	quot.real = (real*z.real + img*z.img)/devisor;
	quot.img = (img*z.real - real*z.img)/devisor;

	return quot;
}

