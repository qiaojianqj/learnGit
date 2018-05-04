import java.util.*;

public class GraphByMatrix {  
    public static final boolean UNDIRECTED_GRAPH = false;//无向图标志  
    public static final boolean DIRECTED_GRAPH = true;//有向图标志  
  
    public static final boolean ADJACENCY_MATRIX = true;//邻接矩阵实现  
    public static final boolean ADJACENCY_LIST = false;//邻接表实现  
  
    public static final int MAX_VALUE = Integer.MAX_VALUE;  
    private boolean graphType;  
    private boolean method;  
    private int vertexSize;  
    private int matrixMaxVertex;  
  
    //存储所有顶点信息的一维数组  
    private Object[] vertexesArray;  
    //存储图中顶点之间关联关系的二维数组,及边的关系  
    private int[][] edgesMatrix;  
  
    // 记录第i个节点是否被访问过  
    private boolean[] visited;  
  
    /** 
     * @param graphType 图的类型：有向图/无向图 
     * @param method    图的实现方式：邻接矩阵/邻接表 
     */  
    public GraphByMatrix(boolean graphType, boolean method, int size) {  
        this.graphType = graphType;  
        this.method = method;  
        this.vertexSize = 0;  
        this.matrixMaxVertex = size;  
  
        if (this.method) {  
            visited = new boolean[matrixMaxVertex];  
            vertexesArray = new Object[matrixMaxVertex];  
            edgesMatrix = new int[matrixMaxVertex][matrixMaxVertex];  
  
            //对数组进行初始化，顶点间没有边关联的值为Integer类型的最大值  
            for (int row = 0; row < edgesMatrix.length; row++) {  
                for (int column = 0; column < edgesMatrix.length; column++) {  
                    edgesMatrix[row][column] = MAX_VALUE;  
                }  
            }  
  
        }  
    }  
  
    /********************最短路径****************************/  
    //计算一个顶点到其它一个顶点的最短距离  
    public void Dijkstra(Object obj) throws Exception {  
        Dijkstra(getVertexIndex(obj));  
    }  
    public void Dijkstra(int v0) {  
        int[] dist = new int[matrixMaxVertex];  
        int[] prev = new int[matrixMaxVertex];  
  
        //初始化visited、dist和path  
        for (int i = 0; i < vertexSize; i++) {  
            //一开始假定取直达路径最短  
            dist[i] = edgesMatrix[v0][i];  
            visited[i] = false;  
  
            //直达情况下的最后经由点就是出发点  
            if (i != v0 && dist[i] < MAX_VALUE)  
                prev[i] = v0;  
            else  
                prev[i] = -1; //无直达路径  
        }  
  
        //初始时源点v0∈visited集，表示v0 到v0的最短路径已经找到  
        visited[v0] = true;  
  
        // 下来假设经由一个点中转到达其余各点,会近些,验证之  
        // 再假设经由两个点中转,会更近些,验证之,.....  
        // 直到穷举完所有可能的中转点  
        int minDist;  
        int v = 0;  
        for (int i = 1; i < vertexSize; i++) {  
            //挑一个距离最近经由点,下标装入 v  
            minDist = MAX_VALUE;  
  
            for (int j = 0; j < vertexSize; j++) {  
                if ((!visited[j]) && dist[j] < minDist) {  
                    v = j;                             // 经由顶点j中转则距离更短  
                    minDist = dist[j];  
                }  
            }  
            visited[v] = true;  
  
            /*顶点v并入S，由v0到达v顶点的最短路径为min. 
              假定由v0到v，再由v直达其余各点，更新当前最后一个经由点及距离*/  
            for (int j = 0; j < vertexSize; j++) {  
                if ((!visited[j]) && edgesMatrix[v][j] < MAX_VALUE) {  
  
                    if (minDist + edgesMatrix[v][j] <= dist[j]) {  
                        //如果多经由一个v点到达j点的 最短路径反而要短,就更新  
                        dist[j] = minDist + edgesMatrix[v][j];  
  
                        prev[j] = v;                    //经由点的序号  
                    }  
  
                }  
            }  
  
        }  
  
        for (int i = 1; i < matrixMaxVertex; i++) {  
            System.out.println("**" + vertexesArray[v0] + "-->" +vertexesArray[i] + " 的最短路径是：" + dist[i]);  
        }  
    }  
  
