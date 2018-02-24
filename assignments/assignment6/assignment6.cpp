//Adam Hoffman, Lecture 1002, Assignment 6

/* Expected Input: 3 data files, file 1 will contain employees first name, 
last name,3 digit employee ID#, their job status F(full time) P(part time)
and their hourly rate. It is expected that their is no bad or misplaced info
in this file. 	
File 2 will contain updated information for each employee. 
It will contain an employee ID number that is used to identify and employee
and it followed by a command code which determine if were switching 
job status or hourly wage. This file is to be checked for bad ID# and info.
The 3RD file contain employee ID#'s and each id number will be
followed by their hours worked, which is used to find total pay. 

expected output: Expected output for file 1 is to print Each employee in 
alphabetical order, last name first, followed by first name, their ID#, 
their job status, and their hourly wage.
The second file is expected to output the ID# of the employee whose info
was to be changed, and then output what thei hourly pay rate changed to, or 
what their job status switched to. It also is expected to print when 
an invalid ID number is given in the input file. It is also expected to 
reoutput what was printed after input file1 but with the updates.
The third file will give the hours worked and the expected output is to 
print the The last name first, followed by first name, Then that individuals
pay rate, the amount of hours worked, and the total pay they should expect. 
It should also output the total pay and total hours worked by all the 
employees combined. 
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>
using namespace std;
int MAX = 25; //maximum number of employees
int W = 30; //used for width in printinfo
struct employee{
  string first, last;     //emplyee first and last name
  int id;                 //employee id number
  char status;            //job status part or full time
  double wage;            //hourly pay 
  double hrsworked;       //hours worked
  double total;	          //total pay for each individual 
};

void staffinfo    (employee[], int&);
void fixname      (string&);
void bubblesort   (employee[], int);
void printinfo    (employee[], int);
void change       (employee[], int);
void hours_total  (employee[], int);
void printpayroll (employee[], int);

int main()
{
  employee info[MAX]; 	//array to store employee info;
  int count = 0;      	//number of employees 
  staffinfo   (info, count);
  bubblesort  (info, count);
  printinfo   (info, count);
  change      (info, count);
  printinfo   (info, count);
  hours_total (info, count);
  printpayroll(info, count);
  cout << endl;
  return 0;
}

void staffinfo(employee info[], int& n)
/* The function staffinfo will retriever the employees business related
information such as, First name, Last name, I.D.#, Their job status, and
their hourly pay. It also counts the number of employees. It also calls the
function fixname */
{
  string filename;  //input file name
  ifstream in;      //input file
  cout << "Enter name of first data file" << endl;
  cin >> filename;
  in.open(filename.c_str()); //input file open
  in >> info[n].first; //input first name
  while(in)
    {
      in >> info[n].last;
      fixname(info[n].first);
      fixname(info[n].last);
      in >> info[n].id;
      in >> info[n].status;
      in >> info[n].wage;
     n++;
      in >> info[n].first;
    }
  in.close();          // input file closed
 
}
void fixname(string& word)
/*The function fixname take the first and last name of each employees and 
uppercases the first letter in their first and their last name. It follows
that by lowercasing the rest of the letter in the first and last name.*/

{
  int wlen=word.length();
  word[0] = toupper(word[0]);
  for (int i = 1; i<wlen; i++)
    word[i] = tolower(word[i]);
}

void printinfo (employee info[], int n)
/*This function is used to print the employee info name, id number, 
job status, and outputs this information in clear, organized columns & rows
*/ 
{
  cout << setw(W) << left << "Name";
  cout << setw(5) << right << "ID#";
  cout << setw(10) << right << "STATUS";
  cout << setw(10) << right << "RATE" << endl;
  for(int i = 0; i < n; i++){
    cout << setw(W) << left << info[i].last+','+info[i].first;
    cout << setw(5) << right << info[i].id;
    cout << setw(5) << right << info[i].status;
    cout << setw(8) << '$';
    cout << fixed << setprecision(2) << setw(7) << info[i].wage << endl;
  }
  cout << endl;
}

