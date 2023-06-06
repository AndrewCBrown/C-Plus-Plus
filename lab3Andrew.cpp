//Lab 3 program by Andrew Brown 2/4/2019
// copy 10 numbers between files
// open the files
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{	
fstream infile("LAB3.data", ios::in);
fstream outfile1("BigOutput.data", ios::app);
fstream outfile2("MediumOutput.data", ios::app);
fstream outfile3("SmallOutput.data", ios::app);
int num;
for (int i = 1; i <= 10; i++)
{
	infile >> num;    // use the files
	if (num>=100)
	{
	outfile1 << num << endl; 
	}
	else if (num<=50)
	{
		outfile3 << num << endl;
	}
	else
	{
		outfile2 << num <<endl;
	}
}
infile.close();      // close the files
outfile1.close();
outfile2.close();
outfile3.close();

return 0;

};