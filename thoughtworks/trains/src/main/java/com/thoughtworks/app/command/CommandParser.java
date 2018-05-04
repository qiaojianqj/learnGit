package com.thoughtworks.app.command;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * Class responsible to add appropriate command instance through the lines of a given file or
 * through the input string 
 */
public class CommandParser {	
	private List<Command> commands;
	private static final String TYPEDISTANCE = "DISTANCE";
	private static final String TYPESHORTEST = "SHORTEST";
	private static final String TYPETRIPS = "TRIPS";
	
	public CommandParser() {
		this.commands = new ArrayList<Command>();
	}
	
	public void addCommand(final File inputFile) throws IOException {
        final BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        while (reader.ready()) {
            final Command toAdd = processLine(reader);
            if (toAdd != null) {
                commands.add(toAdd);
            }
        }
        reader.close();	
	}
	
	public void addCommand(final String type, final String route) {
        Command processedCommand = null;
        
        if (type == TYPESHORTEST) {
        	processedCommand = new CommandShortest(route);
        } else if (type == TYPEDISTANCE) {
        	processedCommand = new CommandDistance(route);
        } else if (type == TYPETRIPS) {
        	processedCommand = new CommandTrips(route);
        }
        
        commands.add(processedCommand);
	}	
    
    private Command processLine(final BufferedReader reader) throws IOException {
        Command processedCommand = null;
        final String currentLine = reader.readLine().toUpperCase();
     
        processedCommand = new CommandNewGraph(currentLine);
    
        return processedCommand;
    }

	public List<Command> getCommand() {
		return commands;
	}
}
