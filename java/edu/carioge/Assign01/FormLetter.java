package edu.carioge.Assign01;

import java.util.Scanner;

public class FormLetter {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        String firstName = "";
        int wholeNum = 0;

        System.out.println("Enter first name:");
        firstName = input.nextLine();
        System.out.println("Enter whole number:");
        wholeNum = input.nextInt();
        System.out.println("Congratulations " + firstName + "!");
        System.out.println("You may have won $" + wholeNum + "!");
    }
}
