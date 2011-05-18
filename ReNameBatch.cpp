#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream	file_list;	// list of file names

	ofstream	out_file;	// file containing double listing
					// of file names

	char		fname[256];	// a temporary file name

	// Opens file_list and tests to see if it is open
	file_list.open("file_list.txt");
	if (!file_list.is_open())
	{
		cout << "ERROR: Could not open file_list.txt" << endl;
		cin.get();
		return -1;
	}

	// Opens outfile and tests to see if it is open
	out_file.open("ReName.bat");
	if (!out_file.is_open())
	{
		cout << "ERROR: Could not open double_file_list.txt" << endl;
		cin.get();
		return -1;
	}

	// Writes to columns of file names in out_file
	while (!file_list.eof())
	{
		file_list.getline(fname, 256);
		out_file << "ren" << "\t"
			 << "\"" << fname << "\"" << "\t"
			 << "\"" << fname << "\"" << endl;
	}

	// Adds a pause statement to the file
	out_file << "pause";

	// Closes both files
	out_file.close();
	file_list.close();

	return 0;
}
