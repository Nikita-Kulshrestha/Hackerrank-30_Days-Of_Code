/* Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:
If the book is returned on or before the expected return date, no fine will be charged.
If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, the fine is 15 Hackos multiplied by the number of days late.
If the book is returned after the expected return month but still within the same calendar year as the expected return date, the fine is 500 Hackos multiplied by the number of months late.
If the book is returned after the calendar year in which it was expected, there is a fixed fine of 10,000 Hackos.*/

#include <stdio.h>

int main() {
    int actualDay, actualMonth, actualYear;
    int dueDay, dueMonth, dueYear;

    // Input the actual and due return dates
    scanf("%d %d %d", &actualDay, &actualMonth, &actualYear);
    scanf("%d %d %d", &dueDay, &dueMonth, &dueYear);

    int fine = 0;

    if (actualYear > dueYear) {
        // Returned in a later year
        fine = 10000;
    } else if (actualYear == dueYear) {
        if (actualMonth > dueMonth) {
            // Returned in the same year but a later month
            fine = 500 * (actualMonth - dueMonth);
        } else if (actualMonth == dueMonth && actualDay > dueDay) {
            // Returned in the same month and year but a later day
            fine = 15 * (actualDay - dueDay);
        }
    }

    // Print the fine
    printf("%d\n", fine);

    return 0;
}