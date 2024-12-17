/*Complete the Difference class by writing the following:
A class constructor that takes an array of integers as a parameter and saves it to the _elements instance variable.
A computeDifference method that finds the maximum absolute difference between any 2 
numbers in _elements and stores it in the maximumDifference instance variable. */

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


class Difference {
  	private int[] elements;
  	public int maximumDifference;
     
    public Difference(int[] elements) 
    {
        this.elements = elements;
    }

    // Method to compute the maximum absolute difference
    public void computeDifference() 
    {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        // Find the minimum and maximum elements in the array
        for (int i = 0; i < elements.length; i++) 
        {
            if (elements[i] > max) 
            {
                max = elements[i];
            }
            if (elements[i] < min)
            {
                min = elements[i];
            }
        }

        // Compute the maximum absolute difference
        maximumDifference = Math.abs(max - min);
    }


} // End of Difference class

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        Difference difference = new Difference(a);

        difference.computeDifference();

        System.out.print(difference.maximumDifference);
    }
}