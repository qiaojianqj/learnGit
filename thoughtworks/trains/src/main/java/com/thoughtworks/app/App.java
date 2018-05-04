package com.thoughtworks.app;

import java.io.File;
import com.thoughtworks.app.command.Command;
import com.thoughtworks.app.command.CommandParser;
import com.thoughtworks.app.graph.*;
/**
 * Directed graph search!
 *
 */
public class App 
{
	public static DirectedGraph dG;
	public static void main( String[] args ) throws Exception
    {
        File inputFile = null;
        if (args.length == 1) {
            inputFile = new File(args[0]);
        } else {
            inputFile = new File(App.class.getResource("/graph.txt").toURI());
        }
  
        CommandParser commandParser = new CommandParser();
        commandParser.addCommand(inputFile);
        commandParser.addCommand("DISTANCE", "A-B-C");
        commandParser.addCommand("DISTANCE", "A-D");
        commandParser.addCommand("DISTANCE", "A-D-C");
        commandParser.addCommand("DISTANCE", "A-E-B-C-D");
        commandParser.addCommand("DISTANCE", "A-E-D");
        
        commandParser.addCommand("TRIPS", "MAX_STOPS, 3, C-C");
        commandParser.addCommand("TRIPS", "EXACT_STOPS, 4, A-C");
        
        commandParser.addCommand("SHORTEST", "A-C");
        commandParser.addCommand("SHORTEST", "B-B");
        
        commandParser.addCommand("TRIPS", "MAX_DISTANCE, 30,C-C");
        
        for (final Command eachCommand : commandParser.getCommand()) {
            eachCommand.execute();
        }
    }
}
