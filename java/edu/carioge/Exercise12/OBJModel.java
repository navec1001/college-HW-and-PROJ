package edu.carioge.Exercise12;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class OBJModel {
    private ArrayList<Vertex> vertices = new ArrayList<Vertex>();
    private ArrayList<Integer> indices = new ArrayList<Integer>();

    public OBJModel() {}

    void save(String filename) throws IOException {
        PrintWriter writer = new PrintWriter(filename);
        // v x y z
        for(Vertex v: vertices){
            writer.print("v" );
            writer.print(v.getX() + " ");
            writer.print(v.getY() + " ");
            writer.print(v.getZ() + "\n");
        }

        // f a b c
        for(int i = 0; i < indices.size(); i += 3){
            writer.print("f ");
            writer.print(indices.get(i) + " ");
            writer.print(indices.get(i+1) + " ");
            writer.print(indices.get(i+2) + " ");
        }

        writer.close();
    }

    void load(String filename) throws IOException {
        Scanner input = new Scanner (new File(filename));
        vertices.clear();
        indices.clear();
        while (input.hasNextLine()) {
            String line = input.nextLine();
            line = line.trim();
            if(line.length() > 0) {
                Scanner lineScan = new Scanner(line);
                String type = lineScan.next();

                if (type.equals("v")) {
                    double x = lineScan.nextDouble();
                    double y = lineScan.nextDouble();
                    double z = lineScan.nextDouble();
                    Vertex v = new Vertex(x, y, z);
                    vertices.add(v);
                } else if (type.equals("f")) {
                    int a = lineScan.nextInt();
                    int b = lineScan.nextInt();
                    int c = lineScan.nextInt();
                    indices.add(a);
                    indices.add(b);
                    indices.add(c);
                }

                System.out.println(line);
            }
        }
        input.close();
    }

    public void scaleY(double s) {
        for(Vertex v: vertices) {
            v.setY(s * v.getY());
        }
    }

    public static void main(String[] args) {
        try{
            OBJModel model = new OBJModel();
            model.load("bunny.obj");
            model.scaleY(2.0);
            model.save("bunnyStretched.obj");
            //TODO!!!!
        }
        catch(Exception help){
            System.err.println(help);
            //help.printStackTrace();
        }
    }
}
