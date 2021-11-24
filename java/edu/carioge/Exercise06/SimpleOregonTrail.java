package edu.carioge.Exercise06;

import java.util.Scanner;

public class SimpleOregonTrail {

    public static boolean isWonGame(int milesTraveled, int DEST_MILES) {
        return (milesTraveled >= DEST_MILES);
    }

    public static boolean isLostGame(int totalFood, int milesTraveled, int DEST_MILES) {
        return (milesTraveled < DEST_MILES && totalFood <= 0);
    }

    public static boolean isGameOver(int totalFood, int milesTraveled, int DEST_MILES) {

        return (isWonGame(milesTraveled, DEST_MILES) || isLostGame(totalFood, milesTraveled, DEST_MILES));
    }

    public static int askToForage(Scanner input, int partyCnt) {
        System.out.println("Do you wish to forage? [y]");
        String ans = input.next().toLowerCase();
        int forage = 0;
        if(ans.equals("y")) {
            int maxForage = 11 * partyCnt;
            forage = ((int)(Math.random()*maxForage));
            System.out.println("Food found: " + forage);
        }
        return forage;
    }

    public static int consumeFood(int totalFood, int partyCnt, int RATIONS) {
        int foodEaten = partyCnt*RATIONS;
        totalFood -= foodEaten;
        totalFood = Math.max(totalFood, 0);
        return totalFood;
    }

    public static void printStatus(int totalFood, int partyCnt, int milesTraveled, int daysTraveled) {
        System.out.println("***********************");
        System.out.println("DAY " + daysTraveled + ":");
        System.out.println("TOTAL FOOD: " + totalFood);
        System.out.println("PARTY COUNT: " + partyCnt);
        System.out.println("MILES TRAVELED: " + milesTraveled);
        System.out.println("***********************");
    }

    public static void printWonMessage(int totalFood) {
        if (totalFood > 0) {
            System.out.println("Y'ALL MADE IT!");
        }
        else {
            System.out.println("Y'ALL BARELY MADE IT OOF");
        }
    }

    public static void printLostMessage() {
        System.out.println("Y'ALL FUCKED LMAO");
    }

    public static void main(String [] args) {
        final int RATIONS = 2;
        final int DEST_MILES = 2000;
        final int SPEED = 200;

        Scanner input = new Scanner(System.in);
        System.out.println("How many people?");
        int partyCnt = input.nextInt();
        int totalFood = 100;
        int milesTraveled = 0;
        int daysTraveled = 0;

        while (!isGameOver(
                totalFood,
                milesTraveled,
                DEST_MILES)) {
            int forage = askToForage(input, partyCnt);
            totalFood += forage;
            totalFood = consumeFood(
                    totalFood,
                    partyCnt,
                    RATIONS);
            milesTraveled += SPEED;
            daysTraveled++;
            printStatus(totalFood, partyCnt, milesTraveled, daysTraveled);
        }

        if(isWonGame(milesTraveled, DEST_MILES)) {
            printWonMessage(totalFood);
        }
        else {
            printLostMessage();
        }
    }
}
