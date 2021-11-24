package edu.carioge.Assign04;

public class Food extends Item {
    private int health;

    public Food(String n, double w, int h){
        super(n, w);
        health = h;
    }

    public int getHealth(){return health;}

    public void setHealth(int h){health = h;}

    @Override
    public String toString(){return "Name: "+name+"\n"+"Weight: "+weight+"\n"+"Health: "+health+"\n";}

    @Override
    public boolean use(Object target){
        if (target instanceof Person) {
            Person p = (Person)target;
            if(p.heal(health)){
                System.out.println(p.getName() + " ate " + getName() + " for " + health + " health!");
                return true;
            }
            else{
                System.out.println(p.getName() + " cannot be healed!");
                return false;
            }
        }
        else{return false;}
    }
}
