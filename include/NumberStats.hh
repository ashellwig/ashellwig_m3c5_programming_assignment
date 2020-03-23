/**
 * @file NumberStats.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains the class prototype of the functions required to
 * compute the data requested in the assignment.
 * @date 2020-03-13
 *
 * Assignment: Module 3 Chapter 5 Programming Assignment
 * Description: This file contains the class prototype of `NumberStats`
 *   functions, allowing us easier implementation and testing utilization.
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
void promptUserInput(int &, int &);
void printOdds(int, int);
int calcSumOfEvens(int, int);
int calcSumOfOddSquares(int, int);

void printPowersOneToTen();
void printLetters();

class InputException : public std::exception {
public:
  virtual const char *what() const throw() {
    return "Cannot have first input higher than the second.";
  }
};
} // namespace chapter5

#endif // !NUMBERSTATS_HH_INCLUDED