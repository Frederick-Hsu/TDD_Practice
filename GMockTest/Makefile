# File			: Makefile
# Description	: This script is used to guide how to build the project.
# Creator		: Frederick Hsu
# Creation date	: Wed.	07 Oct. 2020
#

EXECUTABLE = GMockTest

CURRENT_DIR = .
SRCEXTS = .cpp .cc .cxx .c++
HDREXTS = .h .hpp

DIRS = $(shell find $(CURRENT_DIR) -maxdepth 4 -type d)
SOURCES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*$(SRCEXTS)))
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))

CC = g++
LIBS = -lgmock -lgtest -lpthread
MODE = Debug
PROF =

CFLAGS := -Wall
ifeq ($(MODE), Debug)
	CFLAGS += -g2
else
	CFLAGS += -O2
endif

STD_FLAGS = -std=c++17
CFLAGS += $(LIBS) $(STD_FLAGS) $(PROF)

.PHONY : all clean show rebuild

all : $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "Removing all linked and compiled files ... "
	@find . -name ".o" -exec rm -frv {} \;
	@-rm -frv $(EXECUTABLE)

show :
	@echo "DIRS : " $(DIRS)
	@echo "SOURCES : " $(SOURCES)
	@echo "OBJECTS : " $(OBJECTS)
	@echo "EXECUTABLE : " $(EXECUTABLE)

rebuild : clean all