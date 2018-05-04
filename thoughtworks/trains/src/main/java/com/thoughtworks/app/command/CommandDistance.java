package com.thoughtworks.app.command;

import java.util.ArrayList;

import com.thoughtworks.app.App;

/**
 * Command implementation to process the distance input. 
 * A valid line example for this command would be: A-B-C 
 */
public class CommandDistance extends AbstractCommand {
	private ArrayList<Character> vexs;
	
	public CommandDistance(String commandLine) {
		super(commandLine);
		this.vexs = new ArrayList<Character>();
	}

	public void execute() {
        final String nodesLine = getCommandLine();
        final String[] nodes = nodesLine.split("-");
        for(int i = 0; i < nodes.length; i ++)
        {
        	final String vertexStr = nodes[i].trim();
        	final char vertexChr = vertexStr.charAt(0);
        	Character cVexs = new Character(vertexChr);
        	vexs.add(cVexs);
        }  
        int distance = routeDistance();
        if(distance == Integer.MAX_VALUE) {
        	System.out.println("NO SUCH ROUTE");
        } else {
        	System.out.println(distance);
        }
	}

	private int routeDistance()
	{
        int elen = vexs.size();
        if( elen <= 1)
        {
        	return 0;
        }
        
		int distance = 0;     
        for(int i = 0; i < elen -1; i++)
        {
        	int start = vexs.get(i).charValue() - 'A';   	
        	int to = vexs.get(i+1).charValue() - 'A';
        	int weight = App.dG.getWeight(start, to);
        	if (weight == Integer.MAX_VALUE ) {
        		return  Integer.MAX_VALUE;
        	}
        	distance += weight;
        }

		return distance;
	}
}
