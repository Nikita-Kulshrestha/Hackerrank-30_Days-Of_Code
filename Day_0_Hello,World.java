/* To complete this challenge, you must save a line of input from stdin to a variable, print Hello, World. on a single line, 
and finally print the value of your variable on a second line. */

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); 
        // Create a Scanner to read from stdin
        String inputString = scanner.nextLine(); 
        // Read a line of input from stdin; this line reads the full input and not only the first word
    
        // Next, Printing the required output
        System.out.println("Hello, World.");
        System.out.println(inputString);
    }
}
