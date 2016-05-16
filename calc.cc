#include <iostream>
#include "calc.h"

using namespace std;

/*********** Calc() ***********
  Purpose: Constructor of Class Calc
           using member initialization list to initialize all
           fields to zero.
************************************/
Calc::Calc(): error(false), display(0), oper(0), result(0), memory(0) {}


/*********** Calc(const Calc &other) ***********
  Purpose: Copy constructor of Class Calc
           using member initialization list to initialize all
           fields to the corresponding Class Calc other's fields.
************************************/
Calc::Calc(const Calc &other): error(other.error), display(other.display), oper(other.oper), result(other.result), memory(other.memory) {}


/*********** digit ***********
  Purpose: A method of Class Calc
           add a digit to display, and update display.
  return void.
************************************/
void Calc::digit(int digit){
  if(error == false){                            // preconditon:no error occurs
    if(display >= 0){
      display = display * 10 + digit;
    } else {
      display = display *10 - digit;
    }// if
  }// if
} // digit


/*********** op ***********
  Purpose: A method of Class Calc
           record the operator.
           If no operator previous recored, update result with display.
           after that record the operator.
           Otherwise, calculate current formula using the combination of 
           result, operator and display, after that, record the operator
  return void.
************************************/
void Calc::op(char opr){
  if(error == false){                            // is error?                           
    if(oper != 0){
      equals();
    } else {
      result = display;
    } // if
  } //if
  oper = opr;
  display = 0;
} // op


/*********** equals ***********
  Purpose: A method of Class Calc
           calculate the value with current stored information(result, operator and display)
           if operator is '+' add display to result, update display
           if operator is '-' minus display from result, update display
           if operator is '+' multiply display with result, update display
           if operator is '+' if display not 0, divid display by result, update display
                              Otherwise error occurs
           then update operator to 0;
  return void.
************************************/
void Calc::equals(){
  if(error == false){                            // is error?
    if(oper == '+') {                            // is operator +?
      result = result + display;
      display = result;
    } else if(oper == '-') {                     // is operator -?
      result = result - display;
      display = result;
    } else if(oper == '*') {                     // is operator *?
      result = result * display;
      display = result;
    } else if(oper == '/') {                     // is operator /?
      if(display != 0){                          // is display 0?
        result = result / display;
        display = result;
      } else {
        error = true;
      } // if
    } else {                                     // if error already occurs
      result = display;                          // update result to display
    } // if
    oper = 0;
  } // if
} // equals


/*********** memPlus ***********
  Purpose: A method of Class Calc
           addition on memory
           add display to memory if no error occurs
  return void.
************************************/
void Calc::memPlus(){
  if(error == false){                            // is error?
    memory = display + memory;
  } // if
} // memPlus

/*********** memPlus ***********
  Purpose: A method of Class Calc
           clear memory
           set memory to zero if no error occurs
  return void.
************************************/
void Calc::memClear(){
  if(error == false) {                           // is error?
    memory = 0;
  } // if
} // memClear


/*********** memRecall ***********
  Purpose: A method of Class Calc
           recall memory
  return void.
************************************/
void Calc::memRecall(){
  if(error == false){                           // is error?
    display = memory;
  }
} // memRecall


/*********** memRecall ***********
  Purpose: A method of Class Calc
           judge whether there is an error.
  return true if error is true
         false if error is false.
************************************/
bool Calc::isError() const {
  if(error == true){                           // is error?
    return true;
  } else {
    return false;
  } // if
} // isError

/*********** memRecall ***********
  Purpose: A method of Class Calc
           clear all: set all fields to initial value 0.
  return void.
************************************/
void Calc::allClear(){
  error = false;
  display = 0;
  oper = 0;
  result = 0;
  memory = 0;
} // allClear


/*********** operator<< ***********
  Purpose: overload output operator
           to print memory and error if it has.
  return out.
************************************/
ostream &operator<<(ostream &out, const Calc &c) {
  if((c.error == false) && (c.memory == 0)){
    out << c.display;
  } else if((c.error == false) && (c.memory != 0)) {
    out << c.display << " M: " << c.memory;
  } else if((c.error == true) && (c.memory == 0)) {
    out << "0 E";
  } else {
    out << "0 M: " << c.memory << " E";
  } // if
  return out;
} // operator<<

