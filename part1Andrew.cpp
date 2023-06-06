//Boolalpha program by Andrew Brown 3/03/2019
//Program for homework assignment 4

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	//Declaring and initializing variables
	int a{0};
	int b{0};
	int g{0};
	int i{0};
	int j{0};
	int x{0};
	int y{0};
	
	cout<<boolalpha<<endl;
	cout<<"Case a:\t\t\t!(x < 5) && !(y >= 7)\t"<<(!(x < 5) && !(y >= 7))<<endl;
	cout<<"Case a(rewritten):\t!((x < 5) || (y >= 7))\t"<<!((x < 5) || (y >= 7))<<endl;
	
	cout<<"Case b:\t\t\t!(a == b) || !(g != 5)\t"<<(!(a == b) || !(g != 5))<<endl;
	cout<<"Case b(rewritten):\t!((a == b) && (g != 5))\t"<<!((a == b) && (g != 5))<<endl;
	
	cout<<"Case c:\t\t\t!((x <= 8) && (y > 4))\t"<<!((x <= 8) && (y > 4))<<endl;
	cout<<"Case c(rewritten):\t!(x <= 8) || !(y > 4)\t"<<(!(x <= 8) || !(y > 4))<<endl;
	
	cout<<"Case d:\t\t\t!((i > 4) || (j <= 6))\t"<<!((i > 4) || (j <= 6))<<endl;
	cout<<"Case d(rewritten):\t!(i > 4) && !(j <= 6)\t"<<(!(i > 4) && !(j <= 6))<<endl;
	
return(0);
}