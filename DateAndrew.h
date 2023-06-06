// Definition of class Date.
#include <iostream>

// class Date definition
class Date {
public:
    Date(int m, int d, int y)
      : month{m}, day{d}, year{y} {

      if (month < 1) {
        month = 1;
      }

      if (month > 12) {
        month = 1;
      }
   } 

   void setMonth(int m) {
      month = m;

      if (month < 1) {
         month = 1;
      }

      if (month > 12) {
         month = 1;
      }
   } 

   int getMonth() {
      return month;
   } 

   void setDay(int d) {
      day = d;
   } 

   int getDay() {
      return day;
   } 

   void setYear(int y) {
      year = y;
   } 

   int getYear() {
      return year;
   } 

   void displayDate() { 
      std::cout<<month<<"/"<<day<<"/"<<year<<std::endl;
   } 


private:
   int month{5}; // the month of the date
   int day{31}; // the day of the date
   int year{2018}; // the year of the date
}; 

