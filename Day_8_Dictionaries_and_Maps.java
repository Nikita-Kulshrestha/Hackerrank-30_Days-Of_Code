/* Task
Given n names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers. 
You will then be given an unknown number of names to query your phone book for. 
For each  queried, print the associated entry from your phone book on a new line in the form name=phoneNumber; 
if an entry for  is not found, print Not found instead.
Note: Your phone book should be a Dictionary/Map/HashMap data structure.*/

import java.util.HashMap; 
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create a HashMap to store the phone book
        // used concepts of generics and collections
        HashMap<String, String> phoneBook = new HashMap<>();

        // Read the number of phone book entries
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        //adding entries
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            String phone = scanner.next();
            phoneBook.put(name, phone);
        }

        //Process queries until the end of input
        while (scanner.hasNext()) {
            String query = scanner.next();
            if (phoneBook.containsKey(query)) {
                System.out.println(query + "=" + phoneBook.get(query));
            } else {
                System.out.println("Not found");
            }
        }

        scanner.close(); 
        // Close the scanner
    }
}
