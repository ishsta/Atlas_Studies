#include <stdio.h>
#include <stdlib.h> // for atoi function

//-------------------------------------------------------------// 
// File:   name_age.c                                          //
// Input:  scanf() request user enter their name               //
//         scanf() request user enter their age                //
// Output: printf() "[input name] is [input age] years old.\n" //
//-------------------------------------------------------------// 

int main(){

  char input_name[20]; // Declare a name string no longer than 20 characters
  char age_str[4]; // Declare an age string no longer than 4 characters
  int age; // Declare an integer variable to store the converted age

  // Get user input for name
  printf("What's your name? ");
  scanf("%s", input_name);

  // Get user input for age
  printf("How old are you? ");
  scanf("%s", age_str);

  // Convert age string to an integer using atoi
  age = atoi(age_str);

  // Print the result
  printf("%s is %d years old. \n", input_name, age);

  return 0;


}

/*

  atof(const char *str) Converts the string pointed to by str to a floating-point number (type double)
  atoi(const char *str) Converts the string pointed to by str to an integer
  atol(const char *str) Converts the string pointed to by str to a long integer (type int)
  strtod(const char *str, char **endptr) Converts the string pointed to by str to a flating-point number (type double)
  strtol(const char *str, char **endptr, int base) Converts the string pointed to by str to a long integer (type long int)
  strtoul(const char *str, char **endptr, int base) Converts the string pointed to by str to an unsigned long integer (type unsigned long int)

  */
