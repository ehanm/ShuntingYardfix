#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"
using namespace std;
class Node {

 public:
  
  Node* getNext();
  void setChar(char y);

  Node* next;
  char x;



};
#endif
