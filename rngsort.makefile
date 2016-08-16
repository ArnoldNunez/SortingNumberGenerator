# Makefile for Random Number Generator (for use with Sorting algorithms)

#------------------- Variables -----------------------#

# The c compiler:
CC = gcc

# Compiler Flags:
# -g Adds debug info to exe
# -Wall Turns on most compiler warnings
CFLAGS = --std=c11 -g -Wall

#Build target executable (exe name)
TARGET = rngsort

#------------------------------------------------------#


# ------------------- Build Tree ---------------------#

# Default target entry (usually all or default)
all : $(TARGET)

# To create the exe we compile and link all obj files
$(TARGET) : main.o
	$(CC) $(CFLAGS) main.o -o $(TARGET)
	
# To compile main obj file we need to compile and assemble but not link main.c
main.o : main.c
	$(CC) $(CFLAGS) -c main.c
	
#-------------------------------------------------------#

#----------------- Cleaning up -----------------------#

# To start over from scratch, use make with
# clean as the target. This removes the exe file,
# as well as old .o files nd *~ backup files:
#
clean:
	$(RM) $(TARGET) *.o *~

#--------------------------------------------------------#