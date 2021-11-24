package edu.carioge.Assign05;

import edu.carioge.Assign03.*;

import java.io.IOException;
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.File;

public class SpritePainter {

    public static void main(String [] args) {

        Scanner input = new Scanner(System.in);

        System.out.println("Enter map size in rows and columns:");
        int rows = input.nextInt();
        int cols = input.nextInt();

        TextMap map = new TextMap(rows, cols, '.');

        try{
            char cont;
            do{
                System.out.println("Enter sprite filename:");
                String filename = input.next();

                Sprite sprite = new Sprite();
                sprite.load(filename);

                System.out.println("Enter starting row and column:");
                int startRow = input.nextInt();
                int startCol = input.nextInt();
                sprite.draw(map, startRow, startCol);

                System.out.println("Draw again? [y]");
                cont = input.next().charAt(0);
            }
            while(cont == 'y');
        }
        catch(SpriteFileException s){
            System.err.println("SPRITE NOT LOADED");
        }

        try{
            PrintWriter write = new PrintWriter("output.txt");
            write.print(map.toString());
            write.close();
        }
        catch(IOException i){
            System.err.println("CANNOT SAVE FILE");
        }

    }
}
