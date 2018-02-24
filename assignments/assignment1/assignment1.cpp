//Adam Hoffman, Lecture section 1002, assignment 1

#include <iostream>
using namespace std;

int main()
{
  int a,b,c;       //declaring variables a, b, and c
  int d,e,f;       //declaring variables d, e, and f 
  
  cout<<"Enter constants (a, b, c) for equation 1"<< endl; //outputs statment
  cin>> a >> b >> c;  //allows user to input value of a, b, and c integers
  
  cout<<"Enter constants (d, e, f) for equation 2"<<endl; //outputs statement
  cin>> d >> e >> f;  //allows user to input value of d, e, and f integers
  
  double x;
  x =static_cast<double> (c*e-f*b)/(a*e-d*b); 
  //give the equaton of x more precision because all variables are int
 
  double y;
  y = double  (a*f-d*c)/(a*e-d*b); 
  

  cout <<"Adam Hoffman LecSec#1002 Assignment #1"<< endl; //outputs statement
  cout << a << "x + " << b << "y = " << c << endl; //outputs ax + by = c
  //a, b, and c will output value given by user instead of character
  cout << d << "x + " << e << "y = " << f << endl; //outputs dx + ey = f
  //d, e, and f will output values given by user instead of character
  cout << "x = " << x << endl; //outputs x = (value of x)
  cout << "y = " << y << endl; //outputs y = (value of y)
 
  return 0;
}
