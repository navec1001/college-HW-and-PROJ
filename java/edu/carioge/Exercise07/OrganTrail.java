package edu.carioge.Exercise07;

public class OrganTrail {
    public static int randomIndex(String [] list) {
        return ((int)(Math.random()*list.length));
    }

    public static void main(String [] args) {
        String [] names = {
                "Rick",
                "Lori",
                "Coral",
                "Shane"
        };

        String [] disasters = {
                "a broken leg",
                "dysentery",
                "bitten by a walker",
                "had a bat taken to the face"
        };

        int nameIndex = randomIndex(names);
        int disasterIndex = randomIndex(disasters);

        System.out.println(names[nameIndex] + " has " + disasters[disasterIndex] + ".");
    }
}
