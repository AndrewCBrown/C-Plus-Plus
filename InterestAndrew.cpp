//Interest program by Andrew Brown 2/25/2019
//Program to calculate Peter Minuit's investment return for Lab 6
#include <iostream>
#include <iomanip>
#include <string>
#include "DollarAmountAndrew.h"
using namespace std;

int main()
{
	//Declaring and initializing variables
	//These 6 variables are for storing the final amounts of money
	int64_t final_5{0};
	int64_t final_6{0};
	int64_t final_7{0};
	int64_t final_8{0};
	int64_t final_9{0};
	int64_t final_10{0};
	//These 6 variables are for the year peter breaks even
	unsigned int break_5{0};
	unsigned int break_6{0};
	unsigned int break_7{0};
	unsigned int break_8{0};
	unsigned int break_9{0};
	unsigned int break_10{0};

	//Looping through the 6 different interest rates
	for (int interest_rate = 5; interest_rate <= 10; interest_rate++)
	{
		//Declaring and initialzing variables that will only be used in the loop
		DollarAmount peter_investment{2400}; //initial principal amount in pennies
		unsigned int break_year{0};
		int checked{0};
		unsigned int divisor{100};
		
		//Printing to the screen
		cout<<"Initial principal: "<<peter_investment.toString()<<endl;
		cout<<"    Interest rate: "<<interest_rate<<"%"<<endl;
		cout<<"\nYear    Amount on deposit"<<endl;
		
		//Looping through the years starting at investment year and going through current
		for (unsigned int year = 1627; year <= 2019; year++)
		{
			peter_investment.addInterest(interest_rate, divisor);//Adding the interest earned for that year
			cout<<year<<"        "<<peter_investment.toString()<<endl;//Printing the current balance
			//If statement to check if peter has broken even yet. Statement will not execute if he has already broken even once
			if (peter_investment.getAmount() > 300000000000 && checked == 0)
			{
				break_year = year;
				checked = 1;
			}
		}
		//Switch to assign the values for to their corresponding variables
		switch (interest_rate)
		{
			case 5:
			final_5 = peter_investment.getAmount();
			break_5 = break_year;
			break;
			
			case 6:
			final_6 = peter_investment.getAmount();
			break_6 = break_year;
			break;
			
			case 7:
			final_7 = peter_investment.getAmount();
			break_7 = break_year;
			break;
			
			case 8:
			final_8 = peter_investment.getAmount();
			break_8 = break_year;
			break;
			
			case 9:
			final_9 = peter_investment.getAmount();
			break_9 = break_year;
			break;
			
			case 10:
			final_10 = peter_investment.getAmount();
			break_10 = break_year;
			break;
			
			default:
			cout<<"Program shouldn't have gotten here!"<<endl;
			break;
		}
		cout<<"\n\n\n"<<endl;
	}

	//Printing to the screen the synopsis
	cout<<"Here is the synopsis:\n"<<endl;
	cout<<"05% Year broke even - "<<break_5<<"  Amount - "<<final_5<<" cents"<<endl;
	cout<<"06% Year broke even - "<<break_6<<"  Amount - "<<final_6<<" cents"<<endl;
	cout<<"07% Year broke even - "<<break_7<<"  Amount - "<<final_7<<" cents"<<endl;
	cout<<"08% Year broke even - "<<break_8<<"  Amount - "<<final_8<<" cents"<<endl;
	cout<<"09% Year broke even - "<<break_9<<"  Amount - "<<final_9<<" cents"<<endl;
	cout<<"10% Year broke even - "<<break_10<<"  Amount - "<<final_10<<" cents"<<endl;

return(0);
}