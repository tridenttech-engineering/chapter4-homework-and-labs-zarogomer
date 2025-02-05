// Intermediate14.cpp - displays total sold and percentages of small, medium,
// large, and family sold Created/revised by <your name> on <current date>

#include <iostream>
using namespace std;

int main() {
  int small = 0;
  int medium = 0;
  int large = 0;
  int family = 0;
  int totalSold = 0;
  double smallPercent = 0.0;
  double medPercent = 0.0;
  double largePercent = 0.0;
  double familyPercent = 0.0;

  cout << "Small pizzas: ";
  cin >> small;
  cout << "Medium pizzas: ";
  cin >> medium;
  cout << "Large pizzas: ";
  cin >> large;
  cout << "Family pizzas: ";
  cin >> family;

  totalSold = small + medium + large + family;
  smallPercent = static_cast<double>(small) / totalSold * 100;
  medPercent = static_cast<double>(medium) / totalSold * 100;
  largePercent = static_cast<double>(large) / totalSold * 100;
  familyPercent = static_cast<double>(family) / totalSold * 100;

  cout << endl << "Total sold: " << totalSold << endl;
  cout << "Small percentage: " << smallPercent << "%" << endl;
  cout << "Medium percentage: " << medPercent << "%" << endl;
  cout << "Large percentage: " << largePercent << "%" << endl;
  cout << "Family percentage: " << familyPercent << "%" << endl;

  return 0;
} // end of main function