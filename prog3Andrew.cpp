//Program 3 from the homework by Andrew Brown 1/29/2019
//Program prints a 5 digit integer given by the user but with 3 spaces inbetween each digit.
#include<iostream>
using namespace std;

int main()
{
	//Declaring and initializing variables
	int number{0};
	int a{0};
	int b{0};
	int c{0};
	int d{0};
	int e{0};
	int a_remainder{0};
	int b_remainder{0};
	int c_remainder{0};
	int d_remainder{0};
	
	//User input
	cout<<"Enter a 5-digit integer: ";
	cin>>number;
	
	//Calculations
	a_remainder=number%10000;
	b_remainder=number%1000;
	c_remainder=number%100;
	d_remainder=number%10;
	
	a=(number-a_remainder)/10000;
	b=(number-b_remainder-a*10000)/1000;
	c=(number-c_remainder-a*10000-b*1000)/100;
	d=(number-d_remainder-a*10000-b*1000-c*100)/10;
	e=d_remainder;
	
	//Output statement
	cout<<a<<"   "<<b<<"   "<<c<<"   "<<d<<"   "<<e<<endl;
}