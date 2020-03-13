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

#include <ios>
#include <vector>

#ifndef NUMBERSTATS_HH_INCLUDED
#define NUMBERSTATS_HH_INCLUDED

namespace chapter5 {
class NumberStats {
public:
  NumberStats(int &in1, int &in2) : m_inputOne(in1), m_inputTwo(in2) {}

  void setNumbers(int, int);
  void setEvenNumbers(int, int);
  void setOddNumbers(int, int);
  void generateStatisticalOutput(NumberStats *);

  std::vector<int> getEvenNumbers();
  std::vector<int> getOddNumbers();

  void printPowersOneToTen();
  void printLetters();

private:
  int &m_inputOne;
  int &m_inputTwo;
  int m_firstNumber;
  int m_secondNumber;
  std::vector<int> m_evenNumbers;
  std::vector<int> m_oddNumbers;
};
} // namespace chapter5

#endif // !NUMBERSTATS_HH_INCLUDED