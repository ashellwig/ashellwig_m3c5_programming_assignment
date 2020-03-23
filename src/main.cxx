/**
 * @file main.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the main function to run the program.
 * @date 2020-03-13
 *
 * Assignment: Module 3 Chapter 5 Programming Assignment
 * Description: This file contains the main function to run the program.
 * Instructor: Jeffrey Hemmes
 * Course:
 *   [CSC 160] Introduction to Programming (C++)
 * Date: 14 March 2020
 */

#include "../include/NumberStats.hh"       // NumberStats
#include "../include/general_functions.hh" // pauseprompt
#include <iostream>                        // cout, cin

/**
 * @brief Performs the steps to execute the main application.
 */
int main() {
  // Declare variables for assignment by user input
  int num1 = 0;
  int num2 = 0;

  chapter5::promptUserInput(num1, num2);
  std::cout << std::endl;

  // Print odd numbers;
  std::cout << "Odd integers between " << num1 << " and " << num2
            << " are:" << std::endl;
  chapter5::printOdds(num1, num2);

  // Calculate sum of evens
  std::cout << "Sum of even integers between " << num1 << " and " << num2
            << " = " << chapter5::calcSumOfEvens(num1, num2) << std::endl;

  // Output Integers and their squares for [1..10]
  chapter5::printPowersOneToTen();

  // Output sum of odd squares
  std::cout << "Sum of the squares of odd integers between " << num1 << " and "
            << num2 << " = " << chapter5::calcSumOfOddSquares(num1, num2)
            << std::endl;

  // Print Characters [A..Z]
  chapter5::printLetters();
  std::cout << std::endl;

  // "Press enter to continue..."
  general_functions::pauseprompt();
  std::cin.ignore();

  // Return with exit code 0 if all goes well
  return 0;
}

// vim: set et ts=2 sw=2 ft=cpp:
