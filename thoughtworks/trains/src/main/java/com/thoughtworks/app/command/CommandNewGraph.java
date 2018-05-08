package com.thoughtworks.app.command;

import java.util.ArrayList;

import com.thoughtworks.app.App;
import com.thoughtworks.app.graph.DirectedGraph;
import com.thoughtworks.app.graph.EdgeData;

/**
 * Command implementation to build an input graph. A valid line example for this
 * command would be: AB5, BC4, CD8, DC8, DE6, AD5, CE2, EB3, AE7
 */
public class CommandNewGraph extends AbstractCommand {
	private ArrayList<Character> vexs;
	private ArrayList<EdgeData> edges;
	
	public CommandNewGraph(String commandLine)
	{
		super(commandLine);
		this.vexs = new ArrayList<Character>();
		this.edges = new ArrayList<EdgeData>();
	}
	
	public void execute() {
        final String nodesLine = getCommandLine();
        final String[] nodes = nodesLine.split(",");
        for (final String vertexEdgePair : nodes) {
        	final String trimmedPair = vertexEdgePair.trim();
            final char from = trimmedPair.charAt(0);
            final char to = trimmedPair.charAt(1);
            final int weight = Integer.valueOf(trimmedPair.substring(2));
            addVertexNode(from);
            addVertexNode(to);
            addEdgeNode(from, to, weight);
        }
        
        App.dG = new DirectedGraph(vexs, edges);
        //App.dG.print();   //print directed graph to system.out
	}
	
    private boolean addVertexNode(char vertex) {
    	Character cVexs = new Character(vertex);
        if (!vexs.contains(cVexs)) {
        	vexs.add(cVexs);
            return true;
        }
        return false;
    }
    

    private boolean addEdgeNode(final char from, final char to, final int weight) {

        final EdgeData newEdge = new EdgeData(from, to, weight);
        if (!edges.contains(newEdge)) {
            edges.add(newEdge);
            return true;
        }
        return false;
    }

}
