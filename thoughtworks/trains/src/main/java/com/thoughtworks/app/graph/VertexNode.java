package com.thoughtworks.app.graph;

/**
 * VertexNode implement a vertex in directed graph
 */
public class VertexNode {
	private  char data;
	private EdgeNode firstEdge;
	
	public char getData() {
		return data;
	}
	public void setData(char data) {
		this.data = data;
	}
	public EdgeNode getFirstEdge() {
		return firstEdge;
	}
	public void setFirstEdge(EdgeNode firstEdge) {
		this.firstEdge = firstEdge;
	}
	

}
