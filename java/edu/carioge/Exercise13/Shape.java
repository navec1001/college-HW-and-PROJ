package edu.carioge.Exercise13;

public abstract class Shape {
    private int cx = 0;
    private int cy = 0;

    protected Shape(){}

    protected Shape(int x, int y) {
        cx = x;
        cy = y;
    }

    protected int getCenterX() {
        return cx;
    }

    protected abstract double getArea();
    protected abstract double getPerimeter();

    /*
    public double getArea() throws Exception {
        throw new Exception("Not implemented");
    }
     */

    public static void main(String [] args) {
        Shape c = new Circle();
    }
}

interface Drawable {
    /*implicitly public abstract*/void draw();
}

class NPC implements Drawable {
    public void draw() {
        System.out.println("Draw partner!");
    }
}

class Circle extends Shape implements Drawable {
    private double radius = 1.0;

    public Circle(){
        super();
    }

    public Circle(int x, int y) {
        super(x,y);
    }

    @Override
    public void draw() {
        System.out.println("<Just pretend I drew a Circle>");
    }

    @Override
    public double getArea() {return Math.PI * radius * radius;}

    @Override
    public double getPerimeter() {return Math.PI * radius * 2;}
}
