//Linear Algebra project for Horner's method

/*
1.	Write a program that can be used to solve all real zeros to a fourth-degree polynomial function to within 10^-10 using Horner’s method.
You may write your program in Python or a C-language.
Write the program in such a way that you can input (or enter into the code) the polynomial expression.
 
2.	Meet with Prof. Leininger and show him how your program works.
He will provide two 4th degree polynomials and ask you for solutions.
Your code needs to be based on Horner’s method, can use the quadratic formula to determine the last two roots,
does not need to find imaginary solutions, and should correct your approximations with Horner’s method.  
*/

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

//Function headers
long double * getFunction();
void displayFunction(long double * function);


int main()
{
	//Get the 4th degree polynomial from the user
	long double * func;
	func = getFunction();
	
	cout<<"\n"<<endl;
	cout<<"Is this the function you want to use?"<<endl;
	displayFunction(func);
	cout<<"Type 'y' or 'n': ";
	char use;
	cin>>use;
	cout<<endl;
	
	while (use == 'n')
	{	
		cout<<"Okay, let's try entering the function again."<<endl;
		cout<<"\n"<<endl;
		func = getFunction();
		
		cout<<"\n"<<endl;
		cout<<"Is this the function you want to use?"<<endl;
		displayFunction(func);
		cout<<"Type 'y' or 'n': ";
		cin>>use;
		cout<<endl;
	}
	
	cout<<"\nAlright then, let's get started!"<<endl;
	
	cout<<"\nSearching for solutions . . ."<<endl;
	cout<<"This will only take a few seconds!\n"<<endl;
	
	long double coefficients[5];
	long double x = 1; //make x our original guess
	long double prevX = x + 1;
	long double foo;
	int counter = 0;
	
	//While loop for while our solution is not yet within 10^-10 we keep going
	while (((prevX - x) > 0.0000000001) || ((x - prevX) > 0.0000000001))
	{
		prevX = x;
		
		for (int i = 0; i < 5; i++)
		{coefficients[i] = func[i];}
		
		coefficients[1] += x * coefficients[0];
		coefficients[2] += x * coefficients[1];
		coefficients[3] += x * coefficients[2];
		coefficients[4] += x * coefficients[3];
		
		foo = x * coefficients[0] + coefficients[1];
		foo = x * foo + coefficients[2];
		foo = x * foo + coefficients[3];
		
		x -= coefficients[4] / foo;
		
		counter++;
		if (counter > 10000)
		{
			cout<<"Uh oh! It looks like there are no real solutions..."<<endl;
			cout<<"Solution 1: Imaginary Number"<<endl;
			cout<<"Solution 2: Imaginary Number"<<endl;
			cout<<"Solution 3: Imaginary Number"<<endl;
			cout<<"Solution 4: Imaginary Number"<<endl;
			break;
		}
	}
	//use the method and then asign the result to x and then our loop will go again
	//end while loop
	
	//Save x as an answer and one of our roots.
	long double solutions[4];
	solutions[0] = x;
	
	//Now get the other roots and determine how many imaginary solutions there are.
	prevX = x + 1;
	long double coefficients2[4];
	
	if (counter < 10001) //We are only looking for another solution if there is one
	{
		//While loop for while our solution is not yet within 10^-10 we keep going
		while (((prevX - x) > 0.0000000001) || ((x - prevX) > 0.0000000001))
		{
			prevX = x;
			
			for (int i = 0; i < 4; i++)
			{coefficients2[i] = coefficients[i];}
			
			coefficients2[1] += x * coefficients2[0];
			coefficients2[2] += x * coefficients2[1];
			coefficients2[3] += x * coefficients2[2];
			
			foo = x * coefficients2[0] + coefficients2[1];
			foo = x * foo + coefficients2[2];
			
			x -= coefficients2[3] / foo;
		}
		
		solutions[1] = x;
		
		//Now we use quadratic to get the last two solutions (or get if they are imaginary)
		long double a = coefficients2[0];
		long double b = coefficients2[1];
		long double c = coefficients2[2];
		
		long double innerSqrt = b*b - 4*a*c;
		
		if (innerSqrt >= 0)
		{
			solutions[2] = (-b + sqrt(innerSqrt))/(2*a);
			solutions[3] = (-b - sqrt(innerSqrt))/(2*a);
		}
		
		
		cout<<fixed<<setprecision(10)<<endl;
		int k = 4;
		if (innerSqrt < 0)
		{k = 2;}

		for (int i = 0; i < k; i++)
		{
			cout<<"Solution "<<(i + 1)<<": "<<solutions[i]<<endl;
		}
		
		if (innerSqrt < 0)
		{
			cout<<"Soltuion 3: Imaginary Number"<<endl;
			cout<<"Soltuion 4: Imaginary Number"<<endl;
		}
	}

	
}




//Function definition for getFunction
long double * getFunction()
{
	cout<<"Please enter a 4th degree polynomial function."<<endl;
	cout<<"Example: To enter 3x^4 + x^3 -3.4x + 17, you would type 3 1 0 -3.4 17  and then press enter."<<endl;
	cout<<"Notice each entry is separated by a single space."<<endl;
	cout<<"Please enter your function coefficients: ";
	long double a, b, c, d, e;
	cin>>a>>b>>c>>d>>e;
	static long double function[5];
	function[0] = a;
	function[1] = b;
	function[2] = c;
	function[3] = d;
	function[4] = e;
	return function;
}

void displayFunction(long double * function)
{
	cout<<"f(x) = "; //Print begining of line
	
	//If the first coefficient is 1 we have the special case
	if (function[0] == 1)
	{
		cout<<"x^4"<<" ";
	}
	//Now if the first coefficient is not 0 we will print it
	else if (function[0] != 0)
	{
		cout<<function[0]<<"x^4"<<" ";
	}
	
	//If the second coefficient is 1 we have the special case
	if (function[1] == 1)
	{
		cout<<"+ x^3"<<" ";
	}
	//Now if the second coefficient is not 0 we will print it
	else if (function[1] != 0)
	{
		(function[1] > 0)?(cout<<"+ "):(cout<<"");
		cout<<function[1]<<"x^3"<<" ";
	}
	
	//If the third coefficient is 1 we have the special case
	if (function[2] == 1)
	{
		cout<<"+ x^3"<<" ";
	}
	//Now if the third coefficient is not 0 we will print it
	else if (function[2] != 0)
	{
		(function[2] > 0)?(cout<<"+ "):(cout<<"");
		cout<<function[2]<<"x^2"<<" ";
	}
	
	//If the fourth coefficient is 1 we have the special case
	if (function[3] == 1)
	{
		cout<<"+ x"<<" ";
	}
	//Now if the fourth coefficient is not 0 we will print it
	else if (function[3] != 0)
	{
		(function[3] > 0)?(cout<<"+ "):(cout<<"");
		cout<<function[3]<<"x"<<" ";
	}
	
	//If the fifth coefficient is positive
	if (function[4] > 0)
	{
		cout<<"+ "<<function[4]<<endl;
	}
	else if (function[4] < 0) //else if the fifth coefficient is negative
	{
		cout<<function[4]<<endl;
	}
	else
	{
		//funcion[4] was equal to 0 so we print nothing
	}
	
	//Special case of an empty function
	if ((function[0] == 0) && (function[1] == 0) && (function[2] == 0) && (function[3] == 0) && (function[4] == 0))
	{
		cout<<"0"<<endl;
	}
}
