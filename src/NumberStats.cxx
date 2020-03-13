/**
 * @file Number Stats.cxx
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
 * Date: 13 March 2020
 */

#include "../include/NumberStats.hh"
#include "../include/debug.hh"
#include <iostream>
#include <vector>

using namespace chapter5;

void NumberStats::setNumbers(int, int) {}

void NumberStats::setEvenNumbers(int, int) {}

void NumberStats::setOddNumbers(int, int) {}

void NumberStats::generateStatisticalOutput(NumberStats *numstats) {}

std::vector<int> NumberStats::getEvenNumbers() { return this->m_evenNumbers; }

std::vector<int> NumberStats::getOddNumbers() { return this->m_oddNumbers; }

void NumberStats::printPowersOneToTen() {}

void NumberStats::printLetters() {}