package edu.carioge.Exercise11;

public class Warrior {
    //FIX 1:
    //public Warrior() {}

    public Warrior(String name) {
        System.out.println(name + ", what is best in life?");
    }
}

class Barbarian extends Warrior{
         //public Barbarian(){
         //    super();
         //}

         //FIX 2:
         public Barbarian (String name) {
             super(name);
         }
}

