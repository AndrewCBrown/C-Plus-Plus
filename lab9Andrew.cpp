//Array program by Andrew Brown 3/25/2019
//Program created for lab9 to read in 20 unique numbers to an array and then print them back out

#include<iostream>
#include<iomanip>
#include<string>
#include<array>
#include<algorithm>
using namespace std;

int main()
{
	//Declare and initialize variables
	int number{0}; //To be entered by user
	const size_t arraySize{20}; //Size of array
	array<int, arraySize> my_array{}; //Creates the empty array
	
	//Loop 20 times to get user input
	for (unsigned int i=0; i<arraySize; i++)
	{
		cout<<"\nPlease enter a number between 0 and 101 :";
		cin>>number;
		//Selection statement will run if number is between 0-101 and is not already in the array
		if ((number > 0 && number < 101) && !(binary_search(my_array.begin(), my_array.end(), number)))
		{
			//Add number to array
			my_array[0]=number;
			//Sort array
			sort(my_array.begin(), my_array.end());
		}
	}
	
	//Loop 20 times to print the valid array values
	for (unsigned int i=0; i<arraySize; i++)
	{
		//Selection statement will run if the value in the array is not 0
		if (my_array[i] != 0)
		{
			cout<<my_array[i]<<endl;
		}
	}
return(0);
}