/********************************************************************
 *
 * mergeSort.c
 *
 *      This program uses merge sorting algorithm to sort
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

/* This function merges two subarrays where the
 * first subarray is array[l..m] and the second
 * subarray is array[m+1...r].
 */
void merge(int* array, int l, int m, int r)
{
    int n1 = m - l + 1;     /* size of left array */
    int n2 = r - m;         /* size of right array */
    int* leftArray;         /* temporary store left array */
    int* rightArray;        /* temporary store right array */
    int i = 0;              /* loop variable */
    int j = 0;              /* loop variable */
    int k = 0;              /* loop variable */

    /* allocate memory to store elements of left and right array */
    leftArray = calloc(n1,sizeof(int));
    rightArray = calloc(n2,sizeof(int));

    if ((leftArray == NULL) || (rightArray == NULL))
    {
        printf("Error occurred while allocating memory, exiting...");
        exit(0);
    }

    /* split an array into left array and right array*/
    for (k = 0; k < n1; k++)
        leftArray[k] = array[l+k];

    for (k = 0; k < n2; k++)
        rightArray[k] = array[m+1+k];

    k = l; // set k to left index

    while ((i < n1) && (j < n2))
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    /* left array is not empty yet */
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    /* right array is not empty yet */
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    /* free the allocated arrays */
    free(leftArray);
    free(rightArray);
}


/* This function sorts the input list into the sorted
 * one by using merge sort which is implemented from
 * the pseudocodes discussed in the class.
 */
int* mergeSort(int* array, int left, int right)
{
    /* checks if array has more than one element */
    if (left < right)
    {
        int middle = (left + right)/2;      // middle position of the array
        
        /* sort first half of the array */
        mergeSort(array,left,middle);
        
        /* sort second half of the array */
        mergeSort(array,middle+1,right);

        /* merge two halves */
        merge(array,left,middle,right);
    }

    return array;   // returns the sorted array
}
