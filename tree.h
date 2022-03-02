#include <iostream>
#include <cstring>

using namespace std;

class Tree { // class to initialize the tree
public:
  char x;
  Tree* left;
  Tree* right;

  void setchar(char p);
  void setLeft(Tree* newleft);
  void setRight(Tree* newright);

  char getchar();
  Tree* getLeft();
  Tree* getRight();

  Tree(char newvalue);
  ~Tree();
  
};
