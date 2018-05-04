package com.thoughtworks.app.command;

import com.thoughtworks.app.App;

/**
 * Command implementation to process the trips input. 
 * A valid line example for this command would be: "MAX_STOPS, 3, A-C"
 * or "EXACT_STOPS, 3, A-C" or "MAX_DISTANCE, 30, C-C" 
 */
public class CommandTrips extends AbstractCommand {

	public CommandTrips(String commandLine) {
		super(commandLine);
		// TODO Auto-generated constructor stub
	}

	public void execute() {
        final String[] commandParts = getCommandLine().split(",");
        
        final String filterCriteria = commandParts[0].trim();
        final int filterValue = Integer.valueOf(commandParts[1].trim());
        final String startNode = String.valueOf(commandParts[2].trim().charAt(0));
        final String endNode = String.valueOf(commandParts[2].trim().charAt(2));

        int numberOfTrips = 0;

        if (filterCriteria.equalsIgnoreCase("MAX_STOPS")) {
            numberOfTrips = numberOfPathsWithMaxStops(startNode, endNode, filterValue);
        } else if (filterCriteria.equalsIgnoreCase("EXACT_STOPS")) {
            numberOfTrips = numberOfPathsWithExactStops(startNode, endNode, filterValue);
        } else if (filterCriteria.equalsIgnoreCase("MAX_DISTANCE")) {
            numberOfTrips = numberOfPathsWithMaxWeight(startNode, endNode, filterValue);
        }
        System.out.println(numberOfTrips);
	}
	
	private int numberOfPathsWithMaxStops(String startNode, String endNode, int filterValue)
	{
		int start = startNode.charAt(0) - 'A';
		int end = endNode.charAt(0) - 'A';
	
		return App.dG.countPathForMaxHops(start, end, filterValue);		
	}
	
	private int numberOfPathsWithExactStops(String startNode, String endNode, int filterValue)
	{
		int start = startNode.charAt(0) - 'A';
		int end = endNode.charAt(0) - 'A';
		
		// start - (filterValue -1) vertex - end
		return App.dG.countPathForExactHops(start, end, filterValue);		
	}
	
	private int numberOfPathsWithMaxWeight(String startNode, String endNode, int filterValue)
	{
		int start = startNode.charAt(0) - 'A';
		int end = endNode.charAt(0) - 'A';
		// start - ... - end && path <= filterValue
		return App.dG.countPathForMaxWeight(start, end, filterValue);		
	}
}
