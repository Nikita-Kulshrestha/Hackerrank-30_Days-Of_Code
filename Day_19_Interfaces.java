/* The AdvancedArithmetic interface and the method declaration for the abstract divisorSum(n) method are provided for you in the editor below.
Complete the implementation of Calculator class, which implements the AdvancedArithmetic interface. 
The implementation for the divisorSum(n) method must return the sum of all divisors of n. */

import java.io.*;
import java.util.*;

interface AdvancedArithmetic{
   int divisorSum(int n);
}
class Calculator implements AdvancedArithmetic {
    @Override
    public int divisorSum(int n) {
        int sum = 0; // Initialize sum
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) { // Check if 'i' is a divisor of 'n'
                sum += i; // Add the divisor to the sum
            }
        }
        return sum; // Return the computed sum
    }
}

class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();
        
      	AdvancedArithmetic myCalculator = new Calculator(); 
        int sum = myCalculator.divisorSum(n);
        System.out.println("I implemented: " + myCalculator.getClass().getInterfaces()[0].getName() );
        System.out.println(sum);
    }
}
