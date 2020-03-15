# vim: set ts=2 sw=2 ft=sh:
## Module 3 Chapter 5 Program
## Ashton S. Hellwig
## Date: 13 March 2020
## Instructor: Jeffrey Hemmes
## Course:
##   [CSC160] Introduction to Programming Langauges (C++)
##

# --- Variables ---
PROGRAM := out/bin/ashellwig_m3c5_programming_assignment.bin
CXX := /usr/bin/g++
RM := /usr/bin/rm

CXXFLAGS := -c \
	-std=c++2a \
	-Wall \
	-Wextra \
	-ggdb
LFLAGS := -std=c++2a -ggdb

TEST_CXXFLAGS := -std=c++2a -Wall -Iinclude/catch2 -Iinclude
TEST_LFLAGS := -std=c++2a -Wall -o out/test/bin/test.bin --coverage

SRC := $(wildcard src/*.cxx)
INCLUDES := include
OBJS := $(addprefix out/obj/, $(notdir $(SRC:.cxx=.o)))

# --- Rules ---
all: debug user-doc-release clean
clean: user-doc-clean
	$(RM) -f out/obj/*.o
	$(RM) -f out/test/obj/*.o
clean-all: clean user-doc-clean-all
	$(RM) -f out/bin/*.bin
	$(RM) -f out/test/bin/*.bin
	$(RM) -f out/doc/user_docs.pdf
	$(RM) -f *.gcda
	$(RM) -f *.gcno

# Debug Build
debug: $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(PROGRAM)
out/obj/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDES)

# Tests
test: clean debug
	$(CXX) $(TEST_CXXFLAGS) \
		-c src/NumberStats.cxx -o out/test/obj/NumberStats.o
	$(CXX) $(TEST_CXXFLAGS) -c test/catch_main.cxx -o out/test/obj/catch_main.o
	$(CXX) $(TEST_LFLAGS) out/test/obj/NumberStats.o \
		out/test/obj/catch_main.o test/TestCase.cxx
	./out/test/bin/test.bin --reporter console

# Doc
user-doc-release: user-doc-build user-doc-clean
	cp -R doc/user_docs/main.pdf out/doc/user_docs.pdf
user-doc-build:
	$(MAKE) -C doc/user_docs user-doc-build
user-doc-clean:
	$(MAKE) -C doc/user_docs user-doc-clean
user-doc-clean-all:
	$(MAKE) -C doc/user_docs user-doc-clean-all
