#include "baseCnvrtdNum.h"

baseCnvrtdNum::baseCnvrtdNum(int num, int newbase, int oldbase)
{
	int 	pwr,
		dif,
		qt;

	decVal = num;

	// Bases less than 2 are not possible
	if (newbase >= 2)
	{
		base = newbase;
	}
	else
	{
		cout	<< endl
			<< "baseCnvrtdNum.cpp: In member function "
			<< "'baseCnvrtdNum::baseCnvrtdNum(int num, int newbase):"
			<< endl
			<< "baseCnvrtdNum.cpp: error: "
			<< "'newbase' must be >= 2!"
			<< endl
			<< "Press ENTER to terminate the program..."
			<< endl;
		
		cin.get();
		
		// Exits program returning '-1'
		exit(-1);
	}

	pwr = greatestPwr(num, base);
	// debug code
	// cout << "pwr= " << pwr << endl;
	
	size = pwr + 1;

	num_array = new int [size];

	// initializes each digit to zero
	for (int i = 0; i < size; i++)
	{
		num_array[i] = 0;
	}

	// fills 'num_array' with the correct values
	while ( pwr > 0)
	{
		qt = num/pow(base, pwr);
		// debug code
		// cout << "qt= " << qt << endl;

		num_array[pwr] = qt;

		num = num - qt*pow(base, pwr);
		// debug code
		// cout << "num= " << num << endl;
		
		pwr = greatestPwr(num, base);
		// debug code
		// cout << "pwr= " << pwr << endl;
	}

	if (num >= 0)
	{
		num_array[0] = num;
	}
	else
	{
		num_array[0] = 0;
	}
}

baseCnvrtdNum::~baseCnvrtdNum() 
{
	delete[] num_array;
	num_array = NULL;
}

int baseCnvrtdNum::getsize() const
{
	return size;
}

int baseCnvrtdNum::getdecval() const
{
	return decVal;
}

int baseCnvrtdNum::getbase() const
{
	return base;
}

void baseCnvrtdNum::print() const
{
	cout 	<< "size = " << size << endl
		<< "decVal = " << decVal << endl
		<< "base = " << base << endl
		<< "num_array (base location) = " << num_array << endl
		<< "num_array (entries): ";

	for (int i =  0; i < size; i++)
	{
		cout 	<< " "
			<< num_array[i];
	}
	
}

const int& baseCnvrtdNum::operator [](int index) const
{
	try
	{
		if (index < 0 || index >= size)
			throw index; 

		return num_array[index];
	}
	catch (int index)
	{
		cout	<< endl
			<< "baseCnvrtdNum.cpp: In member function "
			<< "'const int& baseCnvrtdNum::operator "
			<< "[](int index const':"
			<< endl
			<< "baseCnvrtdNum.cpp: error: "
			<< "'index' of "
			<< index
			<< " is out of bounds! Printing member data."
			<< endl;

		print();
		cout << endl << endl;

		cout << "Press ENTER to terminate program...";

		cin.get();

		// Exits program returning the value '-1'
		exit(-1);
	}	
}

const baseCnvrtdNum& baseCnvrtdNum::operator =(const baseCnvrtdNum& rightBCN)
{
	if (this != &rightBCN)
	{
		decVal = rightBCN.getdecval();
		size = rightBCN.getsize();
		base = rightBCN.getbase();

		delete [] num_array;

		num_array = new int [size];

		for (int i = 0; i < size; i++)
		{
			num_array[i] = rightBCN[i];
		}
	}

		return *this;
}

int baseCnvrtdNum::pow(int num_base, int pwr) const
{
	int val = 1;

	for (int i = 0; i < pwr; i++)
	{
		val = val*num_base;
	}

	return val;
}

int baseCnvrtdNum::greatestPwr(int num, int num_base) const
{
	int pwr = 0;

	while (num/pow(num_base, pwr) >= num_base)
	{
		pwr++;
	}

	return pwr;
}





