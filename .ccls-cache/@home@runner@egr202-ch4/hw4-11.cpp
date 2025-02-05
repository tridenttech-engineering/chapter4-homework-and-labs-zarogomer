// Introductory11.cpp - displays ending balance
// Created/revised by <your name> on <current date>

#include <iostream>
using namespace std;

int main() {
  double beginning = 0.0;
  double deposits = 0.0;
  double withdrawals = 0.0;
  double ending = 0.0;

  cout << "Beginning balance: ";
  cin >> beginning;
  cout << "Total deposits: ";
  cin >> deposits;
  cout << "Total withdrawals: ";
  cin >> withdrawals;

  ending = beginning + deposits - withdrawals;
  cout << "Ending balance: $" << ending << endl;

  return 0;
} // end of main function