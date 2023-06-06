//Lab 10 by Andrew Brown 4/1/2019
//Program to get introduced to vectors

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
#include<stdexcept>
using namespace std;

int main()
{
	//Declare and initialize variables
	int number{0}; //To be entered by user
	vector<int> my_vector(0); //Creates a vector initialized to have 20 spots
	
	//Loop 20 times to get user input
	for (unsigned int i=0; i<20; i++)
	{
		cout<<"\nPlease enter a number between 0 and 101 :";
		cin>>number;
		//Selection statement will run if number is between 0-101 and is not already in the vector
		if ((number > 0 && number < 101) && !(binary_search(my_vector.begin(), my_vector.end(), number)))
		{
			//Add number to vector
			my_vector.push_back(number);
			//Sort vector
			sort(my_vector.begin(), my_vector.end());
		}
	}
	
	//Loop 20 times to print the valid vector values
	for (size_t i=0; i < my_vector.size(); i++)
	{
		//Selection statement will run if the value in the vector is not 0
		if (my_vector[i] != 0)
		{
			cout<<my_vector[i]<<endl;
		}
	}
return(0);
}

/*
Using the vector class in this program versus using the array class
was not much different. The main difference was initially declaring
the vector to be empty, and then pushing on a new value everytime
rather than assigning it to a location in the array.
I think vectors were a better fit for this assignment because the
vector size is only as big as necessary with the push_back
function.
*/