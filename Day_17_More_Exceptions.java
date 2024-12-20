/* Write a Calculator class with a single method: int power(int,int). 
The power method takes two integers, n and p, as parameters and returns the integer result of n^p. 
If either n or p is negative, then the method must throw an exception 
with the message: n and p should be non-negative. */

import java.util.*;
import java.io.*;

class Calculator {

    // Method to calculate n^p and throw an exception if inputs are invalid
    int power(int n, int p) throws Exception {
        if (n < 0 || p < 0) {
            // Throw an exception if n or p is negative
            throw new Exception("n and p should be non-negative");
        }
        // Use Math.pow for exponentiation and cast result to int
        return (int) Math.pow(n, p);
    }
}
//Write your code here

class Solution{

    public static void main(String[] args) {
    
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
        
            int n = in.nextInt();
            int p = in.nextInt();
            Calculator myCalculator = new Calculator();
            try {
                int ans = myCalculator.power(n, p);
                System.out.println(ans);
            }
            catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        in.close();
    }
}
