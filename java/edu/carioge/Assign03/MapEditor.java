package edu.carioge.Assign03;

import java.util.Scanner;

public class MapEditor {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.println("Enter rows, columns, and default character:");
        int rows = input.nextInt();
        int cols = input.nextInt();
        char defaultChar = input.next().charAt(0);
        boolean valid = true;

        TextMap myMap = new TextMap(rows, cols, defaultChar);

        System.out.println(myMap);

        while(valid == true){
            System.out.println("Enter row, column, and character:");
            int inRows = input.nextInt();
            int inCols = input.nextInt();
            char inChar = input.next().charAt(0);
            myMap.setPos(new MapCoord(inRows, inCols), inChar);
            System.out.println(myMap);
            valid = myMap.isValidPosition(new MapCoord(inRows, inCols));
        }
    }
}
