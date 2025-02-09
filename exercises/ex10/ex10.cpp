//The Gregory-Leibniz and Euler infinite series for estimating pi
//will be implemented as value-returning functions. The program will
//read several integers from a file that represent the number of 
//terms to be used. For each data set, the program will display the
//number of terms and both estimated values with labels.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int L = 20;  //field width of labels
const int N = 17;  //field width of numbers
double gregory_leibniz(int);
double euler(int);

int main()
{
  int terms;            //number of terms to use in estimates
  double leibniz_est;   //estimated value of pi using gregory-leibniz
  double euler_est;     //estimated value of pi using euler
  cout << fixed << setprecision(15);
  cin >> terms;
  while (cin)
    {
      cout << "Using " << terms << " term(s)" << endl;
      leibniz_est = gregory_leibniz(terms);
      euler_est = euler(terms);
      cout << setw(L) << left << "Gregory-Leibniz: ";
      cout << right << setw(N) << leibniz_est << endl;
      cout << setw(L) << left << "Euler: " << right
	   << setw(N) << euler_est << endl;
      cin >> terms;
	}
  return 0;
}

double gregory_leibniz(int numofterms)
//Given numofterms terms, compute and return an estimate
//of pi using the Gregory-Leibniz series.
{
  //complete the body of the function
  //implement the gregory-leibniz series to estimate pi
  double bottom = 3;
  double temp = 1; //skipping first sum because first is always 1;
  for(int i = 1; i < numofterms; i++)
    {
      if(i%2 == 0){
	temp += 1/bottom;
	bottom += 2;
      }
      else{
	temp -= 1/bottom;
        bottom += 2;
      }
    }
  return temp * 4;
    
}

double euler(int n)
//Given n terms, compute and return an estimate of pi
//using the Euler series.
{
  double temp = 1; //skipping first sum because its always 1
  double bottom = 2;
  for(int i = 1; i < n; i++)
    {
      temp += 1 / pow(bottom, 2);
      bottom++;
    }
  temp = temp * 6;
  temp = sqrt(temp);
  return temp;
  //complete the body of the function
  //implement the euler series to estimate pi
}

