package edu.carioge.Exercise13;

public abstract class Grandparent {
    protected abstract void tellStory();

    protected void complain(){
        System.out.println("GET OFF MY LAWN.");
    }
}

abstract class Parent extends Grandparent {
    protected abstract void spendMoney();
}

class Child extends Parent {
    @Override
    public void tellStory(){
        System.out.println("Back in my day...");
    }
    @Override
    public void spendMoney() {
        System.out.println("Order from Amazon...");
    }

    @Override
    public void complain() {
        System.out.println("Not enough allowance");
    }
}