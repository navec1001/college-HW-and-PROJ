package edu.carioge.Assign05;

import java.util.Scanner;
import java.io.File;
import edu.carioge.Assign03.*;

public class Sprite {
    private int rows;
    private int cols;
    private char [][] data;
    private String name;

    public Sprite() {
        reset();
    }

    public void reset() {
        rows = 0;
        cols = 0;
        data = null;
        name = "";
    }

    public void load(String filename) throws SpriteFileException {
        try{
            Scanner input = new Scanner(new File(filename));
            name = input.nextLine();
            rows = Integer.parseInt(input.nextLine());
            cols = Integer.parseInt(input.nextLine());
            data = new char[rows][cols];

            for(int i = 0; i < rows; i++){
                String line = input.nextLine();
                for(int j = 0; j < cols; j++){
                    data[i][j] = line.charAt(j);
                }
            }

            input.close();
        }
        catch(Exception e){
            reset();
            throw new SpriteFileException("Invalid sprite file", e);
        }
    }

    public void draw(TextMap map, int posRow, int posCol){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                map.setPos(new MapCoord((posRow+i),(posCol+j)),data[i][j]);
            }
        }
    }
}
