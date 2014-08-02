/****************************************************
** Filename: word_tools.cpp
** Date: 7/17/2014
** Updated: 8/1/2014
** Version: 2.2.2
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

namespace word_tools {

  void clear_screen() {
    // clear the screen
    cout << string(100, '\n');
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
    return x != 1 ? w += s : w;
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

  bool is_in_array(int array[], int size, int search) {
    // check if int is in array of int
    for (int i = 0; i < size; i++)
      if (array[i] == search)
        return true;
    return false;
  }

  void replace_blank_word(char letter, std::string word, std::string &blank_word) {
    // replace all occurences char in blank_word string
    for (size_t i = 0; i < word.length(); i++) {
      if (letter == word.at(i))
        blank_word.replace(i, 1, std::string(1, letter));
    }
  }

  bool is_char_in_array(char c, char *arr, int size) {
    // see if character is in the array
    for (int i = 0; i < size; i++)
      if (arr[i] == c)
        return true;
    return false;
  }

  bool is_char_in_str(char c, std::string s) {
    // see if character is in the string
    return (s.find(c) != std::string::npos);
  }

  int num_char_in_str(char c, std::string s) {
    // return number of characters in a string
    int n = 0;
    for (size_t i = 0; i < s.length(); i++)
      if (s.at(i) == c)
        n++;
    return n;
  }

}
