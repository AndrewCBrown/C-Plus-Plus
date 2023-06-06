//Numerical Analysis
//Chapter 4 Project
//Numerical Quadrature Composite Rules
//by Andrew Brown November 22nd 2019

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//Function header for e^(x^2)
double f(double x);

int main()
{
	//Get the input (b, and n for the number of pieces that partition [1,b]).
		//Note that b must be greater than or equal to 1, and n must be an integer greater than or equal to 1.
		//Also note that n must be odd and greater than or equal to 3 for simpson's rule to work.
		
	//Explain the program and the values that will need to be entered
	cout<<"Welcome! This program approximates the integral of e^(x^2)dx on the interval [1,b]."<<endl;
	cout<<"You will be able to enter a value for b, as well as a value for n, which is the"<<endl;
	cout<<"number of pieces that will partition [1,b]."<<endl;
	cout<<"\nThis program uses both the composite trapezoidal rule, and the composite"<<endl;
	cout<<"Simpson's rule to approximate the integral, and then displays the result for both."<<endl;
	
	//Get user input
	double b;
	cout<<"Please enter a value greater than or equal to 1 for b: ";
	cin>>b;
	cout<<endl;
	while (b < 1)
	{
		cout<<"Whoops! That is not a valid entry.\nPlease try entering a number greater than or equal to 1: ";
		cin>>b;
		cout<<endl;
	}
	
	int n;
	cout<<"Please enter an integer value greater than or equal to 1 for the number of pieces that partitions [1,b]: ";
	cin>>n; //Note: If the user enters a decimal number, it will be truncated down to the nearest integer value.
	cout<<endl;
	while (n < 1)
	{
		cout<<"Whoops! That is not a valid entry.\nPlease try entering an integer greater than or equal to 1: ";
		cin>>n;
		cout<<endl;
	}
	
	//Set flag for if simpson's rule can be used.
	bool simpsons_is_valid;
	if ((n >= 2) && (n%2 == 0))
	{
		simpsons_is_valid = true;
	}
	else
	{
		simpsons_is_valid = false;
	}
	
	
	//Set up for calculations
	double h = (b - 1)/n;
	
	//Use composite trapezoidal rule
	double trapezoidal_approximation;
	double inner_sum = 0;
	
	for (int i = 0; i < (n - 1); i++)
	{
		inner_sum += f(1 + ((i+1)*h));
	}
	
	trapezoidal_approximation = (h/2)*(f(1) + f(b) + 2*(inner_sum));
	
	//Use composite Simpson's rule
	double simpsons_approximation;
	if (simpsons_is_valid)
	{
		double middle_sum = 0;
		double inside_sum = 0;
		
		for (int i = 0; i < n; i += 2)
		{
			middle_sum += f(1 + ((i+1)*h));
		}
		for (int i = 0; i < (n - 3); i += 2)
		{
			inside_sum += f(1 + ((i+2)*h));
		}
		
		simpsons_approximation = (h/3)*(f(1) + f(b) + 2*(inside_sum) + 4*(middle_sum));
	}
	
	//Print results to screen
	cout<<"\n"<<endl;
	//Print results for trapezoidal rule
	cout<<"Using the trapezoidal rule with "<<n<<" pieces to partition the interval,"<<endl;
	cout<<"the integral of e^(x^2)dx on the interval [1,"<<b<<"] is approximately equal to "<<setprecision(12)<<trapezoidal_approximation<<"."<<endl;
	
	//Print results for Simpson's rule
	if (simpsons_is_valid)
	{
		cout<<"Using Simpson's rule with "<<n<<" pieces to partition the interval,"<<endl;
		cout<<"the integral of e^(x^2)dx on the interval [1,"<<b<<"] is approximately equal to "<<setprecision(12)<<simpsons_approximation<<"."<<endl;
	}
	else
	{
		cout<<"The program was not able to approximate the integral using Simpson's method."<<endl;
		cout<<"Note that the value for n must be even and greater than or equal to 2 in order for Simpson's rule to be applied."<<endl;
	}
	
	
	
	return 0;
}



//Function definition for e^(x^2)
double f(double x)
{
	return exp(pow(x,2));
}