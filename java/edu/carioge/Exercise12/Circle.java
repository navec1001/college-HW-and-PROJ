package edu.carioge.Exercise12;

public class Circle {
    private double radius = 1.0;

    public Circle () {}

    public Circle (double radius) throws InvalidRadiusException {
        setRadius(radius);
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius (double radius) throws InvalidRadiusException {
        if(radius < 0){
            throw new InvalidRadiusException(radius);
        }

        this.radius = radius;
    }

    @Override
    public String toString(){
        return "Circle with radius " + radius;
    }

    public static void main(String [] args) {
        try{
            Circle c1 = new Circle(5);
            System.out.println(c1);
            Circle c2 = new Circle(-7);
            System.out.println(c2);
            Circle c3 = new Circle(8);
            System.out.println(c3);
        }
        catch(InvalidRadiusException e){
            System.out.println("EXCEPTION!");
            System.out.println("Message: " + e.getMessage());
            System.out.println("Bad radius: " + e.getBadRadius());
            e.printStackTrace();
            System.err.println("END TRACE");
        }

        System.out.println("Life goes on...");
    }
}
