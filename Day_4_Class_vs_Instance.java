/* Write a Person class with an instance variable, age , and a constructor that takes an integer,initialAge , as a parameter. 
The constructor must assign initialAge to age after confirming the argument passed as initialAge is not negative; if a negative argument is passed as initialAge , 
the constructor should set  to  and print Age is not valid, setting age to 0.. In addition, you must write the following instance methods:
        yearPasses() should increase the age instance variable by .
        amIOld() should perform the following conditional actions:
            If age<13, print You are young..
            If age>=13 and age<18, print You are a teenager..
            Otherwise, print You are old..
To help you learn by example and complete this challenge, much of the code is provided for you,
 but you'll be writing everything in the future. The code that creates each instance of your Person class is in the main method. 
*/

import java.util.Scanner;

public class Person {
    private int age; // Instance variable

    // Constructor
    public Person(int initialAge) {
        if (initialAge >= 0) {
            this.age = initialAge;  
        } else {
            this.age = 0;
            System.out.println("Age is not valid, setting age to 0.");
        }
    }

    // Method to determine age category
    public void amIOld() {
        if (age < 13) {
            System.out.println("You are young.");   
        } else if (age >= 13 && age < 18) {
            System.out.println("You are a teenager."); 
        } else {
            System.out.println("You are old."); 
        }
    }

    // Method to increase age by 1
    public void yearPasses() {
        age++;
    }

    // Main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read number of test cases
        int T = sc.nextInt(); 

        // Ensure T is within a reasonable range
        if (T < 1 || T > 100) {
            System.out.println("Invalid number of test cases.");
            return;
        }

        // Loop through each test case
        for (int i = 0; i < T; i++) {
            int age = sc.nextInt(); // Input age for each test case

            // Create a Person object
            Person p = new Person(age);

            // Print age category
            p.amIOld();

            // Increment age 3 times
            for (int j = 0; j < 3; j++) {
                p.yearPasses();
            }

            // Print age category after increment
            p.amIOld();
            System.out.println();
        }

        sc.close(); // Close scanner
    }
}

