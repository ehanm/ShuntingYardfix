#include <iostream>
#include <cstring>
#include "stack.h"
// this is shunting yard

using namespace std;
void push(char x, Stack* next);



int main(){

  Stack* stackhead = NULL;
  
  char input[100];

  char input2[100];

  cout << "Shunting Algorithm!" << endl;

  cout << "Enter a mathematical expression (make sure to include spaces): " << endl;

  cin >> input;

  cout << input;

  for (int i = 0; i < strlen(input); i++){

    if (i = 0){

      // push 
      
    }

    if (input[i] = '+' || input[i] = '-' || input[i] = '*' || input[i] = '/' || 


  }

  cout << "Prefix, Infix, or Postfix?" << endl;

  cin >> input2;

  // enter converting to prefix, infix, and postfix here

  



}
