#include <iostream>
#include <cstring>

using namespace std;

class Tree {
public:
  char x;
  Tree* left;
  Tree* right;

  void setchar(char p);
  void setLeft(char p);
  void setRight(char p);

  char getchar();
  Tree* getLeft();
  Tree* getRight();

  Tree(char newvalue);
  ~Tree();
  
};
