//Lab4-3.cpp - displays a salesperson's commission
//Created/revised by <your name> on <current date>

#include <iostream>
using namespace std;

int main()
{
  //declare variables
  double commRate   = 0.0;
  double sales      = 0.0;
  double commission = 0.0;

  //enter input items
  cout << "Sales amount: ";
  cin >> sales;
  cout << "Commission rate (in decimal form): ";
  cin >> commRate;

  //calculate and display the commission
  commission = sales * commRate;
  cout << "Commission: $"
    << commission << endl;

  return 0;
} //end of main function