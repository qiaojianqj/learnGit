package com.thoughtworks.app.command;

import java.util.ArrayList;

import com.thoughtworks.app.App;

/**
 * Command implementation to a shortest distance input
 */
public class CommandShortest  extends AbstractCommand {
	private ArrayList<Character> vexs;
	
	public CommandShortest(String commandLine) {
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
        System.out.println(routeDistance());
	}

	private int routeDistance()
	{
        int elen = vexs.size();
        if( elen <= 1)
        {
        	return 0;
        }
        
        int[] prev = new int[App.dG.getmVexs().length];
        int[] dist = new int[App.dG.getmVexs().length];
        
        //0 'A'
        //1 'B'
        //2 'C'
        //3 'D'
        //4 'E'
        // dijkstra algorithm counts the shortest path from the forth vertex to another             
        int distance = 0;
        for(int i = 0; i < elen -1; i++)
        {
        	int start = vexs.get(i).charValue() - 'A';
        	App.dG.dijkstra(start, prev, dist);
        	int to = vexs.get(i+1).charValue() - 'A';
        	distance += dist[to];
        }

		return distance;
		
	}

}
