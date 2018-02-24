//Adam Hoffman, Assignment 1, Lect_1002, Lab_1008
//purpose of this program is to find the amount of plastic needed to create

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
  int boxes;
  double L, W, H, T, P;
  float cost, over, total; 
  string stars;
  cout << "How many boxes are to be made? "; 
  cin >> boxes;
  cout <<"What is the exterior length of a box(in cm)? ";
  cin >> L; 
  cout <<"What is the exterior width of a box(in cm)? ";
  cin >> W;
  cout <<"What is the exterior height of a box(in cm)? ";
  cin >> H;
  cout <<"what is the thickness of the sides and bottom (in cm)? ";
  cin >> T;

  /* Creating header with personal informations*/
  stars.append(48, '*');
  cout << stars << endl;
  cout << "Adam Hoffman, Lec #1003, Lab #1008, Assignment#1" << endl;
  cout << stars << endl << endl;

  

  /* creating job cost estimate to print out all information for the 
     theoretical customer" */
  cout << "JOB COST ESTIMATE"  << endl;
  cout << "Box Dimensions --"  << endl;
  cout << "Exterior lenght:   "  << fixed << setw(25) << right 
       << setprecision(3) << L << " cm" << endl;
  cout << "Exterior Width:    "  << setw(25) << right 
       << setprecision(3) << W << " cm" << endl;
  cout << "Exterior heigh:    "  << setw(25) << right 
       << setprecision(3) << H << " cm" << endl;
  cout << "Side/Bottom Thickness:" << setw(22) << right 
       << setprecision(3) << T <<" cm";
  cout << endl << endl;

  /* arithmatic for finding the volume of the box, the amount of plastic
     needed, cost of plastic, overhead, and total estimate.
  
    Below P = cubic cm of plastic needed for each container. The first part
    finds the cu cm of the side of width, the second part finds the cu cm of
    the length side panels of the box and the plastic needed, and the third
    find the bottom cu cm of plastic needed. when they add together
    they find the total cu cm of plastic needed to build 4 walls and 
    the containers bottom
  */
  P = ((W*(H-T)*T*2) + ((L-(2*T))*(H-T)*2*T) + (L*W*T))*boxes;
      
  cost = P * (0.005);
  over = cost * 0.25;
  total = cost + over;
   
  cout << "Boxes ordered:     " << setw(25) << right << boxes << endl;
  cout << "Plastic needed:    " << setw(25) << right << P << " cu cm";
  cout << endl << endl;
  
  cout << "Cost of plastic:   " << setw(17) << right << "$  ";
  cout << setw(8) << right << setprecision(2) <<  cost << endl;
  cout << "Overhead:          " << setw(17) << right << "$  "; 
  cout << setw(8) << right << setprecision(2) << over << endl;
  cout << "Total estimate:    " << setw(17) << right << "$  ";
  cout << setw(8) << right << setprecision(2) << total << endl;
  cout << stars << endl; 
  return 0;
}
