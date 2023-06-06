#include <string>
#include <fstream>
typedef int ItemType;
struct TreeNode;
#include "QueTypeAndrew.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const; 
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  ItemType GetNextItem(OrderType order, bool& finished);
  void Print(std::ofstream& outFile) const;
  //These next three lines are the function headers for the member functions I added to the bottom of TreeType.cpp
  int LeafCount();
  int SingleParentCount();
  bool SimilarTrees(const TreeType& tree1, const TreeType& tree2);
private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

