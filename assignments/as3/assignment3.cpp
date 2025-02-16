/*
Adam Hoffman, Lec 1003, lab 1008, Assignment 3
The purpose of this program is to read in various clock times, determine 
the start times, the end time, and an interval length. 
The times will be either in normal 12 hours format i.e. AM, PM
or the times will be represented as military(24 hour) time
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
void printHeader(); 
void printData(int, int, int, char, char);
void readLine(int);

int main()
{
  int timeInt; //holds 12 or 24 hour marker 

  printHeader(); //Prints my header

  cin >> timeInt; //being reading of file
  while(cin)
    {
      readLine(timeInt);
      cin >> timeInt;
    }

  return 0;
} //end of main
/*
readLine function Reads in the information from the DATA file and calls 
the print data function to output the data. It also find the time interval
between the 2 numbers read in and does the math on them to call
the print data fuction for time interval. 
 */
void readLine(int interval)
{
  int Shour, Sminute; //holds hour and minutes of start time
  int Ehour, Eminute; //holds hour and minute of end time
  int Ihour, Iminute; //holds interval total time

  char SAMPM, EAMPM; //holds value of AM or pm for start and end time
  char Colon; //holds the colon during the read function
  char flag; //used for print function to determin which to print
  
  
    
  cin >> Shour;
  cin >> Colon;
  cin >> Sminute;
  if(interval == 12)
  {
     cin >> SAMPM;
     SAMPM = tolower(SAMPM);
  }
  flag = 's'; //used to print start int print data function
  printData(interval, Shour, Sminute, SAMPM, flag);
  

  cin >> Ehour;
  cin >> Colon;
  cin >> Eminute;
  if(interval == 12)
  {
      cin >> EAMPM;
      EAMPM = tolower(EAMPM);
  }   
  flag = 'e';
  printData(interval, Ehour, Eminute, EAMPM, flag);
    
  flag = 'i';
  if(interval == 24)
  {
      if(Shour > Ehour) //indicates end time was on a sperate day.
      {
	Ihour = Ehour + (24 - Shour);
      }
      else
      {
	Ihour = Ehour - Shour;
      }
      if(Sminute > Eminute) //for when the start min are greater than end
      {
	Ihour--;
	Iminute = 60 -(Sminute - Eminute);
      }
      else
      {
	Iminute = Eminute - Sminute;
      }
      
  } //end if
  else // interval length 12
  {
      if(EAMPM == SAMPM)
      {
	Ihour = Ehour - Shour;
      }
      else
      {
	Ihour = Ehour +(12 - Shour);
      }
      if(Sminute > Eminute) 
      {
	Ihour--;
	Iminute = 60 - (Sminute - Eminute);
      }
      else
      {
      Iminute = Eminute - Sminute;
      }
  } // end else
  printData(interval, Ihour, Iminute, SAMPM, flag);
}

/*
Header consist of personal information involving the class. 
This function prints it in a formated manner that has boarders of '=====' 
for looks. 
 */
void printHeader() 
{
  string boarder; // used to create boarder of  = signs
  boarder.append(60, '=');

  cout << boarder << endl;
  cout << setw(15) << left << "Adam Hoffman";
  cout << setw(15) << left << "Lec Sec# 1003,";
  cout << setw(15) << left << "Lab sec# 1008,";
  cout << setw(15) << right << "Assignment #3" << endl;
  cout << boarder << endl;
  return;
}

/*
print data functions prints the formatted output of the passed information. 
It uses a char flag to determine if the information being passed is
a Start time, End time, or Interval length.
 */
void printData(int interval,int hour,int minute, char AMPM, char flag)
{
  if(flag == 's')
    cout << setw(15) << "Start time: ";
  else if(flag == 'e')
    cout << setw(15) << "End time: ";
  else if (flag == 'i')
    cout << setw(20) << "Interval length: ";

  if(hour < 10){ cout << "0"; } //prints the leading 0 if needed
  cout << hour << ":";

  if(minute < 10) {cout << "0"; } //prints the leading 0 if needed
  cout << minute;

  if(interval == 12 && flag != 'i')
    {
      if(AMPM == 'a')
	cout << "am";
      else if(AMPM == 'p')
	cout << "pm";
    }
  else 
    cout << setw(2) << " "; //used to offset am/pm for print out 
  if(flag == 'i')
    cout << endl;

}
