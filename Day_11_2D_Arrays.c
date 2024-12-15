/* Given a 6x6 2D array, calculate the maximum sum of an hourglass shape. An hourglass is defined as the sum of array elements in the following pattern:
a b c  
  d  
e f g  */

#include <stdio.h>
#include <limits.h> // For INT_MIN

int main() {
    int arr[6][6];

    // Reading the 6x6 array
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int max_sum = INT_MIN;

    // Iterating over possible hourglasses
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Calculating hourglass sum
            int hourglass_sum = arr[i][j] + arr[i][j+1] + arr[i][j+2]
                                              + arr[i+1][j+1]
                                + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            // Update max_sum if the current hourglass_sum is greater
            if (hourglass_sum > max_sum) {
                max_sum = hourglass_sum;
            }
        }
    }

    // Print the maximum hourglass sum
    printf("%d\n", max_sum);

    return 0;
}
