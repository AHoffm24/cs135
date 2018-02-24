#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
/*functions*/

struct inventory
{
public:
  string LP; //license plate number
  string make;
  string model;
};
void printHeader();
void readArray(inventory&[]);
void getFileNames(string&, string&);
int main()
{
  string input;
  string output;
  getFileNames(input, output);
  inventory info[40];
  for(int i =0; i < 40; i++)
  {
      info[i].LP = "holy crap";
  }
  for(int i =0; i < 40; i++)
  {
      cout << info[i].LP << endl; }
  return 0;
}
void getFileNames(string& input, string& output)
{
  cout << "Enter the name of the output file" << endl;
  cin >> input;
  cout << "Enter the name of the inventory file" << endl;
  cin >> output;
  return;
}
void printHeader()
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
void readArray(inventory& info[], string fileName)
{


}
