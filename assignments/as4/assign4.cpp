/*
Adam Hoffman, lecture 1003, lab 1008
the purpose of this program is to read in a data file of names,
sort the list of names in alphabetical order,
determine the longest name(s) and its length and print each name matching size
determine the shortest name(s) and it length and print each name matching size
determine the average number of characters per name
print out the information in a formated order
The file should be printed to an ofstream file, in which the user enters the
name of. The information printed can be found in said output file.
*/
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;
void getFileNames(string&, string&); //name 1, name 2
void printHeader(ofstream&); //ofstream variable being passed to print
void bubbleSort(string[], int); //Names[], count
void print(string[], int, string, ofstream&, int, int, double); //names[],count,
// input file name, outstream, smallest string size,largest string size
bool compareString(string, string); // string 1, string 2 for comparison



int main()
{
  int large = 0; //small and large hold smallest and largest length name
  int small = 1000000; //setting large number to guarentee swap with smaller;
  int count = 0; //total count of names read
  double average = 0; //average number of characters per name;
  string input, output; // hold string input and output file names;
  string Names[30]; //array of names to be stored;
  string name; // used to store the string, First letter upper case, rest lower case
  ifstream in; //input file read function
  ofstream out;//outputfile write function

  getFileNames(input, output);
  in.open(input.c_str()); //open read file
  out.open(output); //open write file
  in >> name;
  while(in) //reads until end of file;
    {
      for(int i = 0; i < name.length(); i++)
	{
	  if(i == 0)
	    {
	      name[0] = toupper(name[0]); //first letter upper case
	    }
	  else
	    {
	      name[i] = tolower(name[i]); //everything but first letter lower case
	    }
	}
      average += name.length(); //getting total number of char from each name
      if(name.length() > large)
	{
	  large = name.length(); //finding largest string size
	}
      if(name.length() < small)
	{
	  small = name.length(); //finding smallest string size
	}
      Names[count] = name; //storing string into array of strings
      count++; //storing total number of strings
      in >> name; //get next
    } // end of while

  average = average/count; //finds average # of chars by takng total char / total count

  bubbleSort(Names, count); //sorts list
  printHeader(out);  //printing header personal information
  print(Names, count, input, out, small, large, average);//prints list to out file
  in.close(); //close file read
  out.close(); //close file write
  return 0;
} // end of main
void printHeader(ofstream& out)
{
  string boarder; //string to easily print boarder of = signs
  boarder.append(60, '=');
  out << boarder << endl;
  out << setw(15) << left << "Adam Hoffman,";
  out << setw(15) << left << "Lec Sec# 1003,";
  out << setw(15) << left << "Lab sec# 1008,";
  out << setw(15) << right << "Assignment 4" << endl;
  out << boarder << endl;
  return;
} // end print header
/*
Promts users to input, input file name and output file name
gets input and output file names from the users and passes them back to main
using pass by reference
*/
void getFileNames(string& input, string& output)
{
  cout << "Input file name: " << endl;
  cout << "Enter input file name" << endl;
  cin >> input;
  cout << "Enter output file name" << endl;
  cin >> output;

} // end getFileNames

/*
Prints the graph in way asked for by the program instructions
*/
void print(string Names[], int count, string in, ofstream& out, int small,
	   int large, double average)
{

  out << "Input file name: " << in << endl << endl;


  out << "# of unique name: " << count << endl;
  out << "Average length of a name: ";
  out << fixed << setprecision(3) << average << endl << endl;


  out << "length of longest name(s): " << large << endl;
  out << "longest Names(s) is " << endl;
  for(int i = 0; i < count; i++)
    {
      if(Names[i].length() == large)
	{
	  out << Names[i] << endl;
	}
    }
  out << endl;


  out << "length of shortest name(s): " << small << endl;
  out << "Shortest name(s) " << endl;
  for(int i = 0; i < count; i++)
    {
      if(Names[i].length() == small)
	{
	  out << Names[i] << endl;
	}
    }
  out << endl;



  out << "Length of Alphabetized Name List) is "  << endl;
  for(int i = 0; i < count; i++)
    {
      out << Names[i] << endl;
    }
  return;
} //end of print
/*
sorts list of string into alphabetical order using bubblesort algorithm;
bubble sort algorithm checks each and every position with an element of its array.
depending on ascending and decending order, youd swap if the element was not in
its right position.
*/
void bubbleSort(string Names[], int count)
{

  string temp; //stores string to be swapped
  for(int i =0; i < count-1; i++)
    {
      for(int j =0; j < count-(i+1);j++)
	{
	  if(compareString(Names[j],Names[j+1])) //if true, swap
	    {
	      temp = Names[j];
	      Names[j] = Names[j+1];
	      Names[j+1]= temp;
	    }
	}
    }
} //end of bubble sort
/*
function returns true if string A is closer to the top of alphabetical order
than string B. If string A = Bat, and string B = apple, apple comes before
bat, thus string A and string B should be swapped
*/
bool compareString(string A, string B)
{

  for(int i = 0; i < A.length(); i ++)
    {
      if(A[i] > B[i])
	{
	  return true;
	}
      if(A[i] < B[i])
	{
	  return false;
	}
    }
  return false; //incase words are the same;

} //end compare string
