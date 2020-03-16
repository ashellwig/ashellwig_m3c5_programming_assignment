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
mv := /usr/bin/mv

CXXFLAGS := \
	-c \
	-std=gnu++2a \
	-Wall \
	-Wextra \
	-ggdb \
	-D_DEBUG=1 \
	-fprofile-arcs \
	-ftest-coverage \
	--coverage
LFLAGS := \
	-std=gnu++2a \
	-ggdb \
	--coverage \
	-fprofile-arcs \
	-ftest-coverage

TEST_CXXFLAGS := \
	-std=c++2a \
	-Wall
TEST_LFLAGS := $(LFLAGS)
TEST_INCLUDES := -Iinclude/catch2 -Iinclude

SRC := $(wildcard src/*.cxx)
INCLUDES := include
OBJS := $(addprefix out/obj/, $(notdir $(SRC:.cxx=.o)))

# --- Rules ---
all: debug test user-doc-release clean
clean: user-doc-clean
	$(RM) -f out/obj/*.gcda
	$(RM) -f out/obj/*.gcno
	$(RM) -f out/obj/*.gcov
	$(RM) -f out/obj/gmon.out
	$(RM) -f out/obj/*.o
	$(RM) -f gmon.out
clean-all: clean user-doc-clean-all
	$(RM) -f out/bin/*.bin
	$(RM) -f out/test/bin/*.bin
	$(RM) -f out/doc/user_docs.pdf

# Debug Build
debug: $(OBJS)
	$(CXX) $(LFLAGS) -o $(PROGRAM) $(OBJS) -I$(INCLUDES)

out/obj/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDES)

# Tests
coverage:
	gcov -o out/obj -r src/main.cxx src/NumberStats.cxx
	lcov -c -b $(shell pwd) --no-external -d out/obj -o out/obj/cov.info
	genhtml out/obj/cov.info -o out/doc
test: debug
	$(CXX) $(CXXFLAGS) -c src/NumberStats.cxx -o out/obj/NumberStats.o $(TEST_INCLUDES)
	$(CXX) $(TEST_CXXFLAGS) -c test/catch_main.cxx -o out/obj/catch_main.o $(TEST_INCLUDES)
	$(CXX) $(TEST_CXXFLAGS) -c test/TestCase.cxx -o out/obj/TestCase.o $(TEST_INCLUDES)
	$(CXX) $(TEST_LFLAGS) -fno-profile-arcs -fno-test-coverage \
		-o out/bin/test.bin out/obj/NumberStats.o \
		out/obj/catch_main.o out/obj/TestCase.o $(TEST_INCLUDES)
unit-test: test
	./out/bin/test.bin \
		--success \
		--reporter console \
		--use-colour yes \
		--abort \
		--durations yes \
		--filenames-as-tags \
		--verbosity normal


# Doc
user-doc-release: user-doc-build user-doc-clean
	cp -R doc/user_docs/main.pdf out/doc/user_docs.pdf
user-doc-build:
	$(MAKE) -C doc/user_docs user-doc-build
user-doc-clean:
	$(MAKE) -C doc/user_docs user-doc-clean
user-doc-clean-all:
	$(MAKE) -C doc/user_docs user-doc-clean-all
