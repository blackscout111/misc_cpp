//Find roots of Ax2 + Bx + C = 0

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double A, B, C, x1, x2, sqrtOfDiscriminant, vertex;
//get three inputs
  cout << endl << endl
       << "Enter the value for A: ";
  cin   >> A;
  cout << "Enter the value for B: ";
  cin   >> B;
  cout << "Enter the value for C: ";
  cin   >> C;

//compute the two solutions and the vertex
  sqrtOfDiscriminant = 
    sqrt( B*B - 4*A*C );
    x1 = (-B+sqrtOfDiscriminant)/(2*A);
    x2 = (-B-sqrtOfDiscriminant)/(2*A);
    vertex = -(B/(2*A));

//display the first root
    cout << endl
	 << "First solution: " 
	 << x1 << endl;
//display the second root if different
  if (x1 != x2) {
    cout << "Second solution: " 
	 << x2 << endl;
  }

//displacy the vertex of the equation
  cout << "Vertex: " << vertex << endl << endl;

	return 0;
}

