package edu.carioge.Exercise04;

import java.util.Scanner;

public class TrigFunctions {
    public static void main(String [] args){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter degrees:");
        double degrees = input.nextDouble();

        double rads = Math.toRadians(degrees);

        double s = Math.sin(rads);
        double c = Math.cos(rads);
        double t = Math.tan(rads);

        System.out.println("Sin: " + s );
        System.out.println("Cos: " + c);
        System.out.println("Tan: " + t);
    }
}
