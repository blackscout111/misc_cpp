#ifndef baseCnvrtdNum_h
#define baseCnvrtdNum_h

#include <iostream>
#include <string>

using namespace std;

// Class used for converting from one base to another
class baseCnvrtdNum
{
public:
	baseCnvrtdNum(int num = 0,  int newbase = 10, int oldbase = 10);
	~baseCnvrtdNum();

	int getsize() const;		// Returns the size
	int getdecval() const;		// Returns the decVal
	int getbase() const;		// Returns the base

	void print() const;		// Prints all of the private
							// variables

	// Overloads the [] operator
	const int& operator [](int ) const;

	// Overloads the = operator
	const baseCnvrtdNum& operator =(const baseCnvrtdNum&);
	

	private:
	int 	decVal;		// Value in base ten
	int 	size;		// Number of digits
	int		base;		// New base
	
	int	*num_array;	// The array of digits

	// Returns the value of 'base' raised to the 'pwr' power
	int pow(int num_base, int pwr) const;

	// Returns the greatest power of 'base' that 'num' is divisible by
	int greatestPwr(int num, int num_base) const;
};

#endif
