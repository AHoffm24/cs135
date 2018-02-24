//basic project that tells you the time intervale between
//a start time and an end time
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;
void printHeader();
void printData(int, int, int, char, char);
void readLine(int);

int main()
{
  string ST; //start time
//  int STMin; //start time minutes
  string ET; //End Time
//  int ETMin;
  char AMPM;
  char middle;
  int timeInt;
  printHeader();
  cin >> timeInt;
  while(cin)
  {
    readLine(timeInt);
    cin >> timeInt;
  }




  return 0;
}
void readLine(int interval)
{
  int Shour, Sminute; //holds hour and minutes of start time
  int Ehour, Eminute; //holds hour and minute of end time
  char SAMPM, EAMPM; //holds value of AM or pm for start and end time
  char Colon;
  char flag; //used for print function to determin which to print

  {
    cin >> Shour;
    cin >> Colon;
    cin >> Sminute;
    if(interval == 12)
    {
    cin >> SAMPM;
    }
    flag = 's';
    printData(interval, Shour, Sminute, SAMPM, flag);
    cin >> Ehour;
    cin >> Colon;
    cin >> Eminute;
    if(interval == 12)
    {
    cin >> EAMPM;
    }
    flag = 'e';
    printData(interval, Ehour, Eminute, EAMPM, flag);
  }

}
void printHeader()
{
  string boarder;
  boarder.append(60, '=');

  cout << boarder << endl;
  cout << setw(15) << left << "Adam Hoffman";
  cout << setw(15) << left << "Lec Sec# 1003,";
  cout << setw(15) << left << "Lab sec# 1008,";
  cout << setw(15) << right << "Assignment #3" << endl;
  cout << boarder << endl;
  return;
}
void printData(int interval,int hour,int minute, char AMPM, char flag)
{
  if(flag == 's')
    cout << setw(15) << "Start time: ";
  else if(flag == 'e')
    cout << setw(15) << "End time: ";
  else if (flag == 'i')
    cout << setw(20) << "Interval length: ";

  if(hour < 10){ cout << "0"; }
  cout << hour << ":";
  if(minute < 10) {cout << "0"; }
  cout << minute;
  if(interval == 12 && flag != 'i')
  {
    if(AMPM == 'a' || AMPM ==  'A')
      cout << "am";
    else if(AMPM == 'p' || AMPM == 'P')
      cout << "pm";
  }
  if(flag == 'e')
    cout << endl;

}
