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
#include "../include/cxxopts/cxxopts.hpp"  // Argument parsing
#include "../include/general_functions.hh" // pauseprompt
#include <exception>
#include <iostream> // cout, cin
#include <limits>

/**
 * \brief Performs the steps to execute the main application.
 */
int main(int argc, char **argv) {
  // Variables to store the user's input
  int num1, num2;

  // Prompt user for numbers
  std::cout << "Enter two numbers." << std::endl;
  std::cout << "First number must be less than the second number you enter"
            << std::endl;
  std::cout << "Enter numbers: ";
  std::cin >> num1 >> num2;

  while (std::cin) {
    if (std::cin.fail()) {
      std::cout << "Input failed." << std::endl;
      break;
    } else {
      break;
    }
  }

  std::cout << std::endl;

  // Initialize our class
  chapter5::NumberStats numbers(num1, num2);

  // Generate the output
  numbers.generateStatisticalOutput();

  // "Press enter to continue..."
  general_functions::pauseprompt();
  std::cin.ignore();

  // Return with exit code 0 if all goes well
  return 0;
}

// vim: set et ts=2 sw=2 ft=cpp:
