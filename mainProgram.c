/********************************************************************
 *
 * mainProgram.c
 *
 *      This program is a main program for sorting comparison
 *      project. This program repeatedly ask the user which
 *      algorithm he/she wants to test.
 *
 *      Types of sorting algorithm consist of
 *
 *          [1] - Insertion sort
 *          [2] - Selection sort
 *          [3] - Merge sort
 *          [4] - Quick sort
 *          [5] - Exit
 *
 *      When the user has selected his/her option, the program
 *      will redirect to other program which handles each type
 *      of the sorting algorithms.
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

/* This function checks if the input contains only
 * digits or not.
 */
int checkDigit(char* input)
{
    int i = 0;          /* loop variable */
    int result = 1;     /* return value */

    for (i = 0; i < strlen(input)-1; i++)
    {
        if (isdigit(input[i]) == 0)
        {
            result = 0;
            break;
        }
    }

    return result;  // 1 if only digits are found
                    // 0 if non-digit character is found
}

/* This function prints all the elements in the array
 * which is passed to this function as an argument.
 */
void printArray(int* array, int size, char text[])
{
    int i = 0;      /* loop variable */

    /* print all elements in the list */
    printf("\nElements of the array %s sorting\n",text);

    for (i = 0; i < size; i++)
    {
        printf("%d\t",array[i]);
    }

    printf("\n");
}

/* This function asks the size of the list and generates
 * random integers between 0 to 1,000,000 for the list.
 */
int* getList(int* array, int choice, int* size)
{
    char stringInput[64];   /* get input from the user */
    int number = 0;         /* temporary stores list size */
    int i = 0;              /* loop variable */

    while ((choice > 0) && (choice < 5) && (*size < 1))
    {
        *size = 0;
        memset(stringInput,0,sizeof(stringInput));
        printf("\nEnter the number of elements: ");
        fgets(stringInput,sizeof(stringInput),stdin);

        if ((checkDigit(stringInput) != 0) && (stringInput[0] != '0'))
        {
            sscanf(stringInput,"%d",&number);
            *size = number;

            /* allocate memory to store the integer list */
            array = calloc(*size,sizeof(int));

            if (array == NULL)
            {
                printf("Error occurred while allocating memory, exiting...");
                exit(0);
            }

            /* get each elements of the list randomly */
            srand(time(0));

            for (i = 0; i < *size; i++)
            {
                array[i] =  rand() % 1000000;
            }

            /* print the unsorted list */
            printArray(array,*size,"before");
        }
        else
        {
            printf("\nPlease enter a postive integer\n");
        }
    }

    return array;   // returns the list of random integers                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}

/* This function is the main function of the sorting
 * comparison project. This function shows the menu 
 * and asks the user for the algorithm he/she wants
 * to test. Then, it calls the responsible functions
 * until the user selects exit.
 */
int main(int argc, char* argv[])
{
    char algorithm[4][16] = {"Insertion","Selection","Merge","Quick"};
                                /* store names of each algorithm */
    char stringInput[64];       /* get input from the user */
    double runningTime = 0;     /* stores executing time */
    int* array;                 /* store integer list */
    int choice = 0;             /* stores selected option */
    int size = 0;               /* stores list size */
    int i = 0;                  /* loop variable */
    time_t t;                   /* to count running time */

    while (choice != 5)
    {
        /* reset values */
        runningTime = 0;
        choice = 0;
        size = 0;
        memset(stringInput,0,sizeof(stringInput));
        
        /* print menu */
        printf("\n************************************************");
        printf("\n\t       Sorting algorithms\n");
        printf("************************************************\n\n");
        printf("     [1]    %s sort\n",algorithm[0]);
        printf("     [2]    %s sort\n",algorithm[1]);
        printf("     [3]    %s sort\n",algorithm[2]);
        printf("     [4]    %s sort\n",algorithm[3]);
        printf("     [5]    Exit\n\n");
        printf("************************************************\n");

        /* get user's choice */
        printf("Which sorting algorithm do to want to use? ");
        fgets(stringInput,sizeof(stringInput),stdin);
        sscanf(stringInput,"%d",&choice);
        printf("************************************************\n");

        /* create new random integer list*/
        array = getList(array,choice,&size);
        
        /* set t to the starting time */
        t = clock();

        switch (choice)
        {
            case 1:
                array = insertionSort(array,size);
                break;
            case 2:
                array = selectionSort(array,size);
                break;
            case 3:
                array = mergeSort(array,0,size-1);
                break;
            case 4:
                array = quickSort(array,0,size-1);
                break;
            case 5:
                printf("\n*****************  Goodbye!  *******************\n");
                exit(0);
            default:
                printf("\nPlease enter only positive integer between 1 and 5\n");
        }

        /* set t to the time taken to sort the list by selected algorithm */
        t = clock() - t;

        /* print output and execution time */
        if ((choice > 0) && (choice < 5))
        {
            printArray(array,size,"after");
            runningTime = ((double)t)/CLOCKS_PER_SEC;   // time taken in second unit
            printf("\n* %s sorting algorithm took %f seconds to execute a sorted list of size %d\n",algorithm[choice-1],runningTime,size);
            free(array);
        }
    }

    return 0;
}
