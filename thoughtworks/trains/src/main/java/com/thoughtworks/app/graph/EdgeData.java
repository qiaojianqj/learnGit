package com.thoughtworks.app.graph;

/**
 * EdgeData is used to create a directed graph
 */
public class EdgeData {
	private char start;
	private char end;
	private int weight;
	
	public EdgeData(char start, char end, int weight)
	{
		this.setStart(start);
		this.setEnd(end);
		this.setWeight(weight);
	}

	public char getStart() {
		return start;
	}

	public void setStart(char start) {
		this.start = start;
	}

	public char getEnd() {
		return end;
	}

	public void setEnd(char end) {
		this.end = end;
	}

	public int getWeight() {
		return weight;
	}

	public void setWeight(int weight) {
		this.weight = weight;
	}
	
}
