#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double labor = 3.50; //constant for labor per square yard of material
const double salestax = .05;//constant for sales tax. only for pad cost and carpet cost
const int n = 30; //used in the setw for all outputs set to the left

int main()
{
  //declaring all variables
  int lfeet = 0; //length in feet
  int linch = 0; //length in inches
  int wfeet = 0; //width in feet
  int winch = 0; //wdith in inches
  int sqyd  = 0; //square yards
  double length  = 0; //length total for sqyd equation
  double width   = 0; //width total for sqyd equation

  double carcost = 0; //carpet cost per square yard
  double padcost = 0; //pad cost per square yard

  double padtot  = 0; //total cost of pad for given square footage
  double cartot  = 0; //total cost of carpet for given square footage

  double labortotal = 0; //total labor cost
  double salestaxtotal = 0; //total salestax
  double total   = 0; //total cost of carcost+padcost+labortotal+salestaxtotal
  
  cout << "Please enter length of room (feet inches)" << endl;
  cin  >> lfeet >> linch; //asks user for feet and inches for length

  cout << "Please enter width of room (feet inches)" << endl;
  cin  >> wfeet >> winch; //asks user for feet and inches of width

  cout << "Please enter cost per square yard of carpet" << endl;
  cin  >> carcost; //asks user for cost of carpet per square yard 

  cout << "Please enter cost per square yards of padding" <<endl; 
  cin  >> padcost; //asks user for cost of padding per square yard 

  cout << setfill('~') << setw(40) << "~" << endl;//creating boarder with a width of 40
  cout << "Magic Carpeting Co Esitmate" << endl; //company name
  cout << "Generate by Adam Hoffman"      << endl; //creator
  cout << "Lec Sec#1002 Assignment 2"   << endl; //class info
  cout << setw(40)<< "~"  << setfill(' ') << endl; //creating boarder with width of 40.
  
  //all of the following statments each have a total width of 40
  cout << "Room Dimensions" << endl; //output room dimension, 
  cout << setw(n) << left << "Length:"; // total width of output will be 40
  cout << setw(4) << right<< lfeet << "\'"; //length in feet
  cout << setw(4) << right<<  linch << "\"" <<endl;  //length in inches

  cout << setw(n) << left << "Width:"; //outputs width of carpet
  cout << setw(4) << right <<  wfeet << "\'";//width in feet
  cout << setw(4) << right <<  winch << "\'" << endl; //with in inches

  cout << setw(n) << left << "Carpet cost per sq yd:"; //displays carpet cost per yd
  cout << "$" << setw(9) << right << fixed << setprecision(2) << carcost;
  cout << endl;
  
  cout << setw(n) << left <<  "Padding cost per sq yd:"; //displays pad cost per yd
  cout << "$" << setw(9) << right << setprecision(2) <<padcost << endl;
  
  //using type casting to double in order to ensure precision 
  length = (lfeet)+ double (linch)/12; //equation to create total length 
  width  = (wfeet)+ double (winch)/12; //equation to create total width 
  sqyd   = ceil (length/3 * width/3); //square yards
  cout << setw(n) << left << "Sq Yds Required:"; //output statement 
  cout << setw(10) << right << sqyd << endl << endl; //outputs sqyd on right boarder

  cartot = carcost*sqyd; //equation for total cost of carpet required
  cout << setfill('.') << setw(n) << left << "Carpet Cost" << "$"; 
  //setfill adds periods between output statment and cost
  cout << setfill(' ') <<setw(9) << right << cartot << endl;
  
  padtot = sqyd * padcost; //equations for total cost of padding required
  cout << setfill('.') << setw(n) << left << "Padding Cost" << "$";
  cout << setfill(' ') << setw(9) << right << padtot << endl;
  
  salestaxtotal = (cartot + padtot)*salestax; //equations for sales tax for given quote
  cout << setfill('.') << setw(n) << left << "Sales Tax"<< "$";
  cout << setfill(' ') << setw(9) << right << salestaxtotal << endl;
  
  labortotal = sqyd * labor; //equations for total cost of labor
  cout << setfill('.') << setw(n) << left << "Labor" << "$";
  cout << setfill(' ') << setw(9) << right << labortotal << endl;
  
  total = padtot + cartot + labortotal + salestaxtotal; //equations of total cost. 
  cout << setfill('.') << setw(n) << left << "Total Due" << "$";
  cout << setfill(' ') << setw(9) << right << total <<  endl;
  
  cout << setfill('~') << setw(40) <<"~" <<  endl; //bottom boarder ~  40 width
  return 0;
}
