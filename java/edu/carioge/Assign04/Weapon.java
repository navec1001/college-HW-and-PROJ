package edu.carioge.Assign04;

public class Weapon extends Item {
    private int damage;

    public Weapon(String n, double w, int d){
        super(n,w);
        damage = d;
    }

    public int getDamage(){return damage;}

    public void setDamage(int d){damage = d;}

    @Override
    public String toString(){return "Name: "+name+"\n"+"Weight: "+weight+"\n"+"Damage: "+damage+"\n";}

    @Override
    public boolean use(Object target){
        if(target instanceof Person){
            Person p = (Person)target;
            System.out.println("Attack " + p.getName() + " with " + getName() + " for " + damage + " damage!");
            if(p.defends(damage)){
                System.out.println(p.getName() + " lives!");
            }
            else{
                System.out.println(p.getName() + " is dead!");
            }
            return true;
        }
        else{return false;}
    }
}
