#ifndef INPUT_TOOLS_INCLUDED
#define INPUT_TOOLS_INCLUDED
/*********************************************************
** Filename: input_tools.h
** Date: 7/15/2014
** Updated: 7/29/2014
** Version: 2.3.1
** Description: Input Integer functions
** Contributors: Michael Hoppes
**               Jonathan Gamble
**               Brandon Swanson
** Link: https://piazza.com/class/hw4gteiztbt22e?cid=198
*********************************************************/
namespace input_tools {

  // Declare functions
  void print_i(std::string msg, bool is_error_msg = true);
  void error(std::string e, void(*f)(std::string, bool) = print_i);
  void error(std::string e, int i, void(*f)(std::string, bool) = print_i);
  void error(std::string e, std::string s, void(*f)(std::string, bool) = print_i);
  std::string input_string(std::string msg, void(*f)(std::string, bool) = print_i);
  void input_c_string(std::string msg, char *array, size_t size, void(*f)(std::string, bool) = print_i);
  int input_integer(std::string msg, int min, int max, void(*f)(std::string, bool) = print_i);
  int input_integer(std::string msg, void(*f)(std::string, bool) = print_i);
  bool input_yes_no(std::string msg, void(*f)(std::string, bool) = print_i);
  char input_alpha_char(std::string msg, void(*f)(std::string, bool) = print_i);
  char input_alpha_char_lc(std::string msg, void(*f)(std::string, bool) = print_i);
  char input_alpha_char_uc(std::string msg, void(*f)(std::string, bool) = print_i);
  const size_t num_digits(int n);
  const int digit_at(size_t val, int n);
  bool is_size_of_int(const std::string input);
  bool is_integer(const std::string input);
  std::string int_to_str(int i);
  std::string char_to_str(char c);
  int str_to_int(std::string s);
  int char_to_int(char c);
  std::string str_to_lower(std::string word);
  std::string str_to_upper(std::string word);

}
/*************************************************
INCLUDING input_tools
**************************************************
Loading the tool

  #include "input_tools.h"

  using namespace input_tools;

or

  using input_tools::function_name;

remember to compile the input_tools.cpp file
in your program

FUNCTION input_std::string()
**************************************************
inputting a std::string

  std::string input;

  input = input_std::string("Please enter a std::string");

FUNCTION input_c_std::string()
**************************************************
inputting a c_std::string or c character array

  const int STR_SIZE = 20;
  char str[STR_SIZE];
  input_c_std::string("Please enter a std::string", str, STR_SIZE);

FUNCTION input_integer()
**************************************************
inputting an integer

  int i;
  i = input_integer("Please enter an integer");

or with a certain range between 10 and 25

  int i;
  i = input_integer("Please enter an integer, 10, 25);

FUNCTION input_yes_no()
**************************************************
inputting a yes or no question

  do {
  // code
  } while (input_yes_no("Play again? (y/n)"));

FUNCTION input_alpha_char()
**************************************************
inputting an alpha character (a-z) or (A-Z)

  char c;
  c = input_alpha_char("Please enter a letter");

or for upper or lower case

  c = input_alpha_char_uc("Please enter a letter");
  c = input_alpha_char_lc("Please enter a letter");

ERROR HANDLING AND MESSAGE OUTPUT
**************************************************
how to customize the error and message output
For each of these functions you can add another parameter
that is your own function to customize the output.

declare your function prototype with a std::string and bool
parameters returning void

  void my_function(std::string msg, bool is_error_msg);

add your function name as the last parameter to the input
function of your choice

  int i = input_integer("Please enter an integer", my_function);

create your own function matching the prototype above
and adding an if statement with your bool variable
to differential between the error and the input message

  void my_function(std::string msg, bool is_error_msg) {
    if (is_error_msg)
      cout << "WOW, you messed up! " << msg << endl;
    else
      cout << msg << endl << " : ";
  }

output

Please enter an integer
: j
Wow, you messed up! You must enter a valid integer....
Please enter an integer
:

*************************************************/
#endif // INPUT_TOOLS_INCLUDED