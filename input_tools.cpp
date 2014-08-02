/*********************************************************
** Filename: input_tools.cpp
** Date: 7/15/2014
** Updated: 7/31/2014
** Version: 2.3.1
** Description: Input Integer functions
** Contributors: Michael Hoppes
**               Jonathan Gamble
**               Brandon Swanson
** Link: https://piazza.com/class/hw4gteiztbt22e?cid=198
*********************************************************/
#include <iostream>
#include <string>
// for INT_MAX and INT_MIN
#include <climits>
// for atoi()
#include <cstdlib>
#include "input_tools.h"

using std::string;

namespace input_tools {

  // Declare the constant error strings
  const string
    NO_VALUE = "You must enter a value!",
    NO_INT = "You must enter a valid integer between " + int_to_str(INT_MIN) + " and " + int_to_str(INT_MAX) + "!",
    NO_YES = "You must enter yes or no!",
    SM_INT = "The integer must be at least %i!",
    LG_INT = "The integer must be at most %i!",
    C_STR_SIZE = "You must enter a string of %i characters at most!",
    NO_ALPHA = "You must enter one valid alpha character!";

  string input_string(string msg, void(*f)(string, bool)) {
    // input a string
    bool valid = false;
    string input;
    while (!valid) {
      print_i(msg, false);
      getline(std::cin, input);
      if (input.length() == 0)
        error(NO_VALUE, f);
      else
        valid = true;
    }
    return input;
  }

  void input_c_string(string msg, char *array, size_t size, void(*f)(string, bool)) {
    // input a c string
    string input;
    bool valid = false;
    while (!valid) {
      input = input_string(msg, f);
      if (input.length() > size)
        error(C_STR_SIZE, size, f);
      else
        valid = true;
    }
    for (size_t i = 0; i < size; i++) {
      if (i < input.length())
        array[i] = input.at(i);
      else
        array[i] = '\0';
    }
  }

  int input_integer(string msg, int min, int max, void(*f)(string, bool)) {
    // input an integer with a range
    int i;
    bool valid = false;
    while (!valid) {
      i = input_integer(msg, f);
      if (i < min)
        error(SM_INT, min, f);
      else if (i > max)
        error(LG_INT, max, f);
      else
        valid = true;
    }
    return i;
  }
  
  int input_integer(string msg, void(*f)(string, bool)) {
    // input an integer as a string
    bool valid = false;
    string input;
    while (!valid) {
      input = input_string(msg, f);
      if (!is_integer(input))
        error(NO_INT, f);
      else
        valid = true;
    }
    return str_to_int(input);
  }

  bool input_yes_no(string msg, void(*f)(string, bool)) {
    // input y or no and return true or false
    bool valid = false;
    string input;
    while (!valid) {
      input = str_to_lower(input_string(msg, f));
      if (input != "yes" && input != "y" && input != "no" && input != "n")
        error(NO_YES, f);
      else
        valid = true;
    }
    return (input.at(0) == 'y') ? true : false;
  }

  char input_alpha_char(string msg, void(*f)(string, bool)) {
    // input an alpha char
    bool valid = false;
    string input;
    while (!valid) {
      input = input_string(msg, f);
      if (!isalpha(input.at(0)) || input.length() != 1)
        error(NO_ALPHA, f);
      else
        valid = true;
    }
    return input.at(0);
  }

  char input_alpha_char_lc(string msg, void(*f)(string, bool)) {
    // input a lower case alpha char
    return tolower(input_alpha_char(msg, f));
  }

  char input_alpha_char_uc(string msg, void(*f)(string, bool)) {
    // input an upper case alpha char
    return toupper(input_alpha_char(msg, f));
  }

  const size_t num_digits(int n) {
    // num of digits in an int
    size_t digits = 0;
    if (n < 0)
      digits = 1;
    while (n) {
      n /= 10;
      digits++;
    }
    return digits;
  }

  const int digit_at(size_t val, int n) {
    // gets a digit like an array
    val++;
    size_t place = num_digits(n) - val;
    for (size_t i = 0; i < place; i++)
      n /= 10;
    return n % 10;
  }

  bool is_size_of_int(const string input) {
    // checks that the input is an int size
    size_t digits = num_digits(INT_MAX);
    if (input.length() < digits)
      return true;
    if (input.length() > digits)
      return false;
    for (size_t i = 0; i < input.length(); i++)
      if (char_to_int(input.at(i)) > digit_at(i, INT_MAX))
        return false;
    return true;
  }

  bool is_integer(const string input) {
    // check if is integer
    if (!isdigit(input.at(0)) && input.at(0) != '-')
      return false;
    for (size_t i = 1; i < input.length(); i++)
    if (!isdigit(input.at(i)))
      return false;
    if (!is_size_of_int(input))
      return false;
    return true;
  }

  string int_to_str(int i) {
    // integer to string
    if (i == 0)
      return "0";
    int sign = (i < 0 ? i = -i, 1 : 0);
    string s = sign ? "-" : "";
    char temp;
    while (i) {
      temp = '0' + i % 10;
      s.insert(sign, &temp, 1);
      i /= 10;
    }
    return s;
  }

  char int_to_char(int i) {
    // integer to character
    // only convert 0 - 9
    return digit_at(0, i) + '0';
  }

  string char_to_str(char c) {
    // character to string
    return string(1, c);
  }

  int str_to_int(string s) {
    // string to integer
    return atoi(s.c_str());
  }

  int char_to_int(char c) {
    // character to integer
    return atoi(string(1, c).c_str());
  }

  string str_to_lower(string word) {
    // change a string to lower case
    for (size_t i = 0; i < word.length(); i++)
      word.replace(i, 1, string(1, tolower(word.at(i))));
    return word;
  }

  string str_to_upper(string word) {
    // change a string to upper case
    for (size_t i = 0; i < word.length(); i++)
      word.replace(i, 1, string(1, toupper(word.at(i))));
    return word;
  }

  void print_i(string msg, bool is_error_msg) {
    // print the input or error msg
    if (is_error_msg)
      // display error msg
      std::cout << msg << std::endl;
    else
      // display input msg
      std::cout << msg << " : ";
  }

  void error(string e, void(*f)(string, bool)) {
    // run the error function
    f(e, true);
  }

  void error(string e, int i, void(*f)(string, bool)) {
    // create an error from int
    e.replace(e.find("%i"), 2, int_to_str(i));
    error(e, f);
  }

  void error(string e, string s, void(*f)(string, bool)) {
    // create an error from string
    e.replace(e.find("%s"), 2, s);
    error(e, f);
  }

}