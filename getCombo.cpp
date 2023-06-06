//Math Tutor Function for practicing any of the four main operations at random
//Andrew Brown

int getCombo(int x, int y){
	int operation;
	
	//Get a random number from 1 to 4
	int random_int;
	random_int = 1 + rand() % 4; //Assumption here that random has already been seeded in main program
	
	//Case to apply each method based on the random number choice
	switch (random_int)
	{
		case 1: //Addition
		cout << "\t" << x << " + " << y << " = ";
		operation = x + y;
		break;
		
		case 2: //Subtraction
		cout << "\t" << x << " - " << y << " = ";
		operation = x - y;
		break;
		
		case 3: //Multiplication
		cout << "\t" << x << " * " << y << " = ";
		operation = x * y;
		break;
		
		case 4: //Division
		cout << "\t" << x << " / " << y << " = ";
		operation = x / y;
		break;
		
		default:
		cout<<"Program encountered an error in regards to random number generation."<<endl;
		operation = 0;
		exit(1);
		break;
	}
	
	return operation;
}