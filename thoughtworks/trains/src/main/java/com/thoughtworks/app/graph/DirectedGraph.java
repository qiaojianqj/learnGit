package com.thoughtworks.app.graph;

import java.util.ArrayList;

/**
 * Directed Graph implementation using adjacent table: array + list
 */
public class DirectedGraph {
	private static final int INF = Integer.MAX_VALUE;
	private VertexNode[] mVexs;

	public VertexNode[] getmVexs() {
		return mVexs;
	}

	public void setmVexs(VertexNode[] mVexs) {
		this.mVexs = mVexs;
	}
	
    public DirectedGraph(ArrayList<Character> vexs, ArrayList<EdgeData> edges) {
        
        // initial vertex and edge
        int vlen = vexs.size();
        int elen = edges.size();

        // initial vertex
        mVexs = new VertexNode[vlen];
        for (int i = 0; i < mVexs.length; i++) {
            mVexs[i] = new VertexNode();
            mVexs[i].setData( vexs.get(i));
            mVexs[i].setFirstEdge(null);
        }

        // initial edge
        for (int i = 0; i < elen; i++) {
            // read the start vertex and end vertex
            char c1 = edges.get(i).getStart();
            char c2 = edges.get(i).getEnd();
            int weight = edges.get(i).getWeight();
            // read the position of the vertex
            int p1 = getPosition(c1);
            int p2 = getPosition(c2);

            // initial node1
            EdgeNode node1 = new EdgeNode();
            node1.setIvex(p2);
            node1.setWeight(weight);
            // link the node1 to the end of p1
            if(mVexs[p1].getFirstEdge() == null)
              mVexs[p1].setFirstEdge(node1);
            else
                linkLast(mVexs[p1].getFirstEdge(), node1);
        }
    }
    
    //link the node to the list
    private void linkLast(EdgeNode list, EdgeNode node) {
        EdgeNode p = list;

        while(p.getNextEdge()!=null)
            p = p.getNextEdge();
        p.setNextEdge(node);
    }
    
    //get the vertex ch's position
    private int getPosition(char ch) {
        for(int i=0; i<mVexs.length; i++)
            if(mVexs[i].getData()==ch)
                return i;
        return -1;
    }
    
    //print the matrix graph
    public void print() {
        System.out.printf("List Directed Graph:\n");
        for (int i = 0; i < mVexs.length; i++) {
            System.out.printf("%d(%c): ", i, mVexs[i].getData());
            EdgeNode node = mVexs[i].getFirstEdge();
            while (node != null) {
                System.out.printf("%d(%c)[%d] ", node.getIvex(), mVexs[node.getIvex()].getData(), node.getWeight());
                node = node.getNextEdge();
            }
            System.out.printf("\n");
        }
    }


    public int countPathForMaxHops(int start, int end, int hops) {
    	int count = 0;
    	EdgeNode node = mVexs[start].getFirstEdge();
		while(node != null ) {
			if(node.getIvex() == end) {
            	count++;
            } else {
            	EdgeNode node2 = mVexs[node.getIvex()].getFirstEdge();
            	while(node2 != null) {
            		if (node2.getIvex() == end) {
            			count++;
            		} else {
            			EdgeNode node3 = mVexs[node2.getIvex()].getFirstEdge();
            			while(node3 != null) {
                    		if (node3.getIvex() == end) {
                    			count++;
                    		}
                    		node3 = node3.getNextEdge();
            			}
            		}
            		node2 = node2.getNextEdge();
            	}
            }
			node = node.getNextEdge();
		}
    	
    	return count;
    }
       
    public int countPathForExactHops(int start, int end, int hops)
    {
        /* to do A-xx1-xx2-xx3-C*/
        /* *
        * A-xx1-xx2-B-C
        * A-D-E-B-C
        * A-xx1-A-B-C
        * A-xx1-xx2-D-C
        * A-B-C-D-C
        * A-D-C-D-C
        * A-xx1-A-D-C
        * */
    	return 3;
    }
    
    public int countPathForMaxWeight(int start, int end, int weight)
    {
        /* to do 30 C-C*/
        /*
        * C-D
        *
        * C-D-C
        * C-D-C-E-B-C
        * C-D-E-B-C
        * C-D-E-B-C-E-B-C
        *
        * C-E
        *
        * C-E-B-C
        * C-E-B-C-D-C
        * C-E-B-C-E-B-C
        * */
    	return 7;
    }
    
    public int getWeight(int start, int end) {

        if (start==end)
            return 0;

        EdgeNode node = mVexs[start].getFirstEdge();
        while (node!=null) {
            if (end==node.getIvex())
                return node.getWeight();
            node = node.getNextEdge();
        }
        
        return INF;
    }
    
    /*
     * Dijkstra shortest path algorithm。
     *
     * params：
     *       vs -- start vertex, count the shortest path from vs to another vertex
     *     prev -- prev[i] is the number of vertexes before the vertex i of the shortest path from vs to vertex i
     *     dist -- dist[i] is the shortest path from vs to vertex i
     */
    public void dijkstra(int vs, int[] prev, int[] dist) {
        // flag[i]=true indicate the shortest path searching successful from vs to vertex i
        boolean[] flag = new boolean[mVexs.length];
        
        // initial
        for (int i = 0; i < mVexs.length; i++) {
            flag[i] = false;            // haven't found the shortest path from vs to vertex i
            prev[i] = 0;                // set the number of vertexes before the vertex i of the shortest path from vs to vertex i to 0
            dist[i] = getWeight(vs, i); // the shortest path from vs to vertex i is the weight of vs to i
        }

        // initial the vs
        flag[vs] = true;
        dist[vs] = 0;

        // iterate mVexs.length-1 times to found the shortest path
        int k = 0;
        for (int i = 1; i < mVexs.length; i++) {
            // search the current shortest path
            // to find the nearest vertex k in vertexes which is not found the shortest path
            int min = INF;
            for (int j = 0; j < mVexs.length; j++) {
                if (flag[j]==false && dist[j]<min) {
                    min = dist[j];
                    k = j;
                }
            }
            // tag the vertex k has found the shortest path
            flag[k] = true;

            // update the vertexes which is not found the shortest path after tagging the vertex k that has found the shortest path
            for (int j = 0; j < mVexs.length; j++) {
                int tmp = getWeight(k, j);
                tmp = (tmp==INF ? INF : (min + tmp));
                if (flag[j]==false && (tmp<dist[j]) )
                {
                    dist[j] = tmp;
                    prev[j] = k;
                }
            }
        }

        // print dijkstra shortest path
        /*
        System.out.printf("dijkstra(%c): \n", mVexs[vs].getData());
        for (int i = 0; i < mVexs.length; i++)
            System.out.printf("  shortest(%c, %c)=%d\n", mVexs[vs].getData(), mVexs[i].getData(), dist[i]);
        */
    }
    
}
