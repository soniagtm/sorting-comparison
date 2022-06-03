/********************************************************************
 *
 * sort.h
 *
 *      This header file defines functions that are located in 
 *      sorting programs used for sorting comparison project.
 * 
 *      Created by Chayathit   Rattanapokil  (Peach)  ID 63070503405
 *		           Sonia       Gautam 	     (Sonia)  ID 63070503410
 *		           Tamonwan    Boonpa 	     (Nice)   ID 63070503418
 *                 Theeranont  Ruchiyakorn   (Peak)   ID 63070503420
 *                 Fasai       Sae-Tae       (Atom)   ID 63070503436 
 * 
 *      02 October 2021
 *
 ********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* This function swaps the value of two elements
 * that is passed to this function.
 */
void swapElements(int* a, int* b);

/* This function sorts the input list into the sorted
 * one by using insertion sort which is implemented
 * from the pseudocodes discussed in the class.
 */
int* insertionSort(int* array, int size);

/* This function sorts the input list into the sorted
 * one by using selection sort which is implemented
 * from the pseudocodes discussed in the class.
 */
int* selectionSort(int* array, int size);

/* This function sorts the input list into the sorted
 * one by using merge sort which is implemented from
 * the pseudocodes discussed in the class.
 */
int* mergeSort(int* array, int left, int right);

/* This function sorts the input list into the sorted
 * one by using quick sort which is implemented from
 * the pseudocodes discussed in the class.
 */
int* quickSort(int* array, int left, int right);
