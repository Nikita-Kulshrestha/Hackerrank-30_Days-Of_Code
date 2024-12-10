/*
Complete the code in the editor below. The variables , , and  are already declared and initialized for you. You must:
a. Declare  variables: one of type int, one of type double, and one of type String.
b. Read  lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your  variables.
c. Use the  operator to perform the following operations:
        1. Print the sum of  plus your int variable on a new line.
        2. Print the sum of  plus your double variable to a scale of one decimal place on a new line.
        3. Concatenate  with the string you read as input and print the result on a new line.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int inputInt;
    double inputDouble;
    char inputString[100];

    // Read and save an integer, double, and String to your variables.
    scanf("%d", &inputInt);
    scanf("%lf", &inputDouble);
    getchar();
    fgets(inputString, sizeof(inputString), stdin);
    // Print the sum of both integer variables on a new line.
    printf("%d\n", i + inputInt);
    // Print the sum of the double variables on a new line.
    printf("%.1f\n", d + inputDouble);
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    printf("%s", s);
    printf("%s", inputString);

    return 0;
}