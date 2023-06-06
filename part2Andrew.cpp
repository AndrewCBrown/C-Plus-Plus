//Pythagorean triple program by Andrew Brown 3/03/2019
//Program for homework assignment 4

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	//Declaring and initializing the variable that will keep track of the hypotenuse for the triangle in the loop
	float hippo{0};
	
	//Looping through all possible side1's
	for(unsigned int side1 = 1; side1 <= 499; side1++)
	{
		//Looping through all possible side2's
		for(unsigned int side2 = 1; side2 <= 499; side2++)
		{
			//Setting the hypotenuse for the current trianlge
			hippo = sqrt((side1 * side1) + (side2 * side2));
			
			//Selection statement to see if the current triangle is a pythagorean triple
			if ((hippo == floor(hippo)) && (hippo <= 500))
			{
				cout<<side1<<" by "<<side2<<" has hypotenuse "<<hippo<<endl;
			}
		}
	}
	
return(0);
}