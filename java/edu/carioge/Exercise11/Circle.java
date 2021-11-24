package edu.carioge.Exercise11;

import javafx.geometry.Point2D;
import java.lang.Math.*;

public class Circle extends Shape {
    private double radius = 1.0;

    public Circle() {
        // super();
        super(false, new Point2D(0,0));
    }

    public Circle(double radius) {
        // super();
        super(false, new Point2D(0,0));
        this.radius = radius;
    }

    public Circle(double radius, boolean filled, Point2D center) {
        super(filled, center);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public String toString() {
        String s = "Radius: " + radius + "\n";
        String oldversion = super.toString();
        s = oldversion + s;
        return s;
    }

    public static String getNameOfShape() {
        return "Circle";
    }

    @Override
    public boolean equals(Object other){
        if(other instanceof Circle){
            Circle otherC = (Circle)other;
            return (radius == otherC.radius);
        }
        else{
            return false;
        }
    }
}
