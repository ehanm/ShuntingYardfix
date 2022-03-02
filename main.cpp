#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"
#include "tree.h"
// this is shunting yard, an algorithm that takes a basic numerical expression, converts it to postfix using a stack and a queue, and then converts it to prefix, postfix, and infix using the binary tree
// created by Ehan Masud, completed on 3/1/2022

using namespace std;

void push(char z, Stack* &head);
char peek(Stack* head);
void pop(Stack* &head);
void enqueue(char z, Queue* &head);
void dequeue(char z, Queue* &head);
void postfixqueue(Stack* &stack, Queue* &queue);
void printqueue(Queue* head);
void stackevaluate(Stack* &head, Queue* &qhead);
void newtree(char z, Stack* &head, Tree* &tree);
void printInfix(Tree* tree);
void printPostfix(Tree* tree);
void printPrefix(Tree* tree);

int main(){

  Stack* stackhead = NULL;
  Queue* queuehead = NULL;

  char input[100];
  char input2[100];

  cout << "Shunting Algorithm!" << endl;

  cout << "Enter a mathematical expression (make sure to include spaces): " << endl;

  cin.getline(input, 100);
  
  for (int i = 0; i < strlen(input); i++){

    if (input[i] == '('){
      
      push(input[i], stackhead);
      
    }
    
    if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^'){ // move to stack and queue
      char a = input[i];
      char c = peek(stackhead);
      
      if (stackhead == NULL) {
	
	push(a, stackhead);
	
      }
      
      else if (stackhead != NULL) {
	
	if (peek(stackhead) == '('){
	  
	  push(a, stackhead);
	  
	}
	else {
	  
	  pop(stackhead);
	  
	  push(a, stackhead);
	  enqueue(c, queuehead);
	  
	}
      }
      
    }

      else if (input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' ||
               input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9'){
	
        char b = input[i];
        enqueue(b, queuehead);
	
      }
      
      else if (input[i] == ')'){
        stackevaluate(stackhead, queuehead);
      }
  }
    
  Stack* newhead = NULL;
  
  postfixqueue(stackhead, queuehead);// move remaining stuff from stack to queue


  // prints out the tree
  cout << "Postfix before tree: ";
  printqueue(queuehead);
  cout << endl;
  


  // create the tree
  
  Tree* treehead = NULL;
  
  while (queuehead != NULL){
    char e = queuehead->x;
    if (e == '1' || e == '2' || e == '3' || e == '4' || e  == '5' ||
	e == '6' || e == '7' || e == '8' || e == '9') {      

      push(e, newhead);
      queuehead = queuehead->next;

      
    }
    else if (e == '+' || e == '-' || e == '*' || e == '/' || e == '^') {

      newtree(e, newhead, treehead);
      push(e, newhead);
      queuehead = queuehead->next;
      
    }

  }

  // print out the infix, prefix, and postfix from tree

  cout << "Infix after tree: ";
  printInfix(treehead);
  cout << endl;

  cout << "Prefix after tree: ";
  printPrefix(treehead);
  cout << endl;

  cout << "Postfix after tree: ";
  printPostfix(treehead);
  cout << endl;
  
  return 0;

}


void push(char z, Stack* &head) { // pushes to stack
  Stack* newpointer = new Stack();
  newpointer->x = z;
  newpointer->next = head;
  head = newpointer;
}

char peek(Stack* head) { //gets first thing added to stack
  char a;
  if (head != NULL){
    return head->x;
  }
  return a;
}

void pop(Stack* &head){ // removes thing from stack

  Stack* temp = head;
  head = head->next;
  delete temp;

}

void enqueue(char z, Queue* &head) { // adds to queue

  if (head == NULL){
    Queue* newpointer = new Queue();
    newpointer->x = z;
    head = newpointer;

  }

  else if (head->next == NULL) {
    Queue* newpointer = new Queue();
    newpointer->x = z;
    head->next = newpointer;

  }

  else {

    enqueue(z, head->next);

  }

}

void dequeue(char z, Queue* &head) {

}

void printqueue(Queue* head){ // prints

  if (head != NULL) {
    cout << head->x;
    printqueue(head->next);
  }
  else {
    return;
  }

}

void postfixqueue(Stack* &stack, Queue* &queue){ // moves everything in stack to queue

  while (stack != NULL){
    enqueue(stack->x, queue);
    stack = stack->next;
  }

}

void stackevaluate(Stack* &head, Queue* &qhead){ // adds to queue until opening parentheses found

  while (head->x != '('){

    enqueue(head->x, qhead);

    Stack* temp = head;

    head = head->next;

    pop(temp);

  }

  pop(head);

}

void newtree(char z, Stack* &head, Tree* &tree){ // creates tree

  Tree* newtree = new Tree(z);

  if (tree == NULL){
    char a = peek(head);
 
    char b = peek(head->next);

    Tree* right = new Tree(a);

    Tree* left = new Tree(b);
    
    newtree->setRight(right);
  
    newtree->setLeft(left);
  
    pop(head);
    pop(head);
    
    tree = newtree;
  }

  else if (tree->getchar() == '+' || tree->getchar() == '-' || tree->getchar() == '/' || tree->getchar() == '*' || tree->getchar() == '^'){

    char a = tree->getchar();

    char b = peek(head);

    Tree* right = new Tree(b);

    newtree->setRight(right);

    newtree->setLeft(tree);

    pop(head);

    tree = newtree;
    
  }

}


void printInfix(Tree* tree){ // prints infix form

  if (tree->getLeft() != NULL){

    printInfix(tree->getLeft());

  }

  cout << tree->getchar();

  if (tree->getRight() != NULL){

    printInfix(tree->getRight());

  }

}

void printPostfix(Tree* tree){ // prints postfix form

  if (tree->getLeft() != NULL) {

    printPostfix(tree->getLeft());

  }

  if (tree->getRight() != NULL) {

    printPostfix(tree->getRight());
    
  }

  cout << tree->getchar();
  
}

void printPrefix(Tree* tree){ // prints prefix form

  cout << tree->getchar();

  if (tree->getLeft() != NULL) {

    printPostfix(tree->getLeft());

  }
  
  if (tree->getRight() != NULL) {

    printPostfix(tree->getRight());

  }
  
  
}
