#ifndef WORD_TOOLS_INCLUDED_H
#define WORD_TOOLS_INCLUDED_H
/****************************************************
** Filename: word_tools.h
** Date: 7/17/2014
** Updated: 8/1/2014
** Version: 2.2.0
** Description: Functions for words
** Contributors: Michael Hoppes
**               Jonathan Gamble
****************************************************
** Linux only terminal color codes
** from http://stackoverflow.com/questions/9158150/colored-output-in-c
****************************************************
** Example: std::cout << RED << "hello world" << RESET << std::endl;
****************************************************/
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m" 
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

namespace word_tools {
  
  // clear the screen with new-lines
  void clear_screen();

  // display lots of asterix in a bar
  void display_bar();

  // display a message
  void display_msg(std::string msg);

  // return a word with an s
  std::string plural(int x, std::string word);
  // if the plural version of the word isn't just adding an s, provide the full version
  // Example: plural(x, "tomato", "tomatoes");
  std::string plural(int x, std::string word, std::string plural_word);

  // check that a file exists
  bool file_exists(const std::string &name);

  // return a random integer
  int rand_int(int min, int max);

  // check if int is in array of int
  bool is_in_array(int array[], int size, int search);

  // replace all char occurences in blank_word string
  void replace_blank_word(char letter, std::string word, std::string &blank_word);

  // see if character is in the array
  bool is_char_in_array(char c, char *arr, int size);

  // see if character is in the string
  bool is_char_in_str(char c, std::string s);

  // return number of occurances of char in a string
  int num_char_in_str(char c, std::string s);

}
#endif // WORD_TOOLS_INCLUDED
