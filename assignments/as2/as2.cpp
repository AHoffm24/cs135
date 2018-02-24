/*
Adam Hoffman, Lect# 1003, Lab# 1008, Assignment2
This program is meant to read in information about each individual employee
determine their employee type, read in extra values depending on their 
employee type for thing such as commission, Then print out each inidividuals 
total earnings plus their employee type and their id number. 
It will also print how many employees were proccessed plus 
the average amount of money payed to each employee processed.
*/
#include <iostream>
#include <iomanip>

using namespace std;

const int commishSalary = 400; //salary for commissioned employees
const double commish = 0.20;  //commission for normal commissioned employess
const double tempCommish = 0.15; //commission for temp commissioned employees


int main()
{
  int id = 0;//used to store id number
  int items = 1; //used in pay code. Initially set to 1 for loop purpose
  char payCode;// used to store pay code char;
  double hours = 0;//used to store hours, or the 3rd input for other inputs
  double total = 0;//used to do calculations of total payment
  double overtime = 0; //used to help equat overtime pay
  double tempPay = 0; //used in temporary employee to store their hourly pay
  double totalEarned = 0; //stores total Earned
  int totalEmployees = -1; //stored as -1 because it kept saying 1 extra employee
  string boarder;//used to create boarder around name, sections, and assign #

  //print heading
  boarder.append(48, '=');
  cout << boarder << endl;
  cout << "Adam Hoffman, Lect# 1003, Lab# 1008, Assignment2" << endl;
  cout << boarder << endl << endl;
  cout << setw(10) << left <<  "Id#";
  cout << setw(15) << left << "Category";
  cout << setw(10) << right << "Earnings" << endl;
  boarder = "";
  boarder.append(35, '-');
  cout << boarder << endl; //end of print heading

  cin >> id;
  while(cin) //end of file loop
    {
      cin >> payCode >> hours;

      if (payCode =='S' || payCode =='s') { //salaried employee

        cout << fixed  << left << setw(10) << id;
        cout << fixed  << left << setw(15) << "Salaried";
        cout << "$ " << right << setw(8) << setprecision(2) << hours << endl;
        totalEarned += hours; //storing total earned by all employees
        totalEmployees++;
      }

      else if (payCode == 'H' || payCode == 'h') { //Hourly employee
        cin >> total; // take in hourly rate
        if(hours > 40){ //equating for overtime pay
          overtime = hours - 40;
          hours = hours - overtime;
          overtime = overtime * total * 1.5;
          total = hours * total + overtime;
          overtime = 0;
          totalEmployees++;
        }
        else{ //no overtime pay
          total = hours * total;
        }
        cout << fixed  << left << setw(10) << id; //print employee info
        cout << fixed  << left << setw(15) << "Hourly";
        cout << "$ " << right << setw(8) << setprecision(2) << total << endl;
        totalEarned += total; //storing total earned by all employees
        total = 0; //restting total to 0;
        totalEmployees++;
      }

      else if(payCode == 'C' || payCode == 'c'){
        total = hours;
        for(int i = 0; i < 4; i++){ // only reading in 4 values since 1st was read
          cin >> hours; //taking in sales for the 5 days of the week
          total += hours; //adding the total sales
        }
        total = total * commish + commishSalary; //finds commission + adds salary
        cout << fixed  << left << setw(10) << id; //print employee info
        cout << fixed  << left << setw(15) << "Commissioned";
        cout << "$ " << right << setw(8) << setprecision(2) << total << endl;
        totalEarned += total; //storing total earned by all employees
        total = 0;
        totalEmployees++;
      }

      else if(payCode == 'T'|| payCode == 't'){
        cin >> tempPay >> total; //pay rate, total sales
        total = total * tempCommish; //total sales * 0.15
        total = total + hours * tempPay; // commish plus hourly pay

        cout << fixed  << left << setw(10) << id; //print employee info
        cout << fixed  << left << setw(15) << "Temporary";
        cout << "$ " << right << setw(8) << setprecision(2) << total << endl;
        totalEarned += total; //storing total earned by all employees
        total = 0;
        tempPay = 0;
        totalEmployees++;
      }
      else if(payCode == 'P'|| payCode == 'p'){

	while(items != 0)
          {
            cin >> items;
            total += items;
          }
	total = total * hours; //total items * item price
	cout << fixed  << left << setw(10) << id; //print employee info
	cout << fixed  << left << setw(15) << "PieceWorker";
	cout << "$ " << right << setw(8) << setprecision(2) << total << endl;
	totalEarned += total;
	total = 0;
	items = 1;
	totalEmployees++;
      }

      cin >> id; //if end of file is found, stops while loop

    }
  //below prints total earned by all employees plus the avg earned by each
  cout<< setw(25) << left << "TOTAL EARNED" << "$ ";
  cout<< setw(8) << setprecision(2) << right << totalEarned << endl << endl;
  cout<< totalEmployees << " employees processed" << endl;
  totalEarned = totalEarned / totalEmployees;
  cout << "Average pay per employee: $" << setprecision(2) << totalEarned << endl;

}
