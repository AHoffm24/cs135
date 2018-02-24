/*
Adam Hoffman, Exercise 13, lec 1003, lab 1008
This program reads in a file and store the information for a basketball
team by name, jersey number, and avg points per game and is sorted
using bubble sort to output them using ofstream to a seperate file
from highest to lower in average points per game.
read output file with cat(more) hoffma4.exercise13
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
struct ballplayers //used to track team by name uniform number and avgPPG
{
  string name; // first name
  int uni; //uniform number
  double APPG; //average points per game
};
void printHeader(ofstream&);
int readData(ballplayers[], string);
void printData(ofstream&,ballplayers[], int);
void bubbleSort(ballplayers[], int);
int main()
{
  int count = 0; //hold total size of team
  string inputName;
  ofstream out;
  ifstream in;

  ballplayers team[25];
  out.open("hoffma4.exercise13");
  cout << "please enter name of inputfile" << endl;
  cin >> inputName;

  printHeader(out);

  count = readData(team, inputName);
  bubbleSort(team, count);
  printData(out, team, count);


  out.close();
  return 0;
}
/*
prints my person class information for grading as well as the boarder
to make it visually pleasing and easy to read
*/
void printHeader(ofstream& out)
{
  string boarder; //string to easily print boarder of = signs
  boarder.append(60, '=');
  out << boarder << endl;
  out << setw(15) << left << "Adam Hoffman,";
  out << setw(15) << left << "Lec Sec# 1003,";
  out << setw(15) << left << "Lab sec# 1008,";
  out << setw(15) << right << "Exercise 13" << endl;
  out << boarder << endl << endl;
  return;
}
/*
uses Ifstream to read in data file and store information into array1
returns count so it can be used at a later time to print and sort data
*/
int readData(ballplayers team[], string file)
{
  ifstream in; //ifstream variable decloration
  string NAME;
  int     NUM;
  double  AVG;
  int count = 0;
  in.open(file.c_str()); //opens file for reading
  if(!in) //test to see if file is reading
    {
      return false; //failed to open
    }
  in >> NAME;
  while(in)
    {
      in >> NUM >> AVG;
      team[count].name = NAME;
      team[count].uni = NUM;
      team[count].APPG = AVG;
      count++;
      in >> NAME;

    }
  in.close();
  return count;
} // end of read data

/*
This bubble sort will sort the list of players on the team
by highest average points per game to lowest.
*/
void bubbleSort(ballplayers team[],int count)
{
  ballplayers temp; //used to store type ballplayers until swapped
  for(int i = 0; i < count-1; i++)
    {
      for(int j = 0; j < count-(i+1); j++)
	{
	  if(team[j].APPG < team[j+1].APPG)
	    {
	      temp = team[j];
	      team[j] = team[j+1];
	      team[j+1] = temp;
	    }
	}
    }
} //end of bubble sort

/*
print data will output the information for the basketball team in
a formated manor asked for by the professor.
*/
void printData(ofstream& out, ballplayers team[], int count)
{
  out << left << setw(15) << "NAME";
  out << right << setw(10) << "Uniform#";
  out << right << setw(10) << "AVEPPG" << endl;
  for(int i = 0; i < count; i++)
    {
      out << left << setw(15) << team[i].name;
      out << right<< setw(10) <<  team[i].uni;
      out << right << fixed << setprecision(2) << setw(10) << team[i].APPG;
      out << endl;
    }
}
