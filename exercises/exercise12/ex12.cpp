/*
reads in an array size 20 max, and greater than 0; reads from data file and
creates array of numbers size doubles. It then computer a function on each numbers
and inserts them into array2. It then prints array 1 and 2
as well as the sum of all of array1, and sum from i = 0 to n/2-1   in array 2
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
//functions
void printHeader();
bool readArray(const string, double *&, int &);
double findSum(const double *, int);
void makeNewArray(const double *, double *&, const int);
void printArray(const double *,const double *,int);
int main()
{
  bool test = false;
  double * array1; //pointer input values
  double * array2; //point array 2
  string filename;
  int size = 0; // size of array
  double sum = 0; //used to print sum and store returned value of find sum

  printHeader();  //print class information header with name, lec,lab. and ex#

  cout << endl << "Please enter name fo the input file" << endl;

  cin >> filename; // read in file to be read by stream
  test = readArray(filename, array1, size); //ensuring input was correct size with test flag
  if(test == false) //end program if data file incompatible
  {
    cout << "fail" << endl;
    return 0;
  }
  makeNewArray(array1, array2, size); //creates array #2
  printArray(array1, array2, size); //prints data

  sum = findSum(array1, size);
  cout << "Sum of all values in Array 1: ";
  cout << fixed << setprecision(5) << setw(8) << right << findSum(array1, size);
  cout << endl;
  size = size / 2;
  cout << "Sum of first " << size << " values in array 2: ";
  cout << fixed << setprecision(5) << setw(8) << right << findSum(array2, size);
  cout << endl;


delete [] array1; //deallocating pointer
delete [] array2; //deallocating pointer

return 0;

}//end of main()
/*
//print class information header with name, lec,lab. and ex# with desired
boarder around the information
*/
void printHeader()
{
  string boarder; //string to easily print boarder of = signs
  boarder.append(60, '=');
  cout << boarder << endl;
  cout << setw(15) << left << "Adam Hoffman,";
  cout << setw(15) << left << "Lec Sec# 1003,";
  cout << setw(15) << left << "Lab sec# 1008,";
  cout << setw(15) << right << "Exercise 12" << endl;
  cout << boarder << endl;
  return;
}
/*
uses Ifstream to read in data file and store information into array1
*/
bool readArray(const string file, double *& array, int & size)
{ //naming variables
  ifstream in; //ifstream variable decloration
  double item; //stores read double value;

  in.open(file.c_str()); //opens file for reading
  if(!in) //test to see if file is reading
  {
      return false; //failed to open
  }


  in >> size; //getting array size
  if(size <= 20 && size > 0)
  {
      array = new double[size]; //creating new array of size double using pointer

      for(int i = 0; i < size; i++)
      {
          in >> item; //getting item
          array[i] = item; //storing item
      } // end for
      in.close(); //closes file from reading

      return true; //SUCCESS
  } //end if

  else return false; //incase it fails the size requirement
}

/*
Fills the second array in correspondance to the document.
if even, new array gets origional arrays value * 2, if odd, gets the cube root
value, and is stored in the corresponding position.
*/
void makeNewArray(const double * ogArr, double *& newArr, const int size)
{
  newArr = new double[size]; //creating new 2nd array of type double
  for(int i = 0; i < size; i++)
  {
    if(i%2 == 0)
    {
      newArr[i] = ogArr[i] * 2.0;
    }
    else
    {
      newArr[i] = cbrt(ogArr[i]);
    }
  }
}

/*
find sum of the entire first array, and from i to size/2 of the second array
*/
double findSum(const double * array1, int size)
{
  double sum = 0; //holds sum of of all array elements
  for(int i = 0; i < size; i++)
  {
    sum += array1[i];
  }


  return sum;
}

/*
print array prints all informations according to instructions from handout
*/
void printArray(const double * array1,const double * array2, int size)
{
  cout << setw(13) << right << "input Array";
  cout << setw(13) << right << "2nd Array" << endl;
  for(int i = 0; i < size; i++)
  {
    cout << fixed << setw(13) << setprecision(5) << right << array1[i];
    cout << setw(13) << setprecision(5) << right << array2[i] << endl;
  }
  return;
}