    //获取顶点值在数组里对应的索引  
    private int getVertexIndex(Object obj) throws Exception {  
        int index = -1;  
        for (int i = 0; i < vertexSize; i++) {  
            if (vertexesArray[i].equals(obj)) {  
                index = i;  
                break;  
            }  
        }  
        if (index == -1) {  
            throw new Exception("没有这个值！");  
        }  
  
        return index;  
    }  
  
    /** 
     * 单源最短路径算法，用于计算一个节点到其他!!所有节点!!的最短路径 
     */  
    public void Dijkstra2(int v0) {  
        // LinkedList实现了Queue接口 FIFO  
        Queue<Integer> queue = new LinkedList<Integer>();  
        for (int i = 0; i < vertexSize; i++) {  
            visited[i] = false;  
        }  
  
        //这个循环是为了确保每个顶点都被遍历到  
        for (int i = 0; i < vertexSize; i++) {  
            if (!visited[i]) {  
                queue.add(i);  
                visited[i] = true;  
  
                while (!queue.isEmpty()) {  
                    int row = queue.remove();  
                    System.out.print(vertexesArray[row] + "-->");  
  
                    for (int k = getMin(row); k >= 0; k = getMin(row)) {  
                        if (!visited[k]) {  
                            queue.add(k);  
                            visited[k] = true;  
                        }  
                    }  
  
                }  
            }  
        }  
    }  
  
    private int getMin( int row) {  
        int minDist = MAX_VALUE;  
        int index = 0;  
        for (int j = 0; j < vertexSize; j++) {  
            if ((!visited[j]) && edgesMatrix[row][j] < minDist) {  
                minDist = edgesMatrix[row][j];  
                index = j;  
            }  
        }  
        if (index == 0) {  
            return -1;  
        }  
        return index;  
    }  
  
    public boolean addVertex(Object val) {  
        assert (val != null);  
        vertexesArray[vertexSize] = val;  
        vertexSize++;  
        return true;  
    }  
  
    public boolean addEdge(int vnum1, int vnum2, int weight) {  
        assert (vnum1 >= 0 && vnum2 >= 0 && vnum1 != vnum2 && weight >= 0);  
  
        //有向图  
        if (graphType) {  
            edgesMatrix[vnum1][vnum2] = weight;  
  
        } else {  
            edgesMatrix[vnum1][vnum2] = weight;  
            edgesMatrix[vnum2][vnum1] = weight;  
        }  
  
        return true;  
    }  

    public static void  main(String args[]) throws Exception { 
    System.out.println(System.getProperty("file.encoding"));    
    GraphByMatrix graph = new GraphByMatrix(DIRECTED_GRAPH, ADJACENCY_MATRIX, 6);  
  
    graph.addVertex("1");  
    graph.addVertex("2");  
    graph.addVertex("3");  
    graph.addVertex("4");  
    graph.addVertex("5");   
  
    graph.addEdge(0, 1,7);  
    graph.addEdge(0, 2,9);  
    graph.addEdge(0, 5,14);  
  
    graph.addEdge(1, 3,15);  
    graph.addEdge(1, 2,10);  
  
    graph.addEdge(2, 3,11);  
    graph.addEdge(2, 5,2);  
  
    graph.addEdge(3, 4,6);  
    graph.addEdge(4, 5,9);  
  
    graph.Dijkstra(0);  
    System.out.println();  
    graph.Dijkstra("1");  
    System.out.println();  
    graph.Dijkstra2(0);  
    System.out.println();  
}

}  