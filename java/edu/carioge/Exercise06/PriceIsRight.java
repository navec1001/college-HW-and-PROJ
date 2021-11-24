package edu.carioge.Exercise06;

import java.util.Scanner;

public class PriceIsRight {
    public static String getRandomItem() {
        // TODO
        return "a washing machine";
    }

    public static int getRandomPrice() {
        int price = 1 + ((int)(Math.random()*1000));
        return price;
    }

    public static void main(String [] args) {
        Scanner myInput = new Scanner(System.in);

        String player1 = "Player 1";
        String player2 = "Player 2";

        while (true) {
            String item = getRandomItem();
            int price = getRandomPrice();

            System.out.println("Item is " + item + "!!!");

            int guess1 = askForGuess(player1, myInput);
            int guess2 = askForGuess(player2, myInput);

            String winner = determineWinner(price,
                    player1, guess1,
                    player2, guess2);

            System.out.println("The true price is " + price + ", meaning...");
            System.out.println("The winner is: " + winner + "!!!!");
        }
    }

    //as long as you're in the same class you can declare methods wherever you want
        public static int askForGuess(String name, Scanner input) {
            System.out.println("**************************");
            System.out.println(name + ", what is your guess?");

            int guess = input.nextInt();
            return guess;
        }

        public static String determineWinner(int truePrice,
                                             String name1, int guess1,
                                             String name2, int guess2) {
            int diff1 = Math.abs(truePrice - guess1);
            int diff2 = Math.abs(truePrice - guess2);
            if (diff1 <= diff2)
                return name1;
            else
                return name2;
        }
}
