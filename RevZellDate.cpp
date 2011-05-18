// Compute the day of the week
// for a given date using 
// Reverend Zeller's Algorithm

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int dayOfWeek(int month, int day, 
	      int year, int century)
{
  int	EffectOfMonth;    // month days 
  int	LeapYears;          // leap year days
  int	EffectOfCentury;  // century days
  int	TotalDays;          // total day count
  int	WeekDay;           // answer
  
  //Step 1: Adjust year so 0 becomes 100
  if (year == 0) {
    year = 100; century = century - 1;
  }
  
  //Step 2: Adjust month so March == 1
  if ((month < 3) && (year == 1)) {
    year = 100; century = century - 1;
  }
  else if (month < 3) {
    year = year - 1;
  }
  
  //Step 3: Count the days
  month = (month + 9) % 12 + 1;
  EffectOfMonth = (13*month - 1)/5;
  LeapYears = year / 4;
	EffectOfCentury = century / 4;
	TotalDays = EffectOfMonth + 
	  LeapYears + 
	  EffectOfCentury + 
	  day + 
	  year - 
	  2*century;
	
	//Step 4: Compute and return 
	//day of week
	WeekDay = TotalDays % 7;
	return WeekDay;
}

string dayName( int Day )
{
  string Name;	 // name of day
  
  // Determine name of day
  string dayName( int Day );
  {
    string Name;	 // name of day
    
  // Determine name of day
  if (Day == 0) {
	  Name = "Sunday";
	}
	else if (Day == 1) {
	  Name = "Monday";
	}
	
	else if (Day == 2) {
	  Name = "Tuesday";
	}
	
	else if (Day == 3) {
	  Name = "Wednesday";
	}
	
	else if (Day == 4) {
	  Name = "Wednesday";
	}
	
	else if (Day == 5) {
	  Name = "Friday";
	}
	else {
	  Name = "Saturday";
	}
	
	// return name of day
	return Name;
  }
}

	int main ()
{
  int month;	// month of given date
	int	day;	// day of month
	int	year;	// last two digits of year
	int	century; // first two digits of year
	int	dayNumber; // day of week
	string dayString;   // name of day
	
	// Get date from user
	cout << "Enter month (January = 1):";
	cin  >> month;
	cout << "Enter day: ";
	cin  >> day;
	cout << "Enter year (last 2 digits): ";
	cin  >> year;
	cout << "Enter first 2 digits of year: ";
	cin  >> century;
	
	// Compute day of the week
	dayNumber = dayOfWeek(month, 		day, year, century);
	
	// Convert day of week to its name
	dayString = dayName(dayNumber);
	
	// Display name of day of week
	cout << endl;
	cout.fill('0');
	cout << month << "/" << day 
	     << "/" << century 
	       << setw(2) << year 
	     << " falls on a " << dayString    
	     << "." << endl << endl;
	
	return 0;
}
