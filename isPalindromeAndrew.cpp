//isPalindrome function by Andrew Brown 4/15/2019

#include <string.h>
using namespace std;

bool isPalindrome(char* theString)
{
	bool myBool = true;
	int length {0};
	length = strlen(theString);
	
	char* begPtr {theString};
	char* endPtr {&(theString[length - 1])};
	
	for (unsigned int i = 0; i < ((length % 2)? (length - 1)/2: length/2); i++)
	{
		if (*begPtr != *endPtr)
		{
			myBool = false;
			break;
		}
		begPtr++;
		endPtr--;
	}
	return myBool;
}