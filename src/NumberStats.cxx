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
#include <vector>

using namespace chapter5;

/**
 * @brief Sets the numbers used for the methods of NumberStats objects.
 *
 * @param num1 First input (Must be < num2).
 * @param num2 Second input.
 */
void NumberStats::setNumbers(int num1, int num2) {
  m_firstNumber = num1;
  m_secondNumber = num2;
}

/**
 * @brief Generates a vector of even integers between `start` and `end`.
 *
 * @param start First number input by user (beginning of vector).
 * @param end Second number input by user (end of vector).
 */
void NumberStats::setEvenNumbers(int start, int end) {
  start = m_firstNumber;
  end = m_secondNumber;

  for (auto iter = start; iter <= end; iter++) {
    if (iter % 2 == 0) {
      m_evenNumbers.push_back(iter);
    }
  }
}

/**
 * @brief Generates a vector of odd integers between `start` and `end`.
 *
 * @param start First number input by user (beginning of vector).
 * @param end Second number input by user (end of vector).
 */
void NumberStats::setOddNumbers(int start, int end) {
  start = m_firstNumber;
  end = m_secondNumber;

  for (auto iter = start; iter <= end; iter++) {
    if (iter % 2 != 0) {
      m_oddNumbers.push_back(iter);
    }
  }
}

/**
 * @brief Generates the output required in the programming assignment
 * specification for this program.
 *
 */
void NumberStats::generateStatisticalOutput() const {
  std::cout << "Odd integers between " << m_firstNumber << " and "
            << m_secondNumber << " are:\n";

  printOdds();

  std::cout << "Sum of even integers between " << m_firstNumber << " and "
            << m_secondNumber << " = " << getSumOfEvens() << '\n';

  printPowersOneToTen();

  std::cout << "The sum of the squares of odd integers between "
            << m_firstNumber << " and " << m_secondNumber << " = "
            << getSumOfOddSquares() << '\n';

  printLetters();

  std::cout << '\n';
}

/**
 * @brief Prints the integers contained in the odd number vector.
 *
 */
void NumberStats::printOdds() const {
  std::vector<int>::const_iterator oddIterator =
      m_oddNumbers.begin(); //<! Iterator (Loop Control Variable)

  do {
    std::cout << *oddIterator << ' ';
    oddIterator++;
  } while (oddIterator != m_oddNumbers.end());

  std::cout << '\n';
}

/**
 * @brief Gets first number input by user.
 *
 * @return int First number input by user.
 */
int NumberStats::getFirstNumber() const { return m_firstNumber; }

/**
 * @brief Gets second number input by user.
 *
 * @return int Second number input by user.
 */
int NumberStats::getSecondNumber() const { return m_secondNumber; }

/**
 * @brief Gets the vector of even integers.
 *
 * @return std::vector<int> Vector of even integers.
 */
std::vector<int> NumberStats::getEvenNumbers() const { return m_evenNumbers; }

/**
 * @brief Generates sum of even integer vector.
 *
 * @return int Sum of even integer vector.
 */
int NumberStats::getSumOfEvens() const {
  int sumOfEvens;

  for (auto iter = m_evenNumbers.begin(); iter != m_evenNumbers.end(); iter++) {
    sumOfEvens += *iter;
  }

  return sumOfEvens;
}

/**
 * @brief Gets odd number vector.
 *
 * @return std::vector<int> Odd number vector.
 */
std::vector<int> NumberStats::getOddNumbers() const { return m_oddNumbers; }

/**
 * @brief Generates sum of squared odd integers in odd vector.
 *
 * @return int Sum of squared odd integers in odd vector.
 */
int NumberStats::getSumOfOddSquares() const {
  int sumOfOddSquares;

  for (auto iter = m_oddNumbers.begin(); iter != m_oddNumbers.end(); iter++) {
    sumOfOddSquares += std::pow(*iter, 2);
  }

  return sumOfOddSquares;
}

/**
 * @brief Outputs a table of the numbers 1-10 and their square.
 *
 */
void NumberStats::printPowersOneToTen() const {
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
void NumberStats::printLetters() const {
  std::cout << "Uppercase letters are: ";

  char currentLetter = 'A';
  while (currentLetter >= 'A' && currentLetter <= 'Z') {
    std::cout << currentLetter++ << ' ';
  }

  std::cout << '\n';
}
