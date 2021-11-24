package edu.carioge.Assign03;

public class MapCoord {
    private int rows;
    private int columns;

    public MapCoord(int r, int c) {
        rows = r;
        columns = c;
    }

    public int getRow() {
        return rows;
    }

    public int getColumn() {
        return columns;
    }

    public String toString() {
        return "("+rows+","+columns+")";
    }
}
