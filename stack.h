#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

struct Stack { // struck for stack

 public:

  Stack* prev;
  Stack* next = NULL;
  char x;

};

#endif
