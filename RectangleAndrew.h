//Rectangle Class by Andrew Brown 2/05/2019
//Class for a rectangle
#include<iostream>

using namespace std;

class Rectangle
{
public:
	//Rectangle constructor
	Rectangle(int l, int w)
	: length{l}, width{w}
	{
	if (length < 1)
			length = 1;
	if (length > 20)
		length = 20;
	if (width < 1)
			width = 1;
	if (width > 20)
		width = 20;
	}
	
	//Function to calculate the perimeter
	int getPerimeter() const
	{
		return (2*length+2*width);
	}
	
	//Function to calculate the area
	int getArea() const
	{
		return (length*width);
	}
	
	//Function to get the length
	int getLength() const
	{
		return length;
	}
	
	//Function to get the width
	int getWidth() const
	{
		return width;
	}
	
	//Function to set the length
	void setLength(int len)
	{
		if (len>0 && len<21)//Verify input between 0 and 21
			length=len;
		else
			cout<<"Your input is not valid! Try an integer between 0 and 21"<<endl;
	}
	
	//Function to set the width
	void setWidth(int wid)
	{
		if (wid>0 && wid<21)//Verify input between 0 and 21
			width=wid;
		else
			cout<<"Your input is not valid! Try an integer between 0 and 21"<<endl;
	}
	
private:
	int length{1};
	int width{1};
};