package edu.carioge.Exercise12;

public class Vertex {
    private double x = 0;
    private double y = 0;
    private double z = 0;

    public Vertex() {}

    public Vertex(double x, double y, double z){
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public double getX() {return this.x;};
    public double getY() {return this.y;};
    public double getZ() {return this.z;};

    public void setX(double x) {this.x = x;}
    public void setY(double y) {this.y = y;}
    public void setZ(double z) {this.z = z;}
}
