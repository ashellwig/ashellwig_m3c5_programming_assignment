/**
 * @file NumberStats.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the class prototype of `NumberStats` objects,
 *   allowing us easier implementation and testing utilization.
 * @date 2020-03-13
 *
 * Assignment: Module 3 Chapter 5 Programming Assignment
 * Description: This file contains the class prototype of `NumberStats`
 *   objects, allowing us easier implementation and testing utilization.
 * Instructor: Jeffrey Hemmes
 * Course:
 *   [CSC 160] Introduction to Programming (C++)
 * Date: 13 March 2020
 */

#include <exception>
#include <iostream>
#include <vector>

#ifndef NUMBERSTATS_HH_INCLUDED
#  define NUMBERSTATS_HH_INCLUDED

namespace chapter5 {

class InputException : public std::exception {
  virtual const char *what() const throw() {
    return "Cannot have first input higher than the second.";
  }
};

class NumberStats {
public:
  NumberStats(int in1, int in2) {
    InputException input_exception;
    if (in1 > in2) {
      throw input_exception;
    }
    setNumbers(in1, in2);
    setEvenNumbers(m_firstNumber, m_secondNumber);
    setOddNumbers(m_firstNumber, m_secondNumber);
  }

  void setNumbers(int, int);
  void setEvenNumbers(int, int);
  void setOddNumbers(int, int);
  void generateStatisticalOutput() const;

  void printOdds() const;

  int getFirstNumber() const;
  int getSecondNumber() const;
  std::vector<int> getEvenNumbers() const;
  int getSumOfEvens() const;
  std::vector<int> getOddNumbers() const;
  int getSumOfOddSquares() const;

  void printPowersOneToTen() const;
  void printLetters() const;

protected:
  int m_firstNumber;
  int m_secondNumber;
  std::vector<int> m_evenNumbers;
  std::vector<int> m_oddNumbers;
};
} // namespace chapter5

#endif // !NUMBERSTATS_HH_INCLUDED