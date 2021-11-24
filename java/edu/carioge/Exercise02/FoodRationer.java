package edu.carioge.Exercise02;

import java.util.Scanner;

public class FoodRationer {
    public static void main(String [] args) {
        //declare finals
        final double DECENT_RATIONS = 2.0;

        //Make a Scanner to read the user's input
        Scanner input = new Scanner(System.in);

        //Get the total amount of food from the user
        System.out.println("How much food are you going to buy?");
        double totalFood = input.nextDouble();

        //Get (number of people)
        System.out.println("How many folks?");
        int numPeople = input.nextInt();

        //get (food eaten per day)
        double foodPerDay = numPeople * DECENT_RATIONS;

        //calc (how many days are left)
        double daysLeft = totalFood / foodPerDay;
        System.out.println("Days of Food Left: " + daysLeft);
    }
}
