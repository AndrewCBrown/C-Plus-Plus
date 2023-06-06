//Test driver program for StudentAndrew.h header file by Andrew Brown 2/5/2019
#include<iostream>
#include<string>
#include"StudentAndrew.h"

using namespace std;

int main()
{
	Student senior("Ryan", "Schaeffer", 4, "Sports Management", 22, 'm');
	senior.displayStudent();
	
	Student senior_2("Bre", "Barney", 4, "Middle Level Math Education", 21, 'f');
	senior_2.displayStudent();
	
	cout<<senior_2.getFirstName();
	cout<<senior_2.getLastName();
	cout<<senior_2.getYear();
	cout<<senior_2.getMajor();
	cout<<senior_2.getAge();
	cout<<senior_2.getGender()<<endl;
	
	senior_2.setFirstName("Breanna");
	senior_2.setLastName("Purple Dinosaur");
	senior_2.setYear(35);
	senior_2.setMajor("Ministry");
	senior_2.setAge(9+10);
	senior_2.setGender('m');
	
	senior_2.displayStudent();
};
