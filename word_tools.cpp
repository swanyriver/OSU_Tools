/****************************************************
** Filename: word_tools.cpp
** Date: 7/17/2014
** Updated: 8/1/2014
** Version: 2.3.1
** Description: Functions for words
** Contributors: Michael Hoppes
**               Jonathan Gamble
****************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "input_tools.h"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

namespace word_tools {

  void clear_screen() {
    // clear the screen
    system(CLEAR);
  }

  void display_bar() {
    // display lots of bars
    cout << string(70, '*') << endl;
  }

  void display_msg(string msg) {
    // display update msg
    cout << endl << "-----" << msg << "-----" << endl << endl;
  }

  string plural(int x, string word) {
    // return a plural word if necessary
    string w = input_tools::int_to_str(x) + " " + word;
    return x == 1 ? w : w += "s";
  }

  string plural(int x, string word, string plural_word) {
    // return non-standard plural word if necessary
    string w = input_tools::int_to_str(x) + " ";
    return x == 1 ? w + word : w + plural_word;
  }

  bool file_exists(const string &name) {
    // check that a file exists
    ifstream ifile(name.c_str());
    return ifile.good();
  }

  int rand_int(int min, int max) {
    // only run srand() once
    static bool loaded = false;
    if (!loaded) {
      //fix problem with 64 bit system
      srand((unsigned int)time(NULL));
      loaded = true;
    }
    int range = max - min + 1;
    return rand() % range + min;
  }

  void replace_all_chars(char c, string str1, string &str2) {
    // replace all matching char occurences from str1 in str2
    for (size_t i = 0; i < str1.length(); i++) {
      if (c == str1.at(i))
        str2[i] = c;
    }
  }

  bool is_in_array(int array[], int size, int search) {
    // check if int is in array of int
    for (int i = 0; i < size; i++)
      if (array[i] == search)
        return true;
    return false;
  }

  bool is_char_in_array(char c, char *arr, int size) {
    // see if character is in the array
    for (int i = 0; i < size; i++)
      if (arr[i] == c)
        return true;
    return false;
  }

  bool is_char_in_str(char c, string s) {
    // see if character is in the string
    return (s.find(c) != string::npos);
  }

  int num_char_in_str(char c, string s) {
    // return number of characters in a string
    int n = 0;
    for (size_t i = 0; i < s.length(); i++)
      if (s.at(i) == c)
        n++;
    return n;
  }

  bool are_equal(char a, char b, char c) {
    // see if three characters are equal
    return (a == b && b == c);
  }

}
