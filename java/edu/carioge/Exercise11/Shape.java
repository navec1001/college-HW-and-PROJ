package edu.carioge.Exercise11;

import javafx.geometry.Point2D;

public class Shape {
    private Point2D center;
    private boolean filled;

    public Shape(){
        center = new Point2D(0, 0);
        filled = false;
    }

    public Shape(boolean newFilled, Point2D newCenter){
        center = new Point2D(newCenter.getX(), newCenter.getY());
        filled = newFilled;
    }

    public boolean isFilled(){
        return filled;
    }

    public Point2D getCenter() {
        return new Point2D(center.getX(), center.getY());
    }

    public void setFilled(boolean newFilled){
        filled = newFilled;
    }

    public void setCenter(Point2D newCenter){
        center = new Point2D(newCenter.getX(), newCenter.getY());
    }

    @Override
    public String toString() {
        String s = "Center: " + center.getX() + "," + center.getY() + "\n";
        s += "Is filled: " + filled + "\n";
        return s;
    }

    public static String getNameOfShape() {
    return "Generic Shape";
    }

    public static double getArea() {
        return -1;
    }
}
