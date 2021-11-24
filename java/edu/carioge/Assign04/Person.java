package edu.carioge.Assign04;

public class Person {
    private String name;
    private int health;

    public Person(String n){
        health = 100;
        name = n;
    }

    public String getName(){return name;}

    public int getHealth(){return health;}

    @Override
    public String toString(){return "Name: "+name+"\n"+"Health: "+health+"\n";}

    public boolean isAlive(){
        if(health != 0){return true;}
        else{return false;}
    }

    public boolean heal(int boost){
        if(this.isAlive()){
            if((health+boost) > 100){
                health = 100;
            }
            else{
                health += boost;
            }
            return true;
        }
        else{
            return false;
        }
    }

    public boolean defends(int damage){
        if(health-damage <= 0){
            health = 0;
        }
        else{
            health -= damage;
        }
        return this.isAlive();
    }
}
