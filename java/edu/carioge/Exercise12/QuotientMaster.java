package edu.carioge.Exercise12;

import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class QuotientMaster {
    public static int quotient(int a, int b){
        /*
        if(b!=0){
        int answer = a / b;
        return answer
        }
        else {
        return 0;
        }
         */
        System.out.println("Before division...");
        if(b == 0) {
            //USUALLY on one line!!! This is just to show what is happening with exceptions!
            ArithmeticException e = new ArithmeticException("Can't divide by zero, you fool!");//WE CONTROL THE EXCEPTIONS NOW, BITCH!
            throw e;
        }
        int answer = a/b;
        //STOP HERE IF EXCEPTION!!! EJECT BACK TO MAIN!
        System.out.println("After division...");
        return answer;
    }

    public static void doesIO() throws IOException {
        System.out.println("Mysterious IO operation...");
        throw new IOException("HELP!!!");
    }

    public static void main(String [] args) {
        Scanner input = new Scanner(System.in);
        try {
            int x = input.nextInt();
            int y = input.nextInt();
            int ans = quotient(x, y);
            //STOP HERE IF EXCEPTION!!! IF NO WAY TO HANDLE THEN EXIT!!
            //BUT if you have a catch block, go to that.
            System.out.println(ans);
            doesIO();
        }
        catch(ArithmeticException bob) {
            System.out.println("YOU HAVE PLUNGED HUMANITY INTO FREEFALL.");
            System.out.println("MESSAGE: " + bob.getMessage());
        }
        //SKIP ALL OTHER CATCHES!!!
        catch(InputMismatchException rob) {
            System.out.println("WHAT KIND OF NUMBER IS THAT????");
        }
        catch(IOException e){
            System.out.println("IO PROBLEM!!!! HELP!");
        }
        catch(Exception dontcare){
            System.out.println("Something's up...");
        }
        //After catch block(s) is(are) handled, keep going!

        System.out.println("The end is nigh.");
    }
}
