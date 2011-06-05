#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
	//variables
	vector <double> datasample_x;	//sample data for x
	vector <double> datasample_y;	//sample data for y

	ofstream outFile;		//file to write data and statistics to
	ifstream inFile;		//file to read data from

	string	tempdata;	// Temporaty data to be converted into a double

	double	data_x,		// a temporary x data point
			data_y,		// a temporary y data point
			N,			// size of X data sample
			M,			// size of Y sample
			x_sum=0,	// sum of the x values
			y_sum=0,	// sum of the y values
			x_mean,		// mean of x values
			y_mean,		// mean of y values 
			xy_sum=0,	// sum of x*y
			x2_sum=0,	// sum of x2
			a,			// constant in y=ax+b
			b,			// coefficient in y=ax+b
			variance,	// variance
			var_sum,	// sum of (y-ax-b)^2
			sigma,		// standard deviation
			sigma_a,	// standard error of a
			sigma_b;	// standard error of b

	int	prec = 10;	// precision of stats

	char	writeToFile,
		readFromFile;

	string	inFileName,
		outFileName;


	// Asks the user if he wants to write the stats to a file
	cout	<< "Write Data & Statistics To A File? (Y/N): ";

	// Gets the value of 'writeToFile'
	// If 'writeToFile' = Y or y then the user is prompted for a file name
	// and 'outFile' is opened
	cin >> writeToFile;
	if (writeToFile == 'y' || writeToFile == 'Y')
	{
		cout	<< "File Name?: ";
		cin	>> outFileName;

		// Opens 'outFile' and then checks to see if it is open
		// if it isn't open an error message is displayed and the
		// program is terminated
		outFile.open(outFileName.c_str());
		if (!outFile.is_open())
		{
			cout << "ERROR: Could not open " << outFileName << endl
			     << "Press ENTER to terminate program..." << endl;
			cin.get();
			cin.get();
			return -1;
		}
		
	}

	// Asks the user if the data can be read from a file, and then prompts
	// the user for the file name.  If the data cannot be read from a file,
	// the user will then be prompted for the data.
	cout << "Read Data From File? (Y/N): ";
	cin >> readFromFile;
	if (readFromFile == 'y' || readFromFile == 'Y')
	{
		cout << "Data File?: ";
		cin >> inFileName;
		inFile.open(inFileName.c_str());
		if (!inFile.is_open())
		{
			cout << "ERROR: Could not open " << inFileName << endl
			     << "Press ENTER to terminate program..." << endl;
			cin.get();
			cin.get();
			return -1;
		}

		cout 	<< endl
				<< setw (2*prec)
				<< "X DATA"
				<< setw (2*prec)
				<< "Y DATA"
				<< endl
				<< endl;

		while (!inFile.eof())
		{
			inFile >> data_x
			       >> data_y;
			datasample_x.push_back(data_x);
			datasample_y.push_back(data_y);

			cout 	<< setw(2*prec)
					<< setprecision (prec)
					<< data_x
					<< setw(2*prec)
					<< setprecision (prec)
					<< data_y
					<< endl;
		}

		inFile.close();
	}

	else
	{	
		cout << endl
		     << "Enter X data (enter \"done\" when finished):" <<endl;
		cin >> tempdata;
		while(tempdata != "done")
		{
			data_x = atof(tempdata.c_str());
			datasample_x.push_back(data_x);
			cin >> tempdata;
		}
	
		cout << endl
		     << "Enter Y data (Enter \"done\" when finished):" <<endl;

		cin >> tempdata;
		while(tempdata != "done")
		{
			data_y = atof(tempdata.c_str());
			datasample_y.push_back(data_y);
			cin >> tempdata;
		}
	}

	cout << endl;

	// records sample size as N
	N = datasample_x.size();

	// records size of Y and compares it to size of X
	M = datasample_y.size();

	if (N!=M)
	{
		cout << "ERROR: data samples must be same size" << endl
		     << endl
		     << "Press ENTER to terminate program...";
			cin.get();
			cin.get();

		return 0;
	}

	// calculates x_sum
	for(int i = 0; i < N; i++)
	{
		x_sum = x_sum + datasample_x[i];
	}

	// calculates y_sum
	for(int i = 0; i < N; i++)
	{
		y_sum = y_sum + datasample_y[i];
	}

	// calculates x_mean
	x_mean = x_sum/N;

	// calculates y_mean
	y_mean = y_sum/N;

	// calculates xy_sum
	for(int i = 0; i < N; i++)
	{
		xy_sum = xy_sum + (datasample_x[i]*datasample_y[i]);
	}

	// calculates x2_sum
	for(int i = 0; i<N; i++)
	{
		x2_sum = x2_sum + (datasample_x[i]*datasample_x[i]);
	}

	// calculates values for Y=ax+b

	a = (N*(xy_sum) - (x_sum*y_sum))/(N*(x2_sum) - (x_sum*x_sum));

	b = ((x2_sum*y_sum)-(x_sum*xy_sum))/(N*(x2_sum)-(x_sum*x_sum));

	// calculates the sum of (y-ax-b)*(y-ax-b)
	for(int i = 0; i < N; i++)
	{
		var_sum = var_sum + (datasample_y[i] - a*datasample_x[i] - b)*
			  (datasample_y[i] - a*datasample_x[i] - b);
	}

	// calculates variance
	variance = var_sum/(N - 2);

	// calculates standard deviation
	sigma = sqrt(variance);

	// calculates standard error of a
	sigma_a = (variance*N)/(N*(x2_sum) - (x_sum)*(x_sum));

	// calculates standard error of b
	sigma_b = (variance*x2_sum)/(N*(x2_sum) - (x_sum*x_sum));


	// Displays Regression Statistics

	cout	<< "----------------------------\r\n"
			<< "LINEAR REGRESSION STATISTICS\r\n"
			<< "----------------------------\r\n"
			<< endl
			<< "For Y=ax+b:" <<endl
			<< setw (25)
			<< setprecision (prec)
			<< "a = " << a << "\r\n"
			<< setw (25)
			<< setprecision (prec)
			<< "b = " << b << "\r\n"
			<< setw (25)
			<< setprecision (prec)
			<< "Variance: " << variance << "\r\n"
			<< setw (25)
			<< setprecision (prec)
			<< "Standard Deviation: " << sigma << "\r\n"
			<< setw (25)
			<< setprecision (prec)
			<< "Standard Error In 'a': " << sigma_a << "\r\n"
			<< setw (25)
			<< setprecision (prec)
			<< "Standard Error In 'b': " << sigma_b << "\r\n"
			<< "\r\n";


		// Writes 'dataSample' and Descriptive Statistics to 'outFile'
		// and then closes 'outFile'
	if (outFile.is_open())
	{
		cout	<< "Data and regression statistics written to: "
				<< outFileName
				<< endl;

		outFile	<< "----------------------------\r\n"
				<< "LINEAR REGRESSION STATISTICS\r\n"
				<< "----------------------------\r\n"
				<< endl
				<< "For Y=ax+b:" <<endl
				<< setw (25)
				<< setprecision (prec)
				<< "a = " << a << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "b = " << b << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Variance: " << variance << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Standard Deviation: " << sigma << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Standard Error In 'a': " << sigma_a << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Standard Error In 'b': " << sigma_b << "\r\n"
				<< "\r\n"
				<< "\r\n"
				<< "------------\r\n"
				<< "DATA SAMPLE	\r\n"
				<< "------------\r\n"
				<< "\r\n"
				<< setw (2*prec)
				<< "X DATA"
				<< setw (2*prec)
				<< "Y DATA"
				<< "\r\n"
				<< "\r\n";


		for (int i = 0; i < N; i++)
		{
			outFile << setw(2*prec)
				<< setprecision (prec) 
				<< datasample_x[i]
				<< setw(2*prec)
				<< setprecision (prec)
				<< datasample_y[i]
				<< "\r\n";
		}

		outFile.close();
	}

	// Pauses Console Before It Closes
	cout << endl 
	     <<"Press ENTER to continue" << endl;
	cin.get();
	cin.get();

	return 0;
}

