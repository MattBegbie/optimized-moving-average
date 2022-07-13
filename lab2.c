#include <stdio.h>
#include <stdlib.h>
#define N 10
int main(){
    int n = 0, newI = 0, denominator = 0, sum = 0, bufferWindow[N] = {0}; //declare variables new = indexNumber, n = average window
    printf("Enter the number of values to be averaged over (n): ");                 //prompt for number to be averaged over
    scanf("%d", &n);                                                                //scan number to be averaged over
    while (1){                                                                      //enter continuous loop
        printf("Enter a value: ");                                                  //prompt for new value
        scanf("%d", &bufferWindow[newI%N]);                                         //scan new number as a number in the array (pos = indexNumber % size of array)
        sum += bufferWindow[newI%N];                                                //add new number to sum
        (newI < n) ? denominator++ : (sum -= bufferWindow[(newI-n)%N]);             //ternary expression, if index is less than n, increment denominator, otherwise remove old number
        newI++;                                                                     //increment index                          
        printf("Buffered Contents: ");                                              //print 
        for (int i = 0; i < N; i++) printf("%d\t", bufferWindow[i]);
        printf("\nNumber of Values Entered: %d \tAverage over: %d \tAverage: %.2f\n\n", newI, denominator, (double) sum/denominator); //print important values, calculate average
    } //end of loop
    return EXIT_SUCCESS;
} //end of main