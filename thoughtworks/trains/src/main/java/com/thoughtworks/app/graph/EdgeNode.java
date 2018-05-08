package com.thoughtworks.app.graph;

/**
 * EdgeNode implement a edge in directed graph
 */
public class EdgeNode {
	private int ivex;
	private int weight;
	private EdgeNode nextEdge;
	
	public int getIvex() {
		return ivex;
	}
	public void setIvex(int ivex) {
		this.ivex = ivex;
	}
	public int getWeight() {
		return weight;
	}
	public void setWeight(int weight) {
		this.weight = weight;
	}
	public EdgeNode getNextEdge() {
		return nextEdge;
	}
	public void setNextEdge(EdgeNode nextEdge) {
		this.nextEdge = nextEdge;
	}
	
}
