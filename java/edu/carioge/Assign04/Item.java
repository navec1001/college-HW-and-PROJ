package edu.carioge.Assign04;

public class Item {
    protected String name;
    protected double weight;

    public Item(String n, double w){
        name = n;
        weight = w;
    }

    public String getName(){return name;}

    public double getWeight(){return weight;}

    public void setName(String n){name = n;}

    public void setWeight(double w){weight = w;}

    @Override
    public String toString(){return "Name: "+name+"\n"+"Weight: "+weight+"\n";}

    public boolean use(Object target){
        System.out.println("Not usable");
        return false;
    }
}
