package edu.carioge.Exercise11;

import java.util.Scanner;

public class TestDragons {
    public static void main(String [] args){
        Monster m = new FireDrake();

        m.attack();
        m.makeNoise();
        m.move();

        Scanner input = new Scanner(System.in);
        int c = input.nextInt();

        Monster n = createMonster(c);

        if(n instanceof Dragon){
            ((Dragon)n).fly();
        }

        if(n instanceof FireDrake) {
            FireDrake y = (FireDrake) n;
            y.breatheFire();
        }
    }

    public static Monster createMonster(int choice) {
        if(choice == 0){
            return new FireDrake();
        }
        else if(choice == 1){
            return new Dragon();
        }
        else {
            return new Monster();
        }
    }
}
