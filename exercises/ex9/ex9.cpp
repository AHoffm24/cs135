#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
  string stars;
  int a; //factor of n(divisor)
  int b; //factor of n(divisor)
  int n; //stores values read in

  stars.append(56, '*'); //header
  cout << stars << endl;
  cout << "Adam Hoffman, Lec Sect# 1003, Lab Sect# 1008, Exercise 9" << endl;
  cout << stars << endl << endl << endl; // end of header
  //creating headers for each column 
  cout << fixed << setw(8) << right <<  " ";
  cout << setw(12) << right << "Input #";
  cout << setw(12) << right <<  "Abundant";
  cout << setw(12) << right << "Deficient";
  cout << setw(12) << right << "Perfect" << endl;
  cin >> n;
  while(cin)
    {
     
    a = 0;
    b = 0;
    if(n > 0)
      {
      for(int i = 1; i < n/2; i++) 
	{
	  if(n%i == 0 && i < n/i) //found factor
	    {
	      a = a + i; 
	      b = b + n / i;
	    }//end if
	}//end for
      cout << setw(8) << right << " "; 
      cout << setw(12) << right << n;
      if((a + b) > (n*2))
	cout << setw(12) << right << "X" <<  endl;
      else if((a + b) < (n*2))
	cout << setw(24) << right << "X" << endl; 
      else 
	cout << setw(36) << right << "X" << endl;
	   
      }//end if
    else
      {
	cout << setw(8)  << right << " ";
 	cout << setw(12) << right << n << endl;
      }
    cin >> n;
    }//end cin file loop
  
  return 0;
}
