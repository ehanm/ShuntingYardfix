#include <cstring>
#include <iostream>
#include "tree.h"

using namespace std;

void Tree::setchar(char p){

  x = p;
  
}

void Tree::setLeft(char p){

  Tree* newleft = new Tree(p);
  left = newleft;
  
}

void Tree::setRight(char p){

  Tree* newright = new Tree(p);
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

  right = NULL;
  left = NULL;
  x = newvalue;
  
  
}
