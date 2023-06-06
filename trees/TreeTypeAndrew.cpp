
#include "TreeTypeAndrew.h"
struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

bool TreeType::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

int CountNodes(TreeNode* tree);

int TreeType::GetLength() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
  return CountNodes(root);
}


int CountNodes(TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else 
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found);

ItemType TreeType::GetItem(ItemType item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
  return item;
}


void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)      
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
  else
  {
    item = tree->info;                 // item is found.
    found = true;
   }
} 

void Insert(TreeNode*& tree, ItemType item);

void TreeType::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}


void Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
} 
void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, ItemType item);

void TreeType::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
  Delete(root, item);
}


void Delete(TreeNode*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}   

void GetPredecessor(TreeNode* tree, ItemType& data);

void DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
  }
}

void GetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

void PrintTree(TreeNode* tree, std::ofstream& outFile) 
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
    PrintTree(tree->left, outFile);   // Print left subtree.
    outFile << tree->info;
    PrintTree(tree->right, outFile);  // Print right subtree.
  }
}

void TreeType::Print(std::ofstream& outFile) const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root, outFile);
}

TreeType::TreeType()
{
  root = NULL;
}

void Destroy(TreeNode*& tree);

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}


void Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}


void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree);

TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
  CopyTree(root, originalTree.root);
}

void TreeType::operator= 
     (const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{
  {
  if (&originalTree == this)
    return;             // Ignore assigning self to self
  Destroy(root);      // Deallocate existing tree nodes
  CopyTree(root, originalTree.root);
  }

}
void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate 
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}
// Function prototypes for auxiliary functions.

void PreOrder(TreeNode*, QueType&);
// Enqueues tree items in preorder.


void InOrder(TreeNode*, QueType&);
// Enqueues tree items in inorder.


void PostOrder(TreeNode*, QueType&);
// Enqueues tree items in postorder.


void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
  switch (order)
  {
    case PRE_ORDER : PreOrder(root, preQue);
                     break;
    case IN_ORDER  : InOrder(root, inQue);
                     break;
    case POST_ORDER: PostOrder(root, postQue);
                     break;
  }
}


void PreOrder(TreeNode* tree, 
     QueType& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}


void InOrder(TreeNode* tree, 
     QueType& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}


void PostOrder(TreeNode* tree, 
     QueType& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}


ItemType TreeType::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
  finished = false;
  ItemType item;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
  return item;
}




/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
New functions added by Andrew for program3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/



int CountLeaves(const TreeNode* tree); //Function header for helper function to LeafCount

int TreeType::LeafCount() //Member fucnction returns an integer describing the number of leaves the tree has that called the funciton.
{
	//Call helper function to count the leaves
	return CountLeaves(root);
} //end LeafCount

//LeafCount's helper function definition
int CountLeaves(const TreeNode* tree)
{
	//Base case 1: when the node is null it is not a leaf so we return 0.
	if (tree == NULL)
	{return 0;}

	//Base case 2: when the node has no children it is a leaf so we return 1.
	else if ((tree->left == NULL) && (tree->right == NULL))
	{return 1;}

	//Recursive call that adds a sum of all the leaves in the tree.
	else
	{return (CountLeaves(tree->left) + CountLeaves(tree->right));}
} //end CountLeaves



int CountSP(const TreeNode* tree); //Function header for helper function to SingleParentCount

int TreeType::SingleParentCount() //Member function returns an integer describing the number of nodes with only one child in the tree that called the function.
{
	//Call helper function to count the single parents
	return CountSP(root);
} //end SingleParentCount

//SingleParentCount's helper function definition
int CountSP(const TreeNode* tree)
{
	//Base case: when the node is null it is not a single parent so we return 0.
	if (tree == NULL)
	{return 0;}

	//Recursive call 1: when the node has no left child, but has a right child, it is a single parent so we return 1 + (the number of single parents in the right sub tree).
	else if ((tree->left == NULL) && (tree->right != NULL))
	{return (1 + CountSP(tree->right));}

	//Recursive call 2: when the node has a left child, but no right child, it is a single parent so we return 1 + (the number of single parents in the left sub tree).
	else if ((tree->left != NULL) && (tree->right == NULL))
	{return (1 + CountSP(tree->left));}

	//Recursive call 3: else the node has 0 or 2 children so we return the sum of the single parents in the left sub tree and the single parents in the right sub tree.
	else
	{return (CountSP(tree->left) + CountSP(tree->right));}
} //end CountSP



void Compare(const TreeNode* tree1, const TreeNode* tree2, bool& same); //Function header for helper function to SimilarTrees

bool TreeType::SimilarTrees(const TreeType& tree1, const TreeType& tree2) //Member function returns true if the two trees passed have the same structure, otherwise returns false.
{
	bool same = true; //boolean starts true, and compare will update it to false if it finds a structural difference in the trees.
	
	//Call helper function to compare the trees
	Compare(tree1.root, tree2.root, same);
	
	return same;
} //end SimilarTrees

int Status(const TreeNode* tree); //Function header for helper function to Compare

//SimilarTrees's helper function definition //The basic idea behind Compare is to traverse both trees using Pre-Order simultaneously, and update a boolean passed by reference if a structural difference is found.
void Compare(const TreeNode* tree1, const TreeNode* tree2, bool& same)
{
	if ((tree1 != NULL) || (tree2 != NULL))	//If at least one of the trees is not null //Note: If both trees were null they would be the same, and we would be done traversing the branch, so same would not need to be updated and no further function calls are needed.
	{
		if (Status(tree1) != Status(tree2)) //If the current node in tree1 has a different structure than the current node in tree2, same is updated to false.
		{same = false;}
		//Note: As soon as a structural difference is found, and same is set to false, there will be no more function calls because there does not need to be more than one difference for the whole tree to be proven not similar.
		
		if (same == true) //If no structural difference has been found yet
		{Compare(tree1->left, tree2->left, same);} //Recursive call to compare the left child in tree1 to the left child in tree2
		
		if (same == true) //If no structural difference has been found yet
		{Compare(tree1->right, tree2->right, same);} //Recursive call to compare the right child in tree1 to the right child in tree2
	}
} //end Compare

//Compare's helper function definition
int Status(const TreeNode* tree) //Helper function returns an integer describing the structure of the tree only at the node passed.
{
	//If the node is null
	if (tree == NULL)
	{return -1;}

	//Else if the node has no children
	else if ((tree->left == NULL) && (tree->right == NULL))
	{return 0;}

	//Else if the node has a left child but no right child
	else if ((tree->left != NULL) && (tree->right == NULL))
	{return 1;}

	//Else if the node has no left child but has a right child
	else if ((tree->left == NULL) && (tree->right != NULL))
	{return 2;}

	//Else the node has both children
	else
	{return 3;}
} //end Status

