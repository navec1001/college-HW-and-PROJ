package edu.carioge.Exercise12;

public class InvalidRadiusException extends Exception {
    private double badRadius;

    public InvalidRadiusException (double badRadius) {
        super("Invalid radius " + badRadius);
        this.badRadius = badRadius;
    }

    public double getBadRadius() {
        return badRadius;
    }
}
