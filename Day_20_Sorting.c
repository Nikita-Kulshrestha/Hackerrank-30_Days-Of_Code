/* Print the following three lines of output:

Array is sorted in numSwaps swaps.
where numSwaps is the number of swaps that took place.
First Element: firstElement
where firstElement is the first element in the sorted array.
Last Element: lastElement
where lastElement is the last element in the sorted array.*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

int main() {
    // Read the size of the array
    int n = parse_int(ltrim(rtrim(readline())));

    // Read the array elements
    char** a_temp = split_string(rtrim(readline()));
    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        *(a + i) = parse_int(*(a_temp + i));
    }

    // Bubble sort implementation
    int numSwaps = 0;
    for (int i = 0; i < n; i++) {
        int numberOfSwaps = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                // Swap adjacent elements
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                numberOfSwaps++;
            }
        }
        numSwaps += numberOfSwaps;

        // If no swaps occurred, array is sorted
        if (numberOfSwaps == 0) {
            break;
        }
    }

    // Print the required outputs
    printf("Array is sorted in %d swaps.\n", numSwaps);
    printf("First Element: %d\n", a[0]);
    printf("Last Element: %d\n", a[n - 1]);

    // Free allocated memory
    free(a);
    free(a_temp);

    return 0;
}

// Utility function: Read a line from standard input
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
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    return data;
}

// Utility function: Trim leading whitespace
char* ltrim(char* str) {
    if (!str) return NULL;
    while (*str != '\0' && isspace(*str)) {
        str++;
    }
    return str;
}

// Utility function: Trim trailing whitespace
char* rtrim(char* str) {
    if (!str) return NULL;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

// Utility function: Split a string into an array of strings
char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }

    return splits;
}

// Utility function: Parse a string to an integer
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
    return value;
}