void bubblesort (employee name[], int n)
/*Given the employee struct(name[]) and the amount of employees(int n).
Function bubble sort is used to alphabatize the employees and their
information by last name, for better organization.*/
{
  int i, j;
  employee temp; 
  for (i = 0; i < n-1; i++)
    for (j = 0; j < n-(i+1); j++)
      if (name[j].last > name[j+1].last)
	{
	  temp = name[j];
	  name[j] = name[j+1];
	  name[j+1] = temp;
	}
       
}
void change(employee info[], int n)
/*Given employee struct(info[]), and the amount of employees(int n).
This folder uses filestream to input new employee information that needs 
to be updated. It first check to see that the employee ID# were trying to
change is a valid employee, It then either changes job status is S is 
following id number, or changes hourly wage is P follows the ID number in 
the input file. After changing the information, it outputs what was updated
in the employee info struct and outputs what invalid ID# were found*/
{
  string filename2; //name of second input file
  ifstream in2;     //input file
  int idnum;        //temporary id number holder
  char command;     //temporary command holder
  bool check;	    // true = valid id number, false = invalid id number
  
  cout << "Enter name of second data file" << endl;
  cin >> filename2; 
  in2.open(filename2.c_str());//open file 2
  in2 >> idnum; 
  while (in2)
  {
    for (int i = 0; i < n; i++)
      {
	if ((idnum == info[i].id))//checks to see if ID# is Valid
	  {
	    cout << "ID# ";
	    cout << info[i].id << " ";
	    in2 >> command; 
	    command = toupper(command);
	    if(command == 'S')//changes employee job status 
	      {
		check = true;
		in2 >> info[i].status;
		cout << "status change to " << info[i].status << endl;
	      }//if
	    else if(command == 'P')//changes wages of employee with given id
	      {
		check = true; 
		in2 >> info[i].wage;
		cout << "Hourly pay rate changed to ";
		cout << info[i].wage << endl;
	      }
	  }
      }

    if (check == false)
      {		       
	in2.ignore(80, '\n'); //ignore command to ignore invalid data
	cout << "ID# " << idnum << " is invalid" << endl;
      }			      //and skip to the next line of input file. 
   
    in2 >> idnum;
    check = false; 
  }
  in2.close(); //close inputfile2
  cout << endl;
}

void hours_total(employee info[], int n)
/*Given employee info struct(info[] and the number of employees (int n)
It retrieves information from a input file that contains the employees ID#
and the number of hours worked by said employee. It also adds the total 
number of hours worked.*/
{
  string filename3; //input file name
  ifstream in3;     //input file 
  bool valid_id; //helps determine valid id;
  int idnum;    //temporary id# holder
  double hours; //used for adding up total hours worked

  cout << "Enter name of third data file" << endl;
  cin >> filename3;
  in3.open(filename3.c_str());//open file 3 
  in3 >> idnum;
  while (in3)
    {
      for (int i = 0; i < n; i++)
	{
	  if ((idnum == info[i].id))//checks to see if ID# is Valid  
	    {
	      in3 >> hours; 
	      info[i].hrsworked = info[i].hrsworked + hours;
	      valid_id = true;
	    }
	}//end of for
      if (valid_id == false)
	{
	  in3.ignore(80, '\n');
	} 

      in3 >> idnum;
      valid_id = false;	
    }
}

void printpayroll(employee info[], int n)
/*Given employee info struct (info[]) and number of employees(int n)
used to find the total pay for each individual employee by multiplying 
the individual employees hours worked by their hourly wage. It also adds the
total pay role of all the employees combined. It then prints it out in 
organized columns and rows for each individual, alphabetically. It includes
their name, pay rate, hours worked, and total made. */
{
  double temp;      //used for calculating money made from overtime 
  double OT;        //used for calculating how much overtime was made
  double total = 0; //add total amount of all employees earnings
  double hours = 0; //add total number of hours worked
  cout << setw(W) << left << "Name";
  cout << setw(5) << right << "PAY RATE";
  cout << setw(10) << right << "HOURS";
  cout << setw(10) << right << "TOTAL" << endl;

  for(int i = 0; i < n; i++)
    {
      if (info[i].status == 'P')
	{
	  info[i].total = (info[i].hrsworked * info[i].wage);
	}
      else
	{
	  if(info[i].hrsworked > 40)
	    {
	      OT = info[i].hrsworked - 40;
	      temp = OT * (info[i].wage * 1.5);
	      info[i].total = (info[i].wage * 40) + temp;
	    }
	  else
	    info[i].total = info[i].hrsworked * info[i].wage;
	}
      hours = hours + info[i].hrsworked;
      total = total + info[i].total;
      cout << setw(W) << left << info[i].last+','+info[i].first;
      cout << '$' << setw(7) << right << info[i].wage;
      cout << setw(10) << right << info[i].hrsworked;
      cout << setw(3) << right << '$';
      cout << setw(9) << right << info[i].total << endl;
    }  
  cout << setw(48) << right << hours;
  cout << setw(3) << right << '$';
  cout << setw(9) << right << total << endl;
}
