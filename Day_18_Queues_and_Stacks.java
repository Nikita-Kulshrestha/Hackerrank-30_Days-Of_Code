/*To solve this challenge, we must first take each character in , enqueue it in a queue, 
and also push that same character onto a stack. Once that's done, 
we must dequeue the first character from the queue and pop the top character off the stack,
then compare the two characters to see if they are the same; as long as the characters match,
we continue dequeueing, popping, and comparing each character until our containers are empty (a non-match means  isn't a palindrome). */
import java.io.*;
import java.util.*;

public class Solution 
{
     // Instance variables for stack and queue
    private Stack<Character> stack = new Stack<>();
    private Queue<Character> queue = new LinkedList<>();

    // Method to push a character onto a stack
    void pushCharacter(char ch) 
    {
        stack.push(ch);
    }

    // Method to enqueue a character in a queue
    void enqueueCharacter(char ch) 
    {
        queue.add(ch);
    }

    // Method to pop a character from the stack
    char popCharacter() 
    {
        return stack.pop();
    }

    // Method to dequeue a character from the queue
    char dequeueCharacter()
    {
        return queue.poll();
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        scan.close();

        // Convert input String to an array of characters:
        char[] s = input.toCharArray();

        // Create a Solution object:
        Solution p = new Solution();

        // Enqueue/Push all chars to their respective data structures:
        for (char c : s) {
            p.pushCharacter(c);
            p.enqueueCharacter(c);
        }

        // Pop/Dequeue the chars at the head of both data structures and compare them:
        boolean isPalindrome = true;
        for (int i = 0; i < s.length/2; i++) {
            if (p.popCharacter() != p.dequeueCharacter()) {
                isPalindrome = false;                
                break;
            }
        }

        //Finally, print whether string s is palindrome or not.
        System.out.println( "The word, " + input + ", is " 
                           + ( (!isPalindrome) ? "not a palindrome." : "a palindrome." ) );
    }
}