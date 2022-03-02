#include <cstring>
#include <iostream>
#include "tree.h"

using namespace std;

void Tree::setchar(char p){

  x = p;
  
}

void Tree::setLeft(Tree* newleft){

  left = newleft;
  
}

void Tree::setRight(Tree* newright){

  right = newright;
  
}

char Tree::getchar(){

  return x;

}

Tree* Tree::getLeft(){

  return left;
  
}

Tree* Tree::getRight(){

  return right;

}

Tree::Tree(char newvalue){

  x = newvalue;
  
  
}
