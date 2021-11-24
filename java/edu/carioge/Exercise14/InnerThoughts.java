package edu.carioge.Exercise14;

public class InnerThoughts {

    private class InnerTwoStep implements TwoStep {
        public void leftStep(int count) {
            System.out.println("LEFT " + count);
        }
        public void rightStep(int count) {
            System.out.println("RIGHT " + count);
        }
    }

    public void dance(TwoStep s) {
        s.leftStep(3);
        s.rightStep(4);
    }

    public void walk(March m) {
        m.march(500);
    }

    public static void main(String [] args) {
        InnerThoughts thoughts = new InnerThoughts();

        //More than 1 function defined -> anonymous inner class
        thoughts.dance(new TwoStep() {
            public void leftStep(int count) {
                System.out.println("MYSTERY LEFT " + count);
            }
            public void rightStep(int count) {
                System.out.println("MYSTERY RIGHT " + count);
            }
        });

        //1 Function defined -> lambda expression
        thoughts.walk(m -> {
            System.out.println("AND I WOULD WALK 500 MORE!");
        });
    }
}

interface March {
    void march(int miles);
}

interface TwoStep {
    void leftStep(int count);
    void rightStep(int count);
}
