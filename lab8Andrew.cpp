//Lab 8 assignment by Andrew Brown 3/18/2019
//Recursive function for power and gcd

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int power(int base, int exponent); //Function prototype
int gcd(int x, int y); //Function prototype

main()
{
	int a{1}; //An integer for the user to input
	int b{1}; //An integer for the user to input
	
	//Get user input for power functon
	cout<<"Please enter two integers, a base and an exponent: ";
	cin>>a>>b;
	cout<<"\n"<<a<<" to the power of "<<b<<" equals "<<power(a, b)<<endl;
	
	//Get user input for gcd function
	cout<<"Please enter two integers: ";
	cin>>a>>b;
	cout<<"The greatest common divisor of "<<a<<" and "<<b<<" is "<<gcd(a, b)<<endl;
	
return(0);
}

//Function to find the number produced when 'base' is risen to the 'exponent' power.
int power(int base, int exponent)
{
	if (exponent < 1) //Check for valid user input
	{
		cout<<"Error: Function could not run.\nYour exponent was not valid! It must be an integer greater than 0."<<endl;
		return 0;
	}
	else
	{
		if (exponent == 1) //Base case
		{
			return base;
		}
		else //Recursive step
		{
			return base * power(base, (exponent - 1));
		}
	}
}


//Function to find the greatest common divisor of x and y
int gcd(int x, int y)
{
	if (x <= y) //Check for valid user input
	{
		cout<<"Error: Function could not run.\nFor this function to run properly, x must be greater than y."<<endl;
		return 0;
	}
	else
	{
		if (y == 0) //Base case
		{
			return x;
		}
		else //Recursive step
		{
			return gcd(y, x%y);
		}
	}
}