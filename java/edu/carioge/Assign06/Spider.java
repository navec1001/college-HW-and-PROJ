package edu.carioge.Assign06;

import edu.carioge.Assign03.TextMap;
import edu.carioge.Assign05.Sprite;

public class Spider extends Monster {
    private Sprite sprite = new Sprite();

    public Spider() {
        try {
            sprite.load("spider.txt" );
        }
        catch (Exception e) {
            System.err.println("Could not load spider.txt");
        }
    }

    public Spider(int row, int col) {
        super(row, col);
        try {
            sprite.load("spider.txt" );
        }
        catch (Exception e) {
            System.err.println("Could not load spider.txt");
        }
    }

    public void draw(TextMap map) {
        sprite.draw(map, getRow(), getCol());
    }
}
