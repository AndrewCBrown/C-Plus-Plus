//Program 1 from the homework by Andrew Brown 1/28/2019
//Program receives 3 integers and computes the sum, average, product, smallest, and largest.
#include<iostream>
using namespace std;

int main()
{
	//Declaring and initializing the user inputted variables.
	int integer_1{0};
	int integer_2{0};
	int integer_3{3};
	//Declaring and initializing calculation variables.
	int sum{0};
	int avg{0};
	int product{0};
	int min{0};
	int max{0};
	
	//User input
	cout<<"Enter three different integers:";
	cin>>integer_1>>integer_2>>integer_3;
	
	//Calculations
	sum=integer_1+integer_2+integer_3;
	avg=sum/3;
	product=integer_1*integer_2*integer_3;
	//Determine min
	if (integer_1<integer_2)
	{
		if (integer_1<integer_3)
		{
			min=integer_1;
		}
	}
	if (integer_2<integer_1)
	{
		if (integer_2<integer_3)
		{
			min=integer_2;
		}
	}
	if (integer_3<integer_1)
	{
		if (integer_3<integer_2)
		{
			min=integer_3;
		}
	}
	//Determine max
	if (integer_1>integer_2)
	{
		if (integer_1>integer_3)
		{
			max=integer_1;
		}
	}
	if (integer_2>integer_1)
	{
		if (integer_2>integer_3)
		{
			max=integer_2;
		}
	}
	if (integer_3>integer_1)
	{
		if (integer_3>integer_2)
		{
			max=integer_3;
		}
	}
	//Determining max and min for cases with identical integers.
	if (integer_1==integer_2)
	{
		if (integer_1==integer_3)
		{
			max=integer_1;
			min=integer_1;
		}
		if (integer_1<integer_3)
		{
			min=integer_1;
			max=integer_3;
		}
		if (integer_1>integer_3)
		{
			min=integer_3;
			max=integer_1;
		}
	}
	if (integer_1==integer_3)
	{
		if (integer_1<integer_2)
		{
			min=integer_1;
			max=integer_2;
		}
		if (integer_1>integer_2)
		{
			min=integer_2;
			max=integer_1;
		}
	}
	if (integer_2==integer_3)
	{
		if (integer_2<integer_1)
		{
			min=integer_2;
			max=integer_1;
		}
		if (integer_2>integer_1)
		{
			min=integer_1;
			max=integer_2;
		}
	}
	
	//Output statements
	cout<<"Sum is "<<sum<<endl;
	cout<<"Average is "<<avg<<endl;
	cout<<"Product is "<<product<<endl;
	cout<<"Smallest is "<<min<<endl;
	cout<<"Largest is "<<max<<endl;
}