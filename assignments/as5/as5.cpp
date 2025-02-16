/*
Adam Hoffman, Assignment 5, lecture 1003, lab 1008
The purpose of this program is to read in a list of
vehicles that a rental car company owns from a file.
Then read in a list of license plates of all cars
that have been rented.
It will then change the status of each car to either
Available or rented when it process rentals, only
if the license plate entered is in their inventory.
next, it will print the processing rentals from
the second read file. it will then show the status
of only the cars being rented including their LP, make,
model, car type and status.
it next will print the daily rental due for the rental along
with the number of cars rented and available.
Last it will then again print info on all cars and
their stauses.
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;
/*functions*/

struct inventory
{
  string lp; //license plate number
  string make; //make of the car
  string model; //model of the car
  char   cat; //category of the car, compact or Standard
  bool status; //false if rented or true Available
};

int  readRentals(string[], string);
int  readFileInventory(inventory[], string);
void getFileNames(string&, string&, string&);
void printHeader(ofstream&);
void PrintStatus(ofstream&, inventory[], int, int, bool);
double ProcessRentals(ofstream&,inventory[], string[], int, int&);
const int MAX = 40;
const double C = 11.95;
const double S = 19.95;
const double P = 39.95;
int main()
{
  string infile, outfile, rentfile; //holds each file name
  string rentals[MAX]; //string array to hold License# of each rented vehicle
  inventory info[MAX]; //array of max # of vehichles to be read
  int countI = 0; //count inventory
  int countR = 0; //count rentals
  double price = 0.0;
  ofstream out; //outputs info to filename provided


  getFileNames(infile, outfile, rentfile);
  countI = readFileInventory(info, infile);
  countR = readRentals(rentals, rentfile);

  out.open(outfile.c_str());
  printHeader(out);
  PrintStatus(out, info, countI, countR, true);
  price = ProcessRentals(out, info, rentals, countI, countR);
  PrintStatus(out, info, countI, countR, false);

  out << "Daily Rental Due is $";
  out << fixed << setprecision(2) << price << endl;
  out << countR << " Car(s) is(are) currently rented" << endl;
  out << countI - countR << " Car(s) is(are) currently Available";
  out << endl << endl;

  PrintStatus(out, info, countI, countR, true);

  out.close();
  return 0;
}//end main;



double ProcessRentals(ofstream& out,inventory info[], string rentals[], int countI, int& countR)
{
  bool found = false; //used to determine if car exist or not
  double price = 0.0; //adds up total price
  int fail = 0; //used to change count Rentals

  out << "Processing Rentals" << endl;
  for(int i = 0; i < countR; i++)
    {
      for(int j = 0; j < countI;j++)
	{
	  if(rentals[i] == info[j].lp)
	    {
	      info[j].status = false; //changes info in struct car is rented

	      out << "License# " << rentals[i] << " "; 
	      out << info[j].make << " " << info[j].model;
	      out << " rented" << endl;

	      found = true; //car was found no error
	      if(info[j].cat == 'C') //compact car = 11.95
		price += C;
	      else if(info[j].cat == 'S') //standar car = 19.95
		price += S;
	      else //info[j].cap == 'p'
		price += P; //premium car = 39.95

	      j = countI; //stops j loop, to save unneed checking
	    }
	}

      if(found == false) //rental not found dont process
	{
	  out << "Error: " << rentals[i] << "could not be found" << endl;
	  fail += 1; //used to get rid of unfound vehicles in count
	}
      else // rental found resets flag for next rental
	found = false;
    }


  countR = countR - fail; //tells number of rented vehicles
  out << endl << endl;
  return price;
}
/*
  prompts user to enter the name of the output file, input file, and
  rental file names that are to be used for this program.
*/
void getFileNames(string& infile, string& outfile, string& rental)
{
  cout << "Enter the name of the output file" << endl;
  cin >> outfile;
  cout << "Enter the name of the input file" << endl;
  cin >> infile;
  cout << "Enter rental file name" << endl;
  cin >> rental;
}

