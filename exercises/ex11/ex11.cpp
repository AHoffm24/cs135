/*
Adam Hoffman, exercise 11, lec 1003, lab 1008
read in words and print them back words
also count total number of words read and number of LC vowels
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
void printHeader();
void printBackwards(string);
int totalLowerVowels(string);



int main()
{
  string word; //store read word
  int vowels = 0; //for counting total number of lower case vowels
  int count = 0; //total count of words
  printHeader(); //prints header information for myself
  cout << endl;
  cout << "BACKWARDS WORDS" << endl;
  cin >> word;
  while(cin)
    {
      printBackwards(word);
      vowels += totalLowerVowels(word);
      
      cout << endl;
      count++;
      cin >> word;

    }
  cout << endl << "Words in file: " << count << endl;
  cout << "Lowercase vowels in file: " << vowels << endl;
  return 0;
}
void printHeader()
{
  string boarder;
  boarder.append(60, '=');
  cout << boarder << endl;
  cout << setw(15) << left << "Adam Hoffman,";
  cout << setw(15) << left << "Lec Sec# 1003,";
  cout << setw(15) << left << "Lab sec# 1008,";
  cout << setw(15) << right << "Exercise 11" << endl;
  cout << boarder << endl;
  return;
}

void printBackwards(string word)
{
  for(int i = (word.length() - 1); i >= 0;i--)
    {
      cout << word[i];
    }
  return;
}

int totalLowerVowels(string word)
{
  int vowel = 0;
  for(int i = (word.length() - 1); i >= 0;i--)
    {
      switch(word[i]) {
      case 'a' :
	vowel++;
	break;
      case 'e':
	vowel++;
	break;
      case 'i':
	vowel++;
	break;
      case 'o':
	vowel++;
	break;
      case 'u':
	vowel++;
	break;
      }
    }
  return vowel;
}
