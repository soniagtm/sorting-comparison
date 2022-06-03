/********************************************************************
 *
 * quickSort.c
 *
 *      This program uses quick sorting algorithm to sort
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

/* This function places values smaller than pivot to
 * the left and the greater elements to the right of 
 * the pivot.
 */
int hoarePartition(int* array, int left, int right)
{
    int p = array[left];    /* stores pivot value */
    int i = left;           /* stores leftmost index */
    int j = right + 1;      /* stores rightmost index */

    do
    {
        /* scan left to right */
        do
        {
            i++;
            if (i == right)
                break;
        } while (array[i] < p);

        /* scan right to left */
        do
        {
            j--;
            if (j == left)
                break;
        } while (array[j] > p);

        /* swap positions */
        swapElements(&array[i],&array[j]);

    } while (i < j);

    swapElements(&array[i],&array[j]);     // undo last step
    
    /* put pivot in the splitting position */
    swapElements(&array[left],&array[j]);

    return j;   // the split position
}


/* This function sorts the input list into the sorted
 * one by using quick sort which is implemented from
 * the pseudocodes discussed in the class.
 */
int* quickSort(int* array, int left, int right)
{
    int s = 0;      /* stores the splitting position based on pivot */

    /* checks if left index is less than right index */
    if (left < right)
    {
        s = hoarePartition(array,left,right);
        quickSort(array,left,s-1);
        quickSort(array,s+1,right);
    }

    return array;   // returns the sorted array
}
