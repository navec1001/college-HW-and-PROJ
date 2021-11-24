package edu.carioge.Exercise14;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.*;
import javafx.stage.Stage;

import java.util.ArrayList;

public class MyJavaFX extends javafx.application.Application {
        @Override
        //must always @Override start();
        public void start(Stage primaryStage){

                //Example 1
                //Button btOK = new Button("OK");
                //Scene scene = new Scene(btOK, 200, 250);

                Button b1 = new Button("1");
                Button b2 = new Button("2");
                Button b3 = new Button("3");
                Button b4 = new Button("4");
                Button b5 = new Button("5");

                /*
                StackPane pane = new StackPane();
                pane.getChildren().add(b1);
                pane.getChildren().add(b2);
                pane.getChildren().add(b3);
                pane.getChildren().add(b4);
                pane.getChildren().add(b5);

                StackPane.setAlignment(b1, Pos.TOP_LEFT);
                StackPane.setMargin(b1, new Insets(8,8,8,8));
                */

                /*
                FlowPane pane = new FlowPane();
                pane.getChildren().add(b1);
                pane.getChildren().add(b2);
                pane.getChildren().add(b3);
                pane.getChildren().add(b4);
                pane.getChildren().add(b5);
                */

                /*
                GridPane pane = new GridPane();
                pane.add(b1, 0, 0);
                pane.add(b2, 2, 0);
                pane.add(b3, 0, 2);
                pane.add(b4, 2, 2);
                pane.add(b5, 1, 1);
                */

                BorderPane pane = new BorderPane();
                pane.setTop(b1);
                pane.setCenter(b2);
                pane.setBottom(b3);
                pane.setLeft(b4);
                pane.setRight(b5);
                BorderPane.setAlignment(b1, Pos.CENTER);
                BorderPane.setAlignment(b2, Pos.CENTER);
                BorderPane.setAlignment(b3, Pos.CENTER);
                BorderPane.setAlignment(b4, Pos.CENTER);
                BorderPane.setAlignment(b5, Pos.CENTER);

                int num = 1;
                ArrayList<Button> numberButtons = new ArrayList<>();
                GridPane numberPane = new GridPane();
                for(int row = 0; row < 3; row++){
                        for(int col = 0; col < 3; col++) {
                                Button tmpButton = new Button("" + num);
                                numberButtons.add(tmpButton);
                                numberPane.add(tmpButton, col, row);
                                num++;
                        }
                }
                pane.setCenter(numberPane);
                BorderPane.setAlignment(numberPane, Pos.CENTER);

                Scene scene = new Scene(pane, 200, 250);

                //always get primaryStage! It's inherent!
                primaryStage.setTitle("Be Gay, Do Crimes!");
                primaryStage.setScene(scene);
                primaryStage.show();
        }

        public static void main(String [] args) {
            launch(args);
        }
}
