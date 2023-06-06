//Tweleve Days of Christmas song program by Andrew Brown 2/18/2019

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

main()
{
	string day=""; //Initializing day variable
	
	//Loop through all 12 days of christmas
	for (unsigned int i=1; i <= 12 ;i++)
	{
		//Block to set which day will be printed
		switch (i)
		{
			case 12:
			day="twelfth";
			break;
			
			case 11:
			day="eleventh";
			break;
			
			case 10:
			day="tenth";
			break;
			
			case 9:
			day="ninth";
			break;
			
			case 8:
			day="eigth";
			break;
			
			case 7:
			day="seventh";
			break;
			
			case 6:
			day="sixth";
			break;
			
			case 5:
			day="fifth";
			break;
			
			case 4:
			day="fourth";
			break;
			
			case 3:
			day="third";
			break;
			
			case 2:
			day="second";
			break;
			
			case 1:
			day="first";
			break;
		}
			
		cout<<"\nOn the "<<day<<" day of Christmas,\nMy true love gave to me:"<<endl;
		
		//Block to print out the statements appropirate for the day
		switch (i)
		{
			case 12:
			cout << "\tTwelve drummers drumming,\n";
			
			case 11:
			cout << "\tEleven pipers piping,\n";
			
			case 10:
			cout << "\tTen lords a-leaping,\n";
			
			case 9:
			cout << "\tNine ladies dancing,\n";
			
			case 8:
			cout << "\tEight maids a-milking,\n";
			
			case 7:
			cout << "\tSeven swans a-swimming,\n";
			
			case 6:
			cout << "\tSix geese a-laying,\n";
			
			case 5:
			cout << "\tFive golden rings,\n";
			
			case 4:
			cout << "\tFour calling birds,\n";
			
			case 3:
			cout << "\tThree French hens,\n";
			
			case 2:
			cout << "\tTwo turtle doves, and\n";
			
			case 1:
			cout << "A partridge in a pear tree.\n";
			break;
		}
	}
return (0);
}