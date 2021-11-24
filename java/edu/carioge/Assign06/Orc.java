package edu.carioge.Assign06;

import edu.carioge.Assign03.TextMap;
import edu.carioge.Assign05.Sprite;

public class Orc extends Monster {
    private Sprite sprite = new Sprite();

    public Orc(){
        try {
            sprite.load("orc.txt" );
        }
        catch (Exception e) {
            System.err.println("Could not load orc.txt");
        }
    }

    public Orc(int row, int col) {
        super(row, col);
        try {
            sprite.load("orc.txt" );
        }
        catch (Exception e) {
            System.err.println("Could not load orc.txt");
        }
    }

    public void draw(TextMap map) {
        sprite.draw(map, getRow(), getCol());
    }
}
