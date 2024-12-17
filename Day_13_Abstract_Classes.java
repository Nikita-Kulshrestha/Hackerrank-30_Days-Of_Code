/* Given a Book class and a Solution class, write a MyBook class that does the following:
    a. Inherits from Book
    b. Has a parameterized constructor taking these 3 parameters:
        string title
        string author
        int price
    c. Implements the Book class' abstract display() method so it prints these 3 lines:
        Title:, a space, and then the current instance's title.
        Author:, a space, and then the current instance's author.
        Price:, a space, and then the current instance's price. */
import java.util.*;

abstract class Book {
    String title;
    String author;
    
    Book(String title, String author) {
        this.title = title;
        this.author = author;
    }
    
    abstract void display();
}

class MyBook extends Book
{
    int price;
    MyBook(String title, String author, int price) 
    {
        super(title,author);
        
        this.price=price;
    } 
    
    void display()
    {
        System.out.println("Title:"+ " "+ title);
        System.out.println("Author:"+ " "+ author);
        System.out.println("Price:"+ " "+ price);
    }
}

public class Solution {
   
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String title = scanner.nextLine();
        String author = scanner.nextLine();
        int price = scanner.nextInt();
        scanner.close();

        Book book = new MyBook(title, author, price);
        book.display();
    }
}
        System.out.println("Price:"+ " "+ price);
    }
}

public class Solution {
   
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String title = scanner.nextLine();
        String author = scanner.nextLine();
        int price = scanner.nextInt();
        scanner.close();

        Book book = new MyBook(title, author, price);
        book.display();
    }
}

