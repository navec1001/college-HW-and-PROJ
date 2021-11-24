package edu.carioge.Assign06;

import java.util.Scanner;

public abstract class Monster implements Loadable, Drawable {
    private int row = 0;
    private int col = 0;

    protected Monster() {}

    protected Monster(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public int getRow() {return this.row;}
    public int getCol() {return this.col;}
    public void setRow(int row) {this.row = row;}
    public void setCol(int col) {this.col = col;}

    @Override
    public void load(Scanner input) throws GameFileException {
        try {
            row = input.nextInt();
            col = input.nextInt();
        }
        catch(Exception e) {
            this.row = 0;
            this.col = 0;
            throw new GameFileException("Error loading Monster", e);
        }
    }
}