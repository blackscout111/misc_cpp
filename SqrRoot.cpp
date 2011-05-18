// Square Root Epsilon

#include <iostream>
#include <iomanip>
using namespace std;

double f(double x, double num)
//PurPose: evaluate x^2 -num for given x and num
//PRECONDITIONS: none
//POST CONDITIONS: return x^2 - num
{
  return (x*x-num);
}

int main ()
//PURPOSE Bisection Method to find square root of a number
//PRECONDITIONS: none
//POSTCONDITIONS: displays square root.
{
  // number to find root of
  double num;
  
  // end points for search
  double left, right;

  // mid point of interval
  double midpoint;

  // error bound
  double epsilon;

  //size of interval
  double interval;

  //flag to terminate iteration
  bool done;

  //Get number to find root of
  cout << "Enter number to find square root of: ";
  cin>> num;

  // Get the error tolerance
  cout << "Enter the error tolerance: ";
  cin >> epsilon;

  // Initialize for iteration
  left = 0.0;
  right = num;

  // Initialize for the iteration loop
  interval = right - left;
  done = false;

  // Iteration to find root
  while ((interval > epsilon) && !done) {
    midpoint = (left + right)/2.0;
    if (f(midpoint, num) == 0.0) {
      done = true;
    }
    else if (f(midpoint, num)*f(left, num) < 0.0) {
      //debug code
      //cout << "mid,left,right,num" << endl
      //<< midpoint << "," << left << "," << right << "," << num << endl;

      right = midpoint;
    }
    else {
      left = midpoint;
    }
    interval = right - left;
  }

  //Display root that was found
  cout << setprecision (15);
  cout << "The square root is: " << midpoint << endl;
  cout << "Error: " << f(midpoint, num) << endl;
  cout << endl;

  return 0;
}
