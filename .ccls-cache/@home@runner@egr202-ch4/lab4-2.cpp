//Lab4-2.cpp - displays a salesperson's commission
//Philip Regalbuto
#include <iostream>
using namespace std;
int main()
{
  //declare named constant and variables
  const double COMM_RATE = 0.1;
  double sales           = 0.0;
  double commission      = 0.0;
  //enter input item
  cout << "Sales amount: ";
  cin >> sales;
  //calculate and display the commission
  commission = sales * COMM_RATE;
  cout << "Commission: $" <<	commission << endl;
  //system("pause");
  return 0;
} //end of main function
/*
Sales amount: 1328.50
Commission: $132.85
Press any key to continue . . .
*/