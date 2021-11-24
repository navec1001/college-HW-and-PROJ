package edu.carioge.Assign02;

import java.util.Scanner;

public class TitleProgram {
    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter message:");
        String message = input.nextLine();

        System.out.println(FancyTitle.createFancyTitle(message, '*'));

        System.out.println(FancyTitle.createFancyTitle(message, '$'));

    }
}
