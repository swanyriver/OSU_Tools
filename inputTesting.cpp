/*
 * inputTesting.cpp
 *
 *  Created on: Aug 5, 2014
 *      Author: brandon
 */

#include "input_tools.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

using namespace input_tools;

const int NUM_CASES = 16;
int testNumber;

void ErrorCatch(string msg, bool error){
   if(error){
      cout << "test case " << testNumber << ": " << msg << endl;
      testNumber++;

   }else{
      //cout << "input:";
   }
}

int main(){

   testNumber=0;

   while(testNumber<NUM_CASES){
      testNumber++;
      int myInt = input_integer("give input",ErrorCatch);
      cout << "test case " << testNumber << ":"<< myInt  << " hex:"
            << std::hex << myInt << std::dec;
      cout <<endl;
   }



}


