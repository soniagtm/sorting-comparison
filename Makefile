# This makefile is intended to build the five programs for
# sorting comparison project.
#
# Created by Chayathit   Rattanapokil  (Peach)  ID 63070503405
#	     Sonia       Gautam        (Sonia)  ID 63070503410
#	     Tamonwan    Boonpa        (Nice)   ID 63070503418
#            Theeranont  Ruchiyakorn   (Peak)   ID 63070503420
#            Fasai       Sae-Tae       (Atom)   ID 63070503436 
#
# 02 October 2021
#

ifeq ($(OSTYPE),WINDOWS)
	EXECEXT =.exe
	COMP	=__MINGCC__
	PLATFORM	=mingw
else
	EXECEXT =
	COMP	=__GCC__
	PLATFORM	=linux
endif

EXECUTABLES = sorting

all : $(EXECUTABLES)

mainProgram.o : mainProgram.c sort.h
	gcc -c mainProgram.c

insertionSort.o : insertionSort.c sort.h
	gcc -c insertionSort.c

selectionSort.o : selectionSort.c sort.h
	gcc -c selectionSort.c

mergeSort.o : mergeSort.c sort.h
	gcc -c mergeSort.c

quickSort.o : quickSort.c sort.h
	gcc -c quickSort.c

sorting : mainProgram.o insertionSort.o selectionSort.o mergeSort.o quickSort.o
	gcc -o sorting mainProgram.o insertionSort.o selectionSort.o mergeSort.o quickSort.o

clean :
	-rm *.o
	-rm sorting
