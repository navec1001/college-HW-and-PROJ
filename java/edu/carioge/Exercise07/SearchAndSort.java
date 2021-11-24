package edu.carioge.Exercise07;

import java.util.*;

public class SearchAndSort {
    public static void main(String [] args) {
        int [] list = new int[20];
        Arrays.fill(list, 5);
        for (int i = 0; i <list.length; i++) {
            list[i] = ((int)(Math.random()*100));
        }

        System.out.println(Arrays.toString(list));
        Scanner input = new Scanner(System.in);
        int key = input.nextInt();
        int index = Arrays.binarySearch(list, key);

        if(index < 0)
            System.out.println("Not found");
        else
            System.out.println("Found");
    }
}
