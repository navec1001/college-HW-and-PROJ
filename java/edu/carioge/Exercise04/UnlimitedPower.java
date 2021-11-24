package edu.carioge.Exercise04;

import java.util.Scanner;

public class UnlimitedPower {
    public static void main(String[] args){
        Scanner myInput = new Scanner(System.in);
        System.out.println("Enter base and exponent:");
        double base = myInput.nextDouble();
        double exp = myInput.nextDouble();

        double power = Math.pow(base, exp);
        System.out.println(base + "^" + exp + " =" + power);
        double squared = Math.sqrt(base);
        System.out.println("sqrt(" + base + ") = " + squared);
    }
}
