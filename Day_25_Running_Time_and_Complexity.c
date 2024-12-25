/* A prime is a natural number greater than 1 that has no positive divisors other than 1 and itself. 
Given a number,n, determine and print whether it is Prime or Not prime.Note: If possible, try to come up with a 𝑂( root 𝑛) primality algorithm, 
or see what sort of optimizations you come up with for an O(n) algorithm. Be sure to check out the Editorial after submitting your code.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false; // Numbers <= 1 are not prime
    }
    if (n <= 3) {
        return true; // 2 and 3 are prime numbers
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; // Exclude multiples of 2 and 3
    }

    // Check for divisors up to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T); // Number of test cases

    while (T--) {
        int n;
        scanf("%d", &n); // Input number for each test case
        if (isPrime(n)) {
            printf("Prime\n");
        } else {
            printf("Not prime\n");
        }
    }

    return 0;
}
