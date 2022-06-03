/********************************************************************
 *
 * selectionSort.c
 *
 *      This program uses selection sorting algorithm to sort
 *      the input list.
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

#include "sort.h"

/* This function swaps the value of two elements
 * that is passed to this function.
 */
void swapElements(int* a, int* b)
{
    int temp = *a;  /* temporal variable */
    *a = *b;
    *b = temp;
}


/* This function sorts the input list into the sorted
 * one by using selection sort which is implemented
 * from the pseudocodes discussed in the class.
 */
int* selectionSort(int* array, int size)
{
    int i = 0;      /* loop variable */
    int j = 0;      /* loop variable */
    int min = 0;    /* to store minimum element's index */

    for (i = 0; i < size-1; i++)
    {
        min = i;

        /* search for a minimum */
        for (j = i+1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }

        /* swap positions */
        swapElements(&array[min],&array[i]);
    }

    return array;   // returns the sorted array
}
