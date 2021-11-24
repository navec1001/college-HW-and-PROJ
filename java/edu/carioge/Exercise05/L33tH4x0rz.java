package edu.carioge.Exercise05;

import java.util.Scanner;

public class L33tH4x0rz {
    public static void main(String [] args) {
        Scanner reader = new Scanner(System.in);

        String line = "";
        do {
            System.out.println("Enter message: ");
            line = reader.nextLine();
            line = line.trim();
            String l33tLine = "";
            for(int i = 0; i < line.length(); i++) {
                char c = line.charAt(i);
                switch(c) {
                    case 'a':
                    case 'A':
                        l33tLine += "4";
                        break;
                    case 'e':
                    case 'E':
                        l33tLine += "3";
                        break;
                    case 'i':
                    case 'I':
                        l33tLine += "1";
                        break;
                    case 'o':
                    case 'O':
                        l33tLine += "0";
                        break;
                    default:
                        l33tLine += c;
                        break;
                }
            }
            System.out.println(l33tLine);

        //} while (!line.equals(""));
        } while(line.length()>0);
    }
}
