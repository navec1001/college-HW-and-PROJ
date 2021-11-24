package edu.carioge.Assign03;

public class TextMap {
    private int rowCnt;
    private int colCnt;
    private char defaultChar;
    private char[][] textmap;

    public TextMap(int rowCnt, int colCnt, char defaultChar) {
        this.rowCnt = rowCnt;
        this.colCnt = colCnt;
        this.defaultChar = defaultChar;
        textmap = new char[rowCnt][colCnt];
        for(int i = 0; i < rowCnt; i++){
            for(int j = 0; j < colCnt; j++){
                textmap[i][j] = defaultChar;
            }
        }
    }

    public int getRowCnt(){
        return rowCnt;
    }

    public int getColumnCnt(){
        return colCnt;
    }

    public boolean isValidPosition(MapCoord coord){
        if (coord.getRow() < getRowCnt() && coord.getColumn() < getColumnCnt() && coord.getRow() >= 0 && coord.getColumn() >= 0){
            return true;
        }
        else{
            return false;
        }
    }

    public char getPos(MapCoord coord){
        if(isValidPosition(coord)){
            return textmap[coord.getRow()][coord.getColumn()];
        }
        else{
            return defaultChar;
        }
    }

    public boolean setPos(MapCoord coord, char c){
        if(isValidPosition(coord)){
            textmap[coord.getRow()][coord.getColumn()] = c;
            return true;
        }
        else{
            return false;
        }
    }

    public String toString(){
        String output = "";
        for(int i = 0; i < rowCnt; i++){
            for(int j = 0; j < colCnt; j++){
                output += textmap[i][j];
            }
            output += "\n";
        }
        return output;
    }
}
