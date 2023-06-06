//Program to test try, throw, and catch

#include <iostream>
#include <string>

using namespace std;

//Function headers
int getIntegerFromUser(int);

int main() {

int num1, num2;
num1 = num2 = 0;
int sum = 0;


cout << "Enter two numbers to be added together!" << endl;
cout << "First number: ";

num1 = getIntegerFromUser(num1);

cout << "Second number: ";
num2 = getIntegerFromUser(num2);

sum = num1 + num2;

cout << endl;
cout << "The sum is: " << sum << endl;



return 0;

}

//Function definitions
int getIntegerFromUser(int x){
	
	bool isInt = false;
	string input;
	string accepted_values = "0123456789";
	
	while (!isInt) {
		
		try {
			
			cin >> input;
			
			for (int i = 0; i < input.length(); i++){
				if (accepted_values.find(input[i]) == string::npos){
					throw "The user entered something other than an integer and only an integer.";
				}
			}
			
			x = stoi(input); //This will throw an exception if data entered is not an int
			
			isInt = true; //If no exceptions are thrown then we get here
			
		} catch(...){
			
			isInt = false;
			cout << "Hm that doesn't work... Please enter an integer: ";
		}
	}
	return x;
}
