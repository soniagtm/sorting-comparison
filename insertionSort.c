/********************************************************************
 *
 * insertionSort.c
 *
 *      This program uses insertion sorting algorithm to sort
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


/* This function sorts the input list into the sorted
 * one by using insertion sort which is implemented
 * from the pseudocodes discussed in the class.
 */
int* insertionSort(int* array, int size)
{
    int i = 0;      /* loop variable */
    int j = 0;      /* loop variable */
    int v = 0;      /* to store current unsorted item */

    for (i = 1; i < size; i++)
    {
        v = array[i];
        j = i - 1;      /* starting index in the sorted portion */

        /* find place to insert v */
        while ((j >= 0) && (array[j] > v))
        {
            /* shift item to the right */
            array[j+1] = array[j];
            j--;
        }

        /* place v in the final position */
        array[j+1] = v;
    }

    return array;   // returns the sorted array
}
