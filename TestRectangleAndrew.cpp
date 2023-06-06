//Test driver for Rectangle class by Andrew Brown 2/5/2019
//Program updated for Homework assignment 3 on 2/18/2019

#include<iostream>
#include<string>
#include<iomanip>
#include"RectangleAndrew.h"

using namespace std;

int main()
{
	//Explanatory greeting
	cout<<"Welcome to the Rectangle program. Please enter the dimensions for a rectangle when "<<
			"prompted.\nValid size ranges from 1 to 20 for length and width.\nThe program will "<<
			"end when you enter 0 for both the length and the width."<<endl;

	//Declaring and intializing variables for user input		
	int i_length{0};
	int i_width{0};
	
	//Loop to continue getting rectangles from user until user attempts to exit
	while (true)
	{
		//Get rectangle size from user
		cout<<"\nEnter the length of your rectangle: ";
		cin>>i_length;
		//Check to make sure input is valid, and if not, get correct input
		while (!(0 <= i_length and i_length < 21))
		{
			cout<<"Your input is invalid! Try a number between 0 and 21."<<endl;
			cout<<"Enter the length of your rectangle: ";
			cin>>i_length;
		}
		
		cout<<"\nEnter the width of your rectangle: ";
		cin>>i_width;
		//Check to make sure input is valid, and if not, get correct input
		while (!(0 <= i_width and i_width < 21))
		{
			cout<<"Your input is invalid! Try a number between 0 and 21."<<endl;
			cout<<"Enter the width of your rectangle: ";
			cin>>i_width;
		}
		
		//If user entered 0 and 0 (attempting to exit program) then break out of loop
		if (i_length == 0 and i_width == 0)
		{
			break;
		}
		
		//Create rectangle object
		Rectangle user(i_length, i_width);
		
		//Checking for only one 0 entered and giving error message but still proceeding
		if (i_length == 0 or i_width == 0)
		{
			cout<<"One of the values you entered for your rectangle dimensions was 0."<<endl;
			cout<<"This was an unexpected value because a rectangle with a dimension of 0 doesn't make sense."<<endl;
			cout<<"That value was changed to 1 so that the rectangle could still be evaluated."<<endl;
			cout<<"If you were trying to exit the program, try entering 0 for BOTH length and width."<<endl;
		}
		
		//Printing the attributes of the rectangle
		cout<<"\nYour rectangle's length is "<<user.getLength()<<endl;
		cout<<"Your rectangle's width is "<<user.getWidth()<<endl;
		cout<<"Your rectangle's perimeter is "<<user.getPerimeter()<<endl;
		cout<<"Your rectangle's area is "<<user.getArea()<<endl;
	}
	
	//Ending message
	cout<<"\nThank you for using the rectangle program!"<<endl;
	
return(0);
};

//Old code for testing the original program
//Kept here for quick testing should it ever be needed
	/*
	//Testing other functions with set values
	Rectangle master(5,6);
	cout<<"The test rectangle's length is "<<master.getLength()<<endl;
	cout<<"The test rectangle's width is "<<master.getWidth()<<endl;
	cout<<"The test rectangle's perimeter is "<<master.getPerimeter()<<endl;
	cout<<"The test rectangle's area is "<<master.getArea()<<endl;
	
	master.setLength(10);
	master.setWidth(4);
	cout<<"Changing test rectangle..."<<endl;
	cout<<"The test rectangle's length is "<<master.getLength()<<endl;
	cout<<"The test rectangle's width is "<<master.getWidth()<<endl;
	cout<<"The test rectangle's perimeter is "<<master.getPerimeter()<<endl;
	cout<<"The test rectangle's area is "<<master.getArea()<<endl;
	
	master.setLength(-5);
	master.setWidth(25);
	cout<<"The test rectangle's length is "<<master.getLength()<<endl;
	cout<<"The test rectangle's width is "<<master.getWidth()<<endl;
	cout<<"The test rectangle's perimeter is "<<master.getPerimeter()<<endl;
	cout<<"The test rectangle's area is "<<master.getArea()<<endl;
	*/