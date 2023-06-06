//Temperature conversion program by Andrew Brown 3/04/2019
//Assignment for lab 7

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//Defining functions
int fahrenheit (int c)
{
	return ((1.8*c)+32);
}

double fahrenheit (double c)
{
	return ((1.8*c)+32);
}

int celsius (int f)
{
	return ((f-32)*(5.0/9.0));
}

double celsius (double f)
{
	return ((f-32)*(5.0/9.0));
}

//Begin program
int main()
{
	cout<<"90.3763 F is equal to "<<celsius(90.3763)<<" celsius."<<endl;
	cout<<"0 F is equal to "<<celsius(0)<<" celsius."<<endl;
	cout<<"32 F is equal to "<<celsius(32)<<" celsius."<<endl;
	cout<<"56.743 F is equal to "<<celsius(56.743)<<" celsius."<<endl;
	cout<<"0.0 F is equal to "<<celsius(0.0)<<" celsius."<<endl;
	cout<<"166 F is equal to "<<celsius(166)<<" celsius."<<endl;
	
	cout<<"\n0 C is equal to "<<fahrenheit(0)<<" fahrenheit."<<endl;
	cout<<"45.363 C is equal to "<<fahrenheit(45.363)<<" fahrenheit."<<endl;
	cout<<"22 C is equal to "<<fahrenheit(22)<<" fahrenheit."<<endl;
	cout<<"55.3 C is equal to "<<fahrenheit(55.3)<<" fahrenheit."<<endl;
	cout<<"100.0000 C is equal to "<<fahrenheit(100.0000)<<" fahrenheit."<<endl;
	cout<<"70 C is equal to "<<fahrenheit(70)<<" fahrenheit."<<endl;

return (0);
}