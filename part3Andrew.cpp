//Integer printing program by Andrew Brown 3/03/2019
//Program for homework assignment 4

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	//Declaring and initializing the counter to be used for the while loop
	unsigned int x{1};
	
	//Looping with "while" 20 times to print out the integers 1 through 20
	while (x <= 20)
	{
		cout<<x;
		
		//Selection statement to space out the integers and return to a new line every 5 integers
		if ((x % 5) == 0)
		{
			cout<<endl;
		}
		else
		{
			cout<<"\t";
		}
		
		//Increaing the counter
		x++;
	}
	
	//Looping with "for" 20 times to print out the integers 1 through 20
	for (unsigned int i = 1; i <= 20; i++)
	{
		cout<<i;
		
		//Selection statement to space out the integers and return to a new line every 5 integers
		if ((i % 5) == 0)
		{
			cout<<endl;
		}
		else
		{
			cout<<"\t";
		}
	}
	
return (0);
}