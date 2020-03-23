/**
 * @file NumberStats.cxx
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the class definition of `NumberStats` objects,
 *   allowing us easier implementation and testing utilization.
 * @date 2020-03-13
 *
 * Assignment: Module 3 Chapter 5 Programming Assignment
 * Description: This file contains the class definition of `NumberStats`
 *   objects, allowing us easier implementation and testing utilization.
 * Instructor: Jeffrey Hemmes
 * Course:
 *   [CSC 160] Introduction to Programming (C++)
 * Date: 14 March 2020
 */

#include "../include/NumberStats.hh"
#include "../include/debug.hh"
#include <cmath>
#include <iomanip>
#include <iostream>

/**
 * @brief Prompts the user for two numbers for future computation.
 *
 * The first number must be lower than the second. If it is not, it will
 * continue to prompt the user until the values supplied satisfy the
 * requirements. The variables are to be declared before calling this function
 * **but not assigned**, as they will be copied by reference when the function
 * is called successfully.
 *
 * @param in1 Variable storing the first input.
 * @param in2 Variable storing the second input.
 */
void chapter5::promptUserInput(int &in1, int &in2) {
  std::cout << "Enter two numbers." << std::endl;
  std::cout << "First number must be less than the second number you enter"
            << std::endl;
  std::cout << "Enter numbers: " << std::endl;
  std::cin >> in1 >> in2;

  while (std::cin) {
    if (in1 > in2) {
      std::cout << "First input should be lower than the second." << std::endl;
      std::cin >> in1 >> in2;
      break;
    }
    break;
  }
}

/**
 * @brief Prints the odd integers between two numbers.
 *
 */
void chapter5::printOdds(int in1, int in2) {
  while (in1 <= in2) {
    if (in1 % 2 != 0) {
      std::cout << in1 << ' ';
      in1++;
      continue;
    }
    in1++;
  }

  std::cout << std::endl;
}

/**
 * @brief Generates sum of even integers between two numbers.
 *
 * @param in1 First input from user.
 * @param in2 Second input from user.
 *
 * @return int The sum of even numbers between `in1` and `in2`
 */
int chapter5::calcSumOfEvens(int in1, int in2) {
  int sumOfEvens = 0;

  // Loop control variable

  while (in1 <= in2) {
    if (in1 % 2 == 0) {
      sumOfEvens += in1;
      in1++;
      continue;
    }
    in1++;
  }

  return sumOfEvens;
}

/**
 * @brief Generates sum of the odd integers squared between two numbers.
 *
 * @param in1 First input from user.
 * @param in2 Second input from user.
 *
 * @return int The sum of (odd numbers)^2 between `in1` and `in2`
 */
int chapter5::calcSumOfOddSquares(int in1, int in2) {
  // Sum of the odd numbers each squared
  int sumOfOddSquares = 0;

  while (in1 <= in2) {
    if (in1 % 2 != 0) {
      sumOfOddSquares += std::pow(in1, 2);
      in1++;
      continue;
    }
    in1++;
  }

  return sumOfOddSquares;
}

/**
 * @brief Outputs a table of the numbers 1-10 and their square.
 *
 */
void chapter5::printPowersOneToTen() {
  std::cout << std::setfill(' ') << "Number" << std::setw(20)
            << "Square of Number" << '\n';

  int start = 1;
  while (start <= 10) {
    if (start == 10) {
      std::cout << start << std::setw(16) << std::pow(start, 2) << '\n';
    } else {
      std::cout << start << std::setw(17) << std::pow(start, 2) << '\n';
    }

    start += 1;
  }

  std::cout << '\n';
}

/**
 * @brief Outputs all uppercase letters of the English alphabet.
 *
 */
void chapter5::printLetters() {
  std::cout << "Uppercase letters are: ";

  char currentLetter = 'A';
  while (currentLetter >= 'A' && currentLetter <= 'Z') {
    std::cout << currentLetter++ << ' ';
  }

  std::cout << '\n';
}
