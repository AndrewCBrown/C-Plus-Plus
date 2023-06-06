#include <iostream>
using namespace std;

void Unknown(int *p, int num);
void HardToFollow(int *p, int q, int *num);

void Unknown(int *p, int num) { //p should be a pointer to int, num should be an int
  int *q; //q is a pointer to type int

  q = &num; //q is set to the memory address of the temporary variable num
  *p = *q + 2; //whatever p was pointing to is now set to the value q was pointing at plus 2.
  num = 7; //the temporary variable num is set to 7.
  //nothing is returned so the only thing that changed was what p was pointing to.
}

void HardToFollow(int *p, int q, int *num) { //p should be a pointer to int, q is an int, and num is a pointer to int.
  *p = q + *num; //whatever p was pointing at now equals the value of q + the value of what num was pointing to.
  *num = q; //whatever num was pointing to is now the value of q.
  num = p; //num now points to the same thing p points to.
  p = &q; //p now points at the memory location of the temporary variable q.
  Unknown(num, *p); //first function is called with the int pointer num, and the value that p was pointing to.
  //nothing is returned so only what p and num were pointing to have been changed plus the call to Unknown()
}

main() {
  int *q; //q points to an int
  int trouble[3]; //trouble is an array of 3 ints

  trouble[0] = 1;
  q = &trouble[1]; //q now points to the 1 element in trouble.
  *q = 2; //trouble[1] = 2;
  trouble[2] = 3;
  //trouble is now {1, 2, 3}

  HardToFollow(q, trouble[0], &trouble[2]); //q points at trouble[1], literal int value 1, literal mem address of trouble[2]
  //trouble[1] = 4;
  //trouble[2] = 1;
  //Unknown(&trouble[1], literal:1)
	//trouble[1] = 3;
  Unknown(&trouble[0], *q); //(&trouble[0], literal: 3)(I think q still points at trouble[1] because even though it was passed into HardToFollow, that function just copied it for its local scope.)
  //trouble[0] = 5;

  cout << *q << " " << trouble[0] << " " << trouble[2]; //q poitns at trouble[1].
  //"3 5 1"
}