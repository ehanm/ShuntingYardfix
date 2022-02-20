dit Options Buffers Tools C++ Help
#include <iostream>
#include <cstring>
#include "stack.h"
#include "queue.h"
// this is shunting yard

using namespace std;

void push(char z, Stack* &head);
void enqueue(char z, Queue* &head);


int main(){

  Stack* stackhead = NULL;
  Queue* queuehead = NULL;

  char input[100];

  char input2[100];

  cout << "Shunting Algorithm!" << endl;

  cout << "Enter a mathematical expression (make sure to include spaces): " << endl;

  cin >> input;

  cout << input;

  cout << "Prefix, Infix, or Postfix?" << endl;

  cin >> input2;

  if (strcmp(input2, "Postfix") == 0) {
    for (int i = 0; i < strlen(input); i++){

      if (i = 0){

        // enqueue

      }

      else if (input[i] = '+' || input[i] = '-' || input[i] = '*' || input[i] = '/' || input[i] = '^' || input[i] = '('){

        push(input[i], stackhead);

      }

      else if (input[i] = '1' || input[i] = '2' || input[i] = '3' || input[i] = '4' || input[i] = '5' ||
               input[i] = '6' || input[i] = '7' || input[i] = '8' || input[i] = '9'){

        enqueue(input[i], queuehead);


      }

    }

    // move stuff from stack to queue

    // print queue
  }

  else if (strcmp(input2, "Prefix") == 0) {
    // make prefix thing
  }

  else if (strcmp(input2, "Infix") == 0) {
    // make infix thing
  }

}

void push(char z, Stack* &head) {
  Stack* newpointer = new Stack();
  newpointer->x = z;
  newpointer->next = head;
  head = newpointer;
}

void enqueue(char z, Queue* &head) {


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


