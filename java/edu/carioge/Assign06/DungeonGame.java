package edu.carioge.Assign06;
//NOTE: CHANGE realemj to YOUR SITNETID!!!
import edu.carioge.Assign03.*;
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class DungeonGame {
	/**
	 * This class is already provided for you.
	 *
	 * See provided output files for desired output.
	 */
    public static void main(String [] args) {
    	// Create map
    	TextMap baseMap = new TextMap(30, 60, '.');

		try {
			// Ask user for level number
		    Scanner inputUser = new Scanner(System.in);
		    System.out.println("Enter level number:");
		    int levelNum = inputUser.nextInt();

		    // Open level file
			Scanner levelFile = new Scanner(new File("Level_" + levelNum + ".txt"));

			// Read in the number of Monsters
		    int numMonsters = levelFile.nextInt();
		    ArrayList<Monster> allMonsters = new ArrayList<Monster>();

		    // For each Monster...
		    for(int i = 0; i < numMonsters; i++) {
				String typeMonster = levelFile.next();
				
				Monster m = null;
				
				switch(typeMonster) {
				    case "Orc":
				    	m = new Orc();
				    	break;
				    case "Spider":
				    	m = new Spider();
				    	break;
				    default:
				    	break;
				}
				
				if(m != null) {
				    m.load(levelFile);
				    allMonsters.add(m);
				}	
		    }

		    // Draw all Monsters on the map
		    for(int i = 0; i < allMonsters.size(); i++) {
		    	allMonsters.get(i).draw(baseMap);
		    }
		}
		catch(Exception e) {
		    System.err.println("Game error");
		    //e.printStackTrace();
		}

		// Print map
		System.out.println(baseMap);
	}
}
