/*Adam Hoffman, lecture 1003, lab 1008, exercise 5
Expected input of the program is an integer number which will be used
to convert fahrenheit to celius, and also celcius to farheinheit. 
Expected output is The initial value in F and its converted number to C. 
And then initial value in C and then that converted to F; 
*/
#include <iostream>
using namespace std; 

int main()
{
  double F;
  double C;
 
  cout << "Adam Hoffman, Lecture 1003, Lab 1008, Exercise 5" << endl;
  cout << "Please enter a temperature to convert" << endl;

  cin  >> F;

  C = 5.0/9*(F-32);
  cout << F << " Fahrenheit = " <<  C << " Celcius" << endl;

  C = F; 

  F = 9.0/5*C + 32;
  cout << C << " Celcius = " << F << " Fahrenheit" << endl;

  return 0;
}
