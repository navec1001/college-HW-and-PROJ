package edu.carioge.Exercise05;

import java.util.Scanner;

public class FoodJourney {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);

        int totalFood = 0;
        int foodBought = input.nextInt();
        while (foodBought != 0) {
            totalFood += foodBought;
            System.out.println("Food so far: " + totalFood);
            System.out.println("More?");
            foodBought = input.nextInt();
        }

        int foodPerDay = 5;
        int dayOnTrail = 0;

        while (totalFood > 0) {
            totalFood -= foodPerDay;
            System.out.println("Food Left: " + totalFood);
            dayOnTrail++;
        }

        System.out.println("SURVIVED " + dayOnTrail + " DAYS");

    }
}
