#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
	// Variables
	vector <double> dataSample;	// Sample data for stats

	ofstream outFile;		// File to write data and stats to	
	ifstream inFile;		// File to read data from.

	string	tempdata;	// Temporary data to be converted into a double

	double 	data,		// A temporary data point

		N,		// The data size

		sum = 0,	// Sum of the data

		sumVar = 0,	// A sum variable for variance and standard
					// deviation

		mean,		// Sample mean of the data

		var,		// Sample variance of the data

		s,		// Sample standard deviation of the data

		err;		// Standard Error Of Mean

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
			return -1;
		}

		while (!inFile.eof())
		{
			inFile >> data;
			dataSample.push_back(data);
			cout << data << endl;
		}

		inFile.close();
	}

	else
	{	
		// Prompts the user to enter in the 'data' and adds it 
		// into 'dataSample'
		cout << "Enter Data (type \"done\" when done):" << endl;
		cin >> tempdata;
		while (tempdata != "done")
		{
			data = atof(tempdata.c_str());
			dataSample.push_back(data);
			cin >> tempdata;
		}
	}

	cout << endl << endl;

	// Gets the data sample size as 'N'
	N = dataSample.size();

	// Calculates 'sum'
	for (int i = 0; i < N; i++)
	{
		sum = sum + dataSample[i];
	}

	// Calculates 'mean'
	mean = sum/N;

	// Calculates 'sumVar'
	for (int i = 0; i < N; i++)
	{
		sumVar = sumVar + (dataSample[i] - mean)*(dataSample[i] - mean);
	}

	// Calculates 'var'
	var = sumVar/(N - 1);

	// Calculates 's'
	s = sqrt(var);

	// Calculates 'err'
	err = s/sqrt(N);
	
	// Displays Statistics
	cout	<< "----------------------------" << endl
			<< "DESCRIPTIVE STATISTICS	" << endl
			<< "----------------------------" << endl
			<< endl
			<< setw (25)
			<< setprecision (prec)
			<< "Sample Size: " << N << endl
			<< setw (25)
			<< setprecision (prec)
			<< "Sum: " << sum << endl
			<< setw (25)
			<< setprecision (prec)
			<< "Mean: " << mean << endl
			<< setw (25)
			<< setprecision (prec)
			<< "Variance: " << var << endl
			<< setw (25)
			<< setprecision (prec)
			<< "Standard Deviation: " << s << endl
			<< setw (25)
			<< setprecision (prec)
			<< "Standard Error In Mean: " << err << endl
			<< endl;

	// Writes 'dataSample' and Descriptive Statistics to 'outFile' and then 
	// closes 'outFile'
	if (outFile.is_open())
	{
		outFile 	<< "----------------------------\r\n"
				<< "DESCRIPTIVE STATISTICS	\r\n"
				<< "----------------------------\r\n"
				<< endl
				<< setw (25)
				<< setprecision (prec)
				<< "Sample Size: " << N << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Sum: " << sum << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Mean: " << mean << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Variance: " << var << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Standard Deviation: " << s << "\r\n"
				<< setw (25)
				<< setprecision (prec)
				<< "Standard Error In Mean: " << err << "\r\n"
				<< "\r\n"
				<< "\r\n"
				<< "------------\r\n"
				<< "DATA SAMPLE	\r\n"
				<< "------------\r\n";

		for (int i = 0; i < N; i++)
		{
			outFile << setprecision (prec) 
					<< dataSample[i] << "\r\n";
		}

		outFile.close();
	}

	// Pauses Console Before It Closes
	cout << "Press ENTER to terminate program..." << endl;
	cin.get();
	cin.get();

	return 0;
}
