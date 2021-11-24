package edu.carioge.Exercise14;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class DeepThought extends javafx.application.Application {
    private Label meaningLabel;

    private class AnswerHandler implements EventHandler<ActionEvent> {
        public void handle(ActionEvent event){
            System.out.println("42!");
            ((Button)event.getSource()).setText("42!");
        }

    }

    public void start(Stage primaryStage){

        meaningLabel = new Label("????");

        Button meaningButton = new Button("Meaning?");
        meaningButton.setOnAction(new AnswerHandler());

        StackPane pane = new StackPane();
        pane.getChildren().add(meaningButton);

        Scene scene = new Scene(pane, 250, 250);

        primaryStage.setScene(scene);
        primaryStage.setTitle("Deep Thought");
        primaryStage.show();

    }

    public static void main(String [] args){

    }
}

/*
class AnswerHandler implements EventHandler<ActionEvent> {
    public void handle(ActionEvent event){
        System.out.println("42!");
    }

}
 */