/* You are given two classes, Person and Student, where Person is the base class and Student is the derived class. Completed code for Person and a declaration for Student are provided for you in the editor. Observe that Student inherits all the properties of Person. */
import java.util.*;

class Person 
{
	protected String firstName;
	protected String lastName;
	protected int idNumber;
	
	// Constructor
	Person(String firstName, String lastName, int identification)
    {
		this.firstName = firstName;
		this.lastName = lastName;
		this.idNumber = identification;
	}
	
	// Print person data
	public void printPerson()
    {
		 System.out.println("Name: " + lastName + ", " + firstName+ "\nID: " + idNumber); 
	}
	 
}

class Student extends Person
{
	private int[] testScores;
    // Constructor
    public Student(String firstName, String lastName, int id, int[] scores) 
    {
        super(firstName, lastName, id); // Call the constructor of the parent class
        this.testScores = scores;
     }

    // Method to calculate grade
    public char calculate() 
    {
        int sum = 0;
                // Calculate the total score
        for (int score : testScores) 
        {
            sum += score;
        }
        // Calculate the average
        int average = sum / testScores.length;
        // Determine the grade
        if (average >= 90) 
        {
            return 'O'; // Outstanding
        } 
        else if (average >= 80) 
        {
            return 'E'; // Exceeds Expectations
        } 
        else if (average >= 70) 
        {
            return 'A'; // Acceptable
        } 
        else if (average >= 55) 
        {
            return 'P'; // Poor
        } 
        else if (average >= 40) 
        {
            return 'D'; // Dreadful
        } 
        else 
        {
            return 'T'; // Troll
        }
    }
}

class Solution 
{
	public static void main(String[] args) 
    {
		Scanner scan = new Scanner(System.in);
		String firstName = scan.next();
		String lastName = scan.next();
		int id = scan.nextInt();
		int numScores = scan.nextInt();
		int[] testScores = new int[numScores];
		for(int i = 0; i < numScores; i++)
        {
			testScores[i] = scan.nextInt();
		}
		scan.close();
		Student s = new Student(firstName, lastName, id, testScores);
		s.printPerson();
		System.out.println("Grade: " + s.calculate() );
	}
}