/*
  reads inventory file, and stores the information of each
  vehicle of the rental company in an array of structs, which
  saves the License plate, Make, model, car type and status of the
  rental of the vehicle in its place in the array.
*/
int readFileInventory(inventory info[], string file)
{
  int count = 0;
  ifstream in; //creating new infile filestream to read info from file
  string LP; //the following 4 variables are used to read in info
  string MAKE; //from the file and manipulate it before storing in
  string MODEL; // the struct
  char   CAT;

  in.open(file.c_str());
  in >> LP;
  while(in)
    {
      in >> MAKE >> MODEL >> CAT;
      for(int i = 0; i < LP.length(); i++)
	{

	  if(isalpha(LP[i]))
	    {
	      LP[i] = toupper(LP[i]);
	    }
	}
      for(int i = 0; i < MAKE.length(); i++)
	{
	  if(i == 0)
	    {
	      MAKE[i] = toupper(MAKE[i]);
	    }
	  else
	    {
	      MAKE[i] = tolower(MAKE[i]);
	    }
	}
      for(int i = 0; i < MODEL.length(); i++)
	{
	  if(i == 0)
	    {
	      MODEL[i] = toupper(MODEL[i]);
	    }
	  else
	    {
	      MODEL[i] = tolower(MODEL[i]);
	    }
	}
      CAT = toupper(CAT);
      info[count].lp = LP;
      info[count].make = MAKE;
      info[count].model = MODEL;
      info[count].cat = CAT;
      info[count].status = true;
      count++;
      in >> LP;
    }//end while(in)
  in.close();
  return count;
}
/*
  reads in the rental file and stores the information in an array of strings
*/
int readRentals(string rentals[], string file)
{
  string item;
  ifstream in;
  int count = 0;
  in.open(file.c_str());
  in >> item;
  while(in)
    {
      for(int i = 0; i < item.length(); i++)
	{
	  if(isalpha(item[i]))
	    {
	      item[i] = toupper(item[i]);
	    }
	}
      rentals[count] = item;
      count++;
      in >> item;
    }
  in.close();
  return count;
}
/*
  prints header of personal information for assignment
*/
void printHeader(ofstream& out)
{
  string boarder; //string to easily print boarder of = signs
  boarder.append(60, '=');
  out << boarder << endl;
  out << setw(15) << left << "Adam Hoffman,";
  out << setw(15) << left << "Lec Sec# 1003,";
  out << setw(15) << left << "Lab sec# 1008,";
  out << setw(15) << right << "Assignment 5" << endl;
  out << boarder << endl << endl;
  return;
}
/*
prints the status of all vehicles to be rented,
as well as each cars make, model, car type,
and license plate number
print status uses a bool so this function could be reused when the
program is expected to show the change in the rented vehicles
and print out the information only on the rented vehicles
*/
void PrintStatus(ofstream& out, inventory info[],int countI, int countR, bool flag)
{
  out << setw(12) << left << "License#";
  out << setw(12) << left << "Make";
  out << setw(12) << left << "Model";
  out << setw(12) << left << "Car Type";
  out << setw(12) << left << "Status" << endl;
  for(int i = 0; i < countI; i++)
    {
      if(flag == true || (flag == false && info[i].status == false))
	{
	  out << setw(12) << left <<  info[i].lp;
	  out << setw(12) << left <<  info[i].make;
	  out << setw(12) << left <<  info[i].model;
	  if(info[i].cat == 'S')
	    out << setw(12) << left << "Standard";
	  else if(info[i].cat == 'C')
	    out << setw(12) << left << "Compact";
	  else //info[i].cat == 'P'
	    out << setw(12) << left << "Premium";
	  if(info[i].status == true)
	    out << setw(12) << left <<  "Available" << endl;
	  else
	    out << setw(12) << left <<  "Rented" << endl;
	}
    }
  out << endl << endl;
}
