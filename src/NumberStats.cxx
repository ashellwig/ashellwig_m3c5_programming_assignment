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

void NumberStats::setNumbers(int num1, int num2) {
  m_firstNumber = num1;
  m_secondNumber = num2;
}

void NumberStats::setEvenNumbers(int start, int end) {
  start = m_firstNumber;
  end = m_secondNumber;

  for (auto iter = start; iter <= end; iter++) {
    if (iter % 2 == 0) {
      m_evenNumbers.push_back(iter);
    }
  }
}

void NumberStats::setOddNumbers(int start, int end) {
  start = m_firstNumber;
  end = m_secondNumber;

  for (auto iter = start; iter <= end; iter++) {
    if (iter % 2 != 0) {
      m_oddNumbers.push_back(iter);
    }
  }
}

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

void NumberStats::printOdds() const {
  for (auto iter = m_oddNumbers.begin(); iter != m_oddNumbers.end(); iter++) {
    std::cout << *iter << ' ';
  }

  std::cout << '\n';
}

int NumberStats::getFirstNumber() const { return m_firstNumber; }

int NumberStats::getSecondNumber() const { return m_secondNumber; }

std::vector<int> NumberStats::getEvenNumbers() const { return m_evenNumbers; }

int NumberStats::getSumOfEvens() const {
  int sumOfEvens;

  for (auto iter = m_evenNumbers.begin(); iter != m_evenNumbers.end(); iter++) {
    sumOfEvens += *iter;
  }

  return sumOfEvens;
}

std::vector<int> NumberStats::getOddNumbers() const { return m_oddNumbers; }

int NumberStats::getSumOfOddSquares() const {
  int sumOfOddSquares;

  for (auto iter = m_oddNumbers.begin(); iter != m_oddNumbers.end(); iter++) {
    sumOfOddSquares += std::pow(*iter, 2);
  }

  return sumOfOddSquares;
}

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

void NumberStats::printLetters() const {
  std::cout << "Uppercase letters are: ";

  char currentLetter = 'A';
  while (currentLetter >= 'A' && currentLetter <= 'Z') {
    std::cout << currentLetter++ << ' ';
  }

  std::cout << '\n';
}
