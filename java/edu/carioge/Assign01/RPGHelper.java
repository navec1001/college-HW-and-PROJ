package edu.carioge.Assign01;

import java.util.Scanner;

public class RPGHelper {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter strength and wisdom:");
        int strength = input.nextInt();
        int wisdom = input.nextInt();
        if (strength == 0 || wisdom == 0)
            System.err.println("ERROR: Negative Entry!");

        if (strength >= 50 && wisdom >= 50)
            System.out.println("PALADIN!");
        else if (strength >= 50 && wisdom < 50)
            System.out.println("BARBARIAN!");
        else if (strength < 50 && wisdom >= 50)
            System.out.println("WIZARD!");
        else
            System.out.println("HOBO!");
    }
}
