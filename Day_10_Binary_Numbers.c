/*Given a base-10 integer,n , convert it to binary (base-2). Then find and print the base-10 integer 
denoting the maximum number of consecutive 1's in n's binary representation.
 When working with different bases, it is common to show the base as a subscript.*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



int main()
{
    int n = parse_int(ltrim(rtrim(readline())));
    scanf("%d", &n); // Read the integer input
    

    int result = countMaxConsecutiveOnes(n); // Get the maximum consecutive 1s
    printf("%d\n", result); // Print the result

    return 0;

    return 0;
}

// Function to count the maximum consecutive 1s in binary representation
int countMaxConsecutiveOnes(int n) {
    int maxCount = 0;
    int currentCount = 0;

    // Iterate through each bit of the number
    while (n > 0) {
        if (n % 2 == 1) { // If the least significant bit is 1
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0; // Reset count when a 0 is encountered
        }
        n /= 2; // Right-shift the number (divide by 2)
    }

    return maxCount;
}


char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
