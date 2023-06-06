// Driver program that demonstrates class Date's capabilities.
// Name: Teresa Hale-Lespier (Edited by Andrew Brown)
// Assignment: Lab2
// Date: 1/28/19
//
//
#include <iostream>
#include "DateAndrew.h" // include definition of class Date from Date.h
using namespace std;

// function main begins program execution
int main()
{
   Date firstDayOfTerm{1, 8, 2019};
   Date lab2Date{1, 28, 2019};
   Date mysteryDate{7,4,2005};
   
   // display the month day and year of firstDayofTerm. One per line with labels.
   cout << "Month:" << firstDayOfTerm.getMonth() << endl;
   cout<<"Date:"<<firstDayOfTerm.getDay()<<endl;
   cout<<"Year:"<<firstDayOfTerm.getYear()<<endl;
   
   // display the year, month and day of lab2Date all on the same line in the requested order.
   cout<<lab2Date.getYear()<<lab2Date.getMonth()<<lab2Date.getDay()<<endl;
   
   // use displayDate to print out the mysteryDate 
   mysteryDate.displayDate();
} 

