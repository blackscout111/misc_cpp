#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	bool	repeat = true;

	while (repeat == true)
	{
		unsigned long long			n,j,i;
		char					menu;
		bool					ask = true;
		vector <unsigned long long>		lowerFactors,
		       upperFactors;
		ofstream				outFile;
		string					outFile_name;

		cout	<< "---------------------------------------------------"
			<< endl
			<< "Enter a number less than 2^64: ";

		cin >> n;

		cout << endl;

		for (i = 1; i <= (n/i); i++)
		{
			j = n/i;

			if (n%i == 0)
			{
				lowerFactors.push_back(i);
				upperFactors.push_back(j);
			}
		}

		cout << "\a" << endl;

		if (lowerFactors.size() == 1)
		{
			cout << "PRIME" << endl << endl;
		}

		else
		{ cout	<< "Factored " << (lowerFactors.size() - 1) << " times" << endl << endl;

			while (ask == true)
			{
				cout	<< "Type:"
					<< endl
					<< "(d) to display factors"
					<< endl
					<< "(e) to export factors to a file"
					<< endl
					<< "... or else type (n): ";

				cin >> menu;

				cout << endl;

				if (menu == 'd')
				{
					for (int i = 0; i < lowerFactors.size(); i++)
					{
						cout	<< setw(10)
							<< lowerFactors[i]
							<< setw(25)
							<< upperFactors[i]
							<< endl << endl;
					}
				}

				else if (menu == 'e')
				{
					cout << "Enter File Name: ";
					cin >> outFile_name;
					cout << endl;

					outFile.open(outFile_name.c_str());
					if (!outFile.is_open())
					{
						cout 	<< "ERROR: COULD NOT OPEN "
							<< outFile_name << endl
							<< "Press any ENTER to continue...";

						cin.get();

						return -1;
					}

					else
					{
						outFile	<< "The number " << n << " has factors:"
							<< "\r\n\r\n";

						for (int i = 0; i < lowerFactors.size(); i++)
						{
							outFile << setw(10)
								<< lowerFactors[i]
								<< setw(25)
								<< upperFactors[i]
								<< "\r\n";
						}

						outFile.close();
					}

				}

				else if (menu == 'n')
				{
					ask = false;
				}
			}
		}

		ask = true;
		while (ask == true)
		{
			cout << "Type (q) to quit or (r) to repeat: ";

			cin >> menu;

			cout << endl;

			if (menu == 'q')
			{
				repeat = false;	
				ask = false;

				cout	<< "--------------------------------"
					<< endl;
			}

			else if (menu == 'r')
			{
				ask = false;
			}
		}
	}

	return 0;
}
