//Read in the three trees, print them, then print all 3 traversals for each tree.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "TreeType.h"

using namespace std;

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  
  char item;
  TreeType tree[3];
  bool finished;
  int length;

  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;


  for (int i = 0; i < 3; i++)
  {
	  inFile >> length;
	  
	  for (int j = 0; j < length; j++)
	  {
		  inFile >> item;
		  tree[i].PutItem(item);
		  outFile << item;
		  outFile << " is inserted" << endl;
	  }
  }
  outFile << endl;
  
  //Use the print function on each tree
  outFile << "Printing first tree..." <<endl;
  tree[0].Print(outFile);
  outFile << endl;
  
  outFile << "Printing second tree..." <<endl;
  tree[1].Print(outFile);
  outFile << endl;
  
  outFile << "Printing third tree..." <<endl;
  tree[2].Print(outFile);
  outFile << endl;
  
  //Display all three traversal methods for each tree
  for (int i = 0; i < 3; i++)
  {
	  outFile << endl;
	  length = tree[i].GetLength();
	  
	  //Pre-Order traversal
	  tree[i].ResetTree(PRE_ORDER);
	  outFile << "Pre-Order traversal of tree "<<(i + 1)<<": ";
	  for (int foo = 0; foo < length; foo++)
	  {
		  item = tree[i].GetNextItem(PRE_ORDER, finished);
		  outFile << item;
	  }
	  outFile << endl;
	  
	  //In-Order traversal
	  tree[i].ResetTree(IN_ORDER);
	  outFile << "In-Order traversal of tree "<<(i + 1)<<": ";
	  for (int foo = 0; foo < length; foo++)
	  {
		  item = tree[i].GetNextItem(IN_ORDER, finished);
		  outFile << item;
	  }
	  outFile << endl;
	  
	  //Post-Order traversal
	  tree[i].ResetTree(POST_ORDER);
	  outFile << "Post-Order traversal of tree "<<(i + 1)<<": ";
	  for (int foo = 0; foo < length; foo++)
	  {
		  item = tree[i].GetNextItem(POST_ORDER, finished);
		  outFile << item;
	  }
	  outFile << endl;
  }
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
}