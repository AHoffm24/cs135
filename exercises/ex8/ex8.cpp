//Adam Hoffman, Exercise 8, Lecture 1003, lab 1008
/*expected to read in data from a file, integers to be exact, and use the
formula given to get that number to 1. It will out put the starting number, 
the number of steps to reach 1, the largest number in the series, and 
the largest number position in which it was found*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
  string boarder;
  int k = 0; //stores number of steps
  int x = 0; //store input value
  int large = 0; //stores largest value
  int position = 0; // stores positiopn of largest value

  boarder.append(60,'=');
  cout << boarder << endl;
  cout << "Adam Hoffman    Lec Sec#1003, Lab Sec 1008, Exercise #8" <<endl;
  cout << boarder << endl;
  
  while(!cin.eof())
    {
      k = 0;
      cin >> x;
      if(x == 1)
	return 0;
      cout <<"Starting at "<< x << " it takes ";
      while(x != 1)
	{
	  k++;
	  if(x%2 == 0)
	    {
	      if(large < x)
		{
		  large = x;
		  position = k;
		}
	      x = x / 2; 
	     }
	  else
	    {
	      if(large < x)
		{
		  position  = k;
		  large = x;
		}
	      x = x * 3 + 1;
	    }
	 
	}
      cout << k << " steps to reach 1" << endl;
      cout << "The largest Number in the series is "<< large;
      cout << " at position " << position  << endl << endl;
     large = 0;
    }
     return 0;
}
