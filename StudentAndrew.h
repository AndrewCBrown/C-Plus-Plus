//Student Class by Andrew Brown 2/03/2019
//Class for keeping information on a student object
#include<iostream>
#include<string>

class Student
{
public:
	//Student constructor
	Student(std::string fn, std::string ln, int y, std::string mj, int a, char g)
	: firstName{fn}, lastName{ln}, year{y}, major{mj}, age{a}, gender{g}
	{}
	
	//Set functions
	//Function that sets the student's first name
	void setFirstName(std::string  first_name)
	{
		firstName=first_name;
	}
	
	//Function that sets the student's last name
	void setLastName(std::string last_name)
	{
		lastName=last_name;
	}
	
	//Function that sets the year
	void setYear(int theYear)
	{
		year=theYear;
	}
	
	//Function that sets the student's major
	void setMajor(std::string theMajor)
	{
		major=theMajor;
	}
	
	//Function that sets the student's age
	void setAge(int theAge)
	{
		age=theAge;
	}
	
	//Function that sets the student's gender
	void setGender(char theGender)
	{
		gender=theGender;
	}
	
	//Get functions
	//Function that returns the student's first name
	std::string getFirstName() const
	{
		return firstName;
	}
	
	//Function that returns the student's last name
	std::string getLastName() const
	{
		return lastName;
	}
	
	//Function that returns the year
	int getYear() const
	{
		return year;
	}
	
	//Function that returns the student's major
	std::string getMajor() const
	{
		return major;
	}
	
	//Function that returns the student's age
	int getAge() const
	{
		return age;
	}
	
	//Function that returns the student's gender
	char getGender() const
	{
		return gender;
	}
	
	
	//Function that displays all attributes of the student object
	void displayStudent() const
	{
		std::cout<<firstName<<" "<<lastName<<" is a "<<age<<" year old ";
		if (gender=='m')
		{	
			std::cout<<"male";
		}
		else 
		{
			std::cout<<"female";
		}
		std::cout<<" in year "<<year<<" of a "<<major<<" major."<<std::endl;
	}
		
private:
	std::string firstName="Missing name";
	std::string lastName="Missing name";
	int year{0};
	std::string major="Missing major";
	int age{0};
	char gender='m';
};

	
	
	
	
	
	
	
	
	
	