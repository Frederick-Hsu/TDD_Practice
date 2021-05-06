# File name		: Makefile
# Description	: This script is used to build the project of FirstCppUTest.
# Creator		: Frederique Hsu
# Creation date : Mon.	19 April 2021
# Copyright(C)	2021	All rights reserved.
#

Project = FirstTDDExample

CXX = g++
CXXFLAGS = -g -Wall -std=c++17
INCLUDES = 
LIBS = -lgtest -lpthread

SRC_EXTENSIONS = .c .cpp .c++ .cxx .cc
HDR_EXTENSIONS = .h .hpp .h++ .hxx .hh

CUR_DIR = .
DIRS = $(shell find $(CUR_DIR) -maxdepth 5 -type d)
SOURCES = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(SRC_EXTENSIONS))))
HEADERS = $(foreach dir, $(DIRS), $(wildcard $(addprefix $(dir)/*, $(HDR_EXTENSIONS))))
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

.PHONY : all clean rebuild show

all : $(Project)

$(Project) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS) $(INCLUDES)

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.c++
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	-rm -frv $(Project)
	-rm -frv $(OBJECTS)
	-rm -frv *.out

rebuild : clean all

show :
	@echo "Project = " $(Project)
	@echo "DIRS = " $(DIRS)
	@echo "SOURCES = " $(SOURCES)
	@echo "HEADERS = " $(HEADERS)
	@echo "OBJECTS = " $(OBJECTS)