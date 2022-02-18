#include <iostream>
#include <cstring>
#include "stack.h"
// this is shunting yard

using namespace std;

void push(char z, Stack* next);

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

      if (input[i] = '+' || input[i] = '-' || input[i] = '*' || input[i] = '/' || input[i] = '^'){

	// push
	
      
      }
      
    }
  }

  else if (strcmp(input2, "Prefix") == 0) {
    // make prefix thing
  }

  else if (strcmp(input2, "Infix") == 0) {
    // make infix thing
  }

}

void push(char z, Stack* next){
  if (next == NULL){

    Stack* newpointer = new Stack();
    nextpointer->z = x;


  }
  
}
