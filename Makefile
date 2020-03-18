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
DOXYGEN := /usr/bin/doxygen
RM := /usr/bin/rm
mv := /usr/bin/mv

# === VARIABLES ===
# --- Program Variables ---
SRC := $(wildcard src/*.cxx)
INCLUDES := include
OBJS := $(addprefix out/obj/, $(notdir $(SRC:.cxx=.o)))
CXXFLAGS := \
	-c \
	-std=gnu++2a \
	-Wall \
	-Wextra \
	-ggdb \
	-D_DEBUG=1
LFLAGS := \
	-std=gnu++2a \
	-ggdb \

# --- Test Variables ---
TEST_PROGRAM := out/bin/test
TEST_SRC := test/catch_main.cxx src/NumberStats.cxx
TEST_INCLUDES := -isystem include/catch2 -Iinclude
TEST_OBJS := $(addprefix out/obj/test/, $(notdir $(TEST_SRC:.cxx=.o)))
TEST_OBJS += out/obj/test/NumberStats.o
TEST_CXXFLAGS := \
	-std=c++11 \
	-ggdb
TEST_LFLAGS := -std=c++11

# -- Documentation Variables
DOC_DOXYGEN_OUT := out/doc/doxygen
DOC_DOXYGEN_SUBDIRS := out/doc/doxygen/html out/doc/doxygen/latex out/doc/doxygen/man out/doc/doxygen/rtf

# === Rules ===
# --- Chains ---
all: doc-doxygen-build user-doc-release debug unit-test clean
clean: user-doc-clean doc-doxygen-clean
	$(RM) -f out/obj/*.o
	$(RM) -f out/obj/test/*.o
clean-all: clean user-doc-clean-all
	$(RM) -f out/bin/*.bin
	$(RM) -f out/bin/test
	$(RM) -f out/doc/user_docs.pdf

# --- Debug Build ---
debug: $(OBJS)
	$(CXX) $(LFLAGS) -o $(PROGRAM) $(OBJS) -I$(INCLUDES)

out/obj/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDES)

# --- Tests ---
test: debug
	$(CXX) $(CXXFLAGS) \
		-c src/NumberStats.cxx \
		-o out/obj/test/NumberStats.o \
		-I$(INCLUDES)

	$(CXX) $(TEST_CXXFLAGS) \
		-c test/catch_main.cxx \
		-o out/obj/test/catch_main.o \
		$(TEST_INCLUDES)

	$(CXX) $(TEST_CXXFLAGS) \
		-c test/TestCase.cxx \
		-o out/obj/test/TestCase.o \
		$(TEST_INCLUDES) -I$(INCLUDES)

	$(CXX) $(TEST_LFLAGS) -o out/bin/test.bin \
		out/obj/test/NumberStats.o \
		out/obj/test/catch_main.o \
		out/obj/test/TestCase.o \
		$(TEST_INCLUDES) -I$(INCLUDES)

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
doc-doxygen-build:
	$(DOXYGEN) Doxyfile
doc-doxygen-clean:
	$(foreach docsubdir,$(DOC_DOXYGEN_SUBDIRS),$(RM) -rf $(docsubdir);)
user-doc-release: user-doc-build user-doc-clean
	cp -R doc/user_docs/main.pdf out/doc/user_docs.pdf
user-doc-build:
	$(MAKE) -C doc/user_docs user-doc-build
user-doc-clean:
	$(MAKE) -C doc/user_docs user-doc-clean
user-doc-clean-all:
	$(MAKE) -C doc/user_docs user-doc-clean-all
