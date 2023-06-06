//This is the test driver for program 3
//The only thing I changed in QueType.h was the typedef from char to int
//The only thing I changed in QueType.cpp was the #include for the name of QueType.h to QueTypeAndrew.h

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "TreeTypeAndrew.h"

using namespace std;

//Client function headers
int NumberOfNodesLessThan(TreeType& tree, int number);
void MakeTree(TreeType& tree, const int* list, const int size);
bool MatchingItems(TreeType& tree, const int* list, const int size);

int main()
{

  ofstream outFile;      // file containing output
  string outFileName;    // output file external name
  string outputLabel;     
  
  int item;
  int length;
  bool finished;
  TreeType foo;
  
  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;
  
  /*
  Test Driver trees:
  tree_01: 5, 3, 2, 1, 4, 8, 7, 6, 9
  tree_01 has 4 leaf nodes, and 2 single parents

  tree_02: 14, 12, 11, 10, 13, 17, 16, 15, 18
  tree_02 has 4 leaf nodes, and 2 single parents

  tree_01 and tree_02 have the same structure.

  tree_03: 5, 2, 1, 3, 4, 7, 6, 8, 9

  tree_01 and tree_03 both have the same number of nodes, leaf nodes, and single parents, but they do not have the same structure.

  tree_04: 1, 2, 3, 4
  tree_04 has 1 leaf node, and 3 single parents

  list_01: 1, 2, 3, 4, 5, 6, 7, 8, 9
  list_02: 1, 2, 3, 4, 5, 6, 7, 8, 10
  list_03: 10, 11, 12, 13, 14, 15, 16, 17, 18
  list_01 has the same items as tree_01
  list_02 and list_03 do not have the same items as tree_01
  */
  outFile << "Building Trees for testing . . ." << endl;
  outFile << "\n";
  
  //Build tree_01
  int tree_01Contents[9] = {5, 3, 2, 1, 4, 8, 7, 6, 9};
  TreeType tree_01;
  for (int i = 0; i < 9; i++)
  {
	  item = tree_01Contents[i];
	  tree_01.PutItem(item);
	  outFile << item;
      outFile << " is inserted to tree_01" << endl;
  }
  outFile << "\n";
  
  //Build tree_02
  int tree_02Contents[9] = {14, 12, 11, 10, 13, 17, 16, 15, 18};
  TreeType tree_02;
  for (int i = 0; i < 9; i++)
  {
	  item = tree_02Contents[i];
	  tree_02.PutItem(item);
	  outFile << item;
      outFile << " is inserted to tree_02" << endl;
  }
  outFile << "\n";
  
  //Build tree_03
  int tree_03Contents[9] = {5, 2, 1, 3, 4, 7, 6, 8, 9};
  TreeType tree_03;
  for (int i = 0; i < 9; i++)
  {
	  item = tree_03Contents[i];
	  tree_03.PutItem(item);
	  outFile << item;
      outFile << " is inserted to tree_03" << endl;
  }
  outFile << "\n";
  
  //Build tree_04
  int tree_04Contents[4] = {1, 2, 3, 4};
  TreeType tree_04;
  for (int i = 0; i < 4; i++)
  {
	  item = tree_04Contents[i];
	  tree_04.PutItem(item);
	  outFile << item;
      outFile << " is inserted to tree_04" << endl;
  }
  outFile << "\n";
  
  outFile << "The lists for testing are:" << endl;
  outFile << "list_01: 1, 2, 3, 4, 5, 6, 7, 8, 9" << endl;
  outFile << "list_02: 1, 2, 3, 4, 5, 6, 7, 8, 10" << endl;
  outFile << "list_03: 10, 11, 12, 13, 14, 15, 16, 17, 18" << endl;
  int list_01[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int list_02[9] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
  int list_03[9] = {10, 11, 12, 13, 14, 15, 16, 17, 18};
  outFile << "\n";

  
  //Test the 3 member functions
  //Test LeafCount
  outFile << "tree_01 has " << tree_01.LeafCount() << " leaves." << endl;
  outFile << "tree_02 has " << tree_02.LeafCount() << " leaves." << endl;
  outFile << "tree_03 has " << tree_03.LeafCount() << " leaves." << endl;
  outFile << "tree_04 has " << tree_04.LeafCount() << " leaves." << endl;
  outFile << "Was expecting 4, 4, 4, 1" << endl;
  outFile << "\n";

  //Test SingleParentCount
  outFile << "tree_01 has " << tree_01.SingleParentCount() << " single parent nodes." << endl;
  outFile << "tree_02 has " << tree_02.SingleParentCount() << " single parent nodes." << endl;
  outFile << "tree_03 has " << tree_03.SingleParentCount() << " single parent nodes." << endl;
  outFile << "tree_04 has " << tree_04.SingleParentCount() << " single parent nodes." << endl;
  outFile << "Was expecting 2, 2, 2, 3" << endl;
  outFile << "\n";
  
  //Test SimilarTrees
  outFile << "tree_01 " << (foo.SimilarTrees(tree_01, tree_01)?"has":"does not have") << " the same structure as tree_01." << endl;
  outFile << "tree_01 " << (foo.SimilarTrees(tree_01, tree_02)?"has":"does not have") << " the same structure as tree_02." << endl;
  outFile << "tree_01 " << (foo.SimilarTrees(tree_01, tree_03)?"has":"does not have") << " the same structure as tree_03." << endl;
  outFile << "tree_01 " << (foo.SimilarTrees(tree_01, tree_04)?"has":"does not have") << " the same structure as tree_04.\n" << endl;
  outFile << "tree_02 " << (foo.SimilarTrees(tree_02, tree_01)?"has":"does not have") << " the same structure as tree_01." << endl;
  outFile << "tree_02 " << (foo.SimilarTrees(tree_02, tree_02)?"has":"does not have") << " the same structure as tree_02." << endl;
  outFile << "tree_02 " << (foo.SimilarTrees(tree_02, tree_03)?"has":"does not have") << " the same structure as tree_03." << endl;
  outFile << "tree_02 " << (foo.SimilarTrees(tree_02, tree_04)?"has":"does not have") << " the same structure as tree_04.\n" << endl;
  outFile << "tree_03 " << (foo.SimilarTrees(tree_03, tree_01)?"has":"does not have") << " the same structure as tree_01." << endl;
  outFile << "tree_03 " << (foo.SimilarTrees(tree_03, tree_02)?"has":"does not have") << " the same structure as tree_02." << endl;
  outFile << "tree_03 " << (foo.SimilarTrees(tree_03, tree_03)?"has":"does not have") << " the same structure as tree_03." << endl;
  outFile << "tree_03 " << (foo.SimilarTrees(tree_03, tree_04)?"has":"does not have") << " the same structure as tree_04.\n" << endl;
  outFile << "tree_04 " << (foo.SimilarTrees(tree_04, tree_01)?"has":"does not have") << " the same structure as tree_01." << endl;
  outFile << "tree_04 " << (foo.SimilarTrees(tree_04, tree_02)?"has":"does not have") << " the same structure as tree_02." << endl;
  outFile << "tree_04 " << (foo.SimilarTrees(tree_04, tree_03)?"has":"does not have") << " the same structure as tree_03." << endl;
  outFile << "tree_04 " << (foo.SimilarTrees(tree_04, tree_04)?"has":"does not have") << " the same structure as tree_04.\n" << endl;
  outFile << "Was expecting same, same, different, different" << endl;
  outFile << "same, same, different, different" << endl;
  outFile << "different, different, same, different" << endl;
  outFile << "different, different, different, same" << endl;
  outFile << "\n";
  
  
  //Testing the 3 client functions
  //Test NumberOfNodesLessThan
  outFile << "tree_01 has " << NumberOfNodesLessThan(tree_01, 1) << " nodes that are less than 1." << endl;
  outFile << "tree_01 has " << NumberOfNodesLessThan(tree_01, 6) << " nodes that are less than 6." << endl;
  outFile << "tree_01 has " << NumberOfNodesLessThan(tree_01, 10) << " nodes that are less than 10." << endl;
  outFile << "Was expecting 0, 5, 9." << endl;
  outFile << "\n";
  
  //Test MakeTree
  outFile << "Creating tree using this list: 1, 2, 3, 4, 5, 6, 7, 8, 9 . . ." << endl;
  
  TreeType newTree;
  MakeTree(newTree, list_01, (sizeof(list_01)/sizeof(*list_01)));
  
  length = newTree.GetLength();
  
  newTree.ResetTree(PRE_ORDER);
  outFile << "Pre-order traversing the new tree gives : ";
  for (int i = 0; i < length; i++)
  {outFile << newTree.GetNextItem(PRE_ORDER, finished) << ", ";}
  outFile << endl;
  outFile << "Was expecting 5, 3, 2, 1, 4, 8, 7, 6, 9." << endl;
  outFile << "\n";
  
  //Test MatchingItems
  outFile << "tree_01 " << (MatchingItems(tree_01, list_01, (sizeof(list_01)/sizeof(*list_01)))?"has":"does not have") << " the same items as list_01." << endl;
  outFile << "tree_01 " << (MatchingItems(tree_01, list_02, (sizeof(list_02)/sizeof(*list_02)))?"has":"does not have") << " the same items as list_02." << endl;
  outFile << "tree_01 " << (MatchingItems(tree_01, list_03, (sizeof(list_03)/sizeof(*list_03)))?"has":"does not have") << " the same items as list_03." << endl;
  outFile << "Was expecting same, different, different." << endl;
  

  
  outFile << endl;
  cout << "Testing completed."  << endl;
  outFile.close();
  return 0;
}



//NumberOfNodesLessThan function definition
int NumberOfNodesLessThan(TreeType& tree, int number) //Function returns an integer describing the number of nodes in the tree argument that are less than the integer argument.
{
	int quantityOfNodesLessThanNumber = 0;
	int item;
	bool finished = false;
	tree.ResetTree(IN_ORDER);
	
	while (finished == false) //Traverse the whole tree
	{
		item = tree.GetNextItem(IN_ORDER, finished);
		if (item < number) //If the current node's data value is less than the integer argument we add 1 to quantityOfNodesLessThanNumber
		{quantityOfNodesLessThanNumber++;}
		/*If I stop traversing the tree early, like once I know all the rest will be greater it makes future
		traversals of the same tree not work for some reason because of how the original ADT is made.
		So I lose efficiency here but not much.*/
	}
	return quantityOfNodesLessThanNumber;
}

void Create(TreeType& tree, const int* list, const int size); //Header for helper function to MakeTree

//MakeTree function definition
void MakeTree(TreeType& tree, const int* list, const int size) //Function takes a tree argument by reference, empties it, and makes it a new tree using the list argument passed.
//MakeTree assumes the list passed to be sorted from least to greatest
//	The tree will be constructed so that the number of levels in the tree will be as small as possible.
{
	tree.MakeEmpty();
	
	//Call helper function for Make Tree
	Create(tree, list, size);
}

//Helper function definition for MakeTree
void Create(TreeType& tree, const int* list, const int size)
//The concept of Create is to take a list, add the middle element to the tree, then split the list into a left list and a right list
//	and recursively call Create on the left list and the right list until the base case occurs which is a list with only one element.
{	
	if (size == 1) //If the list passed has only one item, it gets added to the tree.
	{tree.PutItem(list[0]);}
	
	else
	{
		int middle;
		
		if (size%2 == 1) //if the list has an odd number of elements
		{middle = (size - 1) / 2;}
		else //else the list has an even number of elements
		{middle = size / 2;}
		
		//Put the item in the middle of the list into the tree
		tree.PutItem(list[middle]);
		
		//Split the original list into two pieces, leftList and rightList
		int leftList[middle];
		for (int i = 0; i < middle; i++)
		{leftList[i] = list[i];}
	
		int rightList[size - middle - 1];
		for (int i = 0; i < (size - middle - 1); i++)
		{rightList[i] = list[i + middle + 1];}
		
		//Recursively call Create on the left list
		Create(tree, leftList, middle);
		if (size > 2) //If the big list had more than 2 elements, the right list will not be empty so we recursively call Create on the right list
		{Create(tree, rightList, size - middle - 1);}
	}
}

bool MatchingItems(TreeType& tree, const int* list, const int size) //Function returns true if the tree argument contains every element that is in the list argument. 
//The concept of MatchingItems is to assume the tree contains everything in the list, then traverse the list and update matches to false if an item in the list is not found in the tree.
{
	bool matches = true;
	
	//If the number of nodes in the tree differs from the number of elements in the list we immediately know the tree and list don't contain the same items.
	//	this also accounts for the case where the tree may contain every element that the list does, but have additional elements.
	if (size != tree.GetLength())
	{matches = false;}

	int counter = 0;
	bool found;
	
	//Traverse the list
	while ((counter < size) && matches) //Traversal will end if an item in the list is not found in the tree. This saves time by not requiring the traversal of the entire list.
	{
		tree.GetItem(list[counter], found);
		if (!found) //If the item in the list is not found in the tree matches is updated to false.
		{matches = false;}
	
		counter++;
	}
	return matches;
}

