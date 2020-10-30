/**
 * Java: 邻接矩阵图
 *
 * @author skywang
 * @date 2014/04/19
 */

import java.io.IOException;
import java.util.Scanner;

public class ListDG {
    private static int INF = Integer.MAX_VALUE;
    
    // 邻接表中表对应的链表的顶点
    private class ENode {
        int ivex;       // 该边所指向的顶点的位置
        int weight;     // 该边的权值
        ENode nextEdge; // 指向下一条弧的指针
    }

    // 邻接表中表的顶点
    private class VNode {
        char data;          // 顶点信息
        ENode firstEdge;    // 指向第一条依附该顶点的弧
    };

    private VNode[] mVexs;  // 顶点数组


    /*
     * 创建图(用已提供的矩阵)
     *
     * 参数说明：
     *     vexs  -- 顶点数组
     *     edges -- 边数组
     */
    public ListDG(char[] vexs, EData[] edges) {
        
        // 初始化"顶点数"和"边数"
        int vlen = vexs.length;
        int elen = edges.length;

        // 初始化"顶点"
        mVexs = new VNode[vlen];
        for (int i = 0; i < mVexs.length; i++) {
            mVexs[i] = new VNode();
            mVexs[i].data = vexs[i];
            mVexs[i].firstEdge = null;
        }

        // 初始化"边"
        for (int i = 0; i < elen; i++) {
            // 读取边的起始顶点和结束顶点
            char c1 = edges[i].start;
            char c2 = edges[i].end;
            int weight = edges[i].weight;
            // 读取边的起始顶点和结束顶点
            int p1 = getPosition(c1);
            int p2 = getPosition(c2);

            // 初始化node1
            ENode node1 = new ENode();
            node1.ivex = p2;
            node1.weight = weight;
            // 将node1链接到"p1所在链表的末尾"
            if(mVexs[p1].firstEdge == null)
              mVexs[p1].firstEdge = node1;
            else
                linkLast(mVexs[p1].firstEdge, node1);
        }
    }

    /*
     * 将node节点链接到list的最后
     */
    private void linkLast(ENode list, ENode node) {
        ENode p = list;

        while(p.nextEdge!=null)
            p = p.nextEdge;
        p.nextEdge = node;
    }

    /*
     * 返回ch位置
     */
    private int getPosition(char ch) {
        for(int i=0; i<mVexs.length; i++)
            if(mVexs[i].data==ch)
                return i;
        return -1;
    }

    /*
     * 读取一个输入字符
     */
    private char readChar() {
        char ch='0';

        do {
            try {
                ch = (char)System.in.read();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } while(!((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')));

        return ch;
    }

    /*
     * 读取一个输入字符
     */
    private int readInt() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    /*
     * 获取边<start, end>的权值；若start和end不是连通的，则返回无穷大。
     */
    private int getWeight(int start, int end) {

        if (start==end)
            return 0;

        ENode node = mVexs[start].firstEdge;
        while (node!=null) {
            if (end==node.ivex)
                return node.weight;
            node = node.nextEdge;
        }
        
        return INF;
    }
    
    /*
     * Dijkstra最短路径。
     * 即，统计图中"顶点vs"到其它各个顶点的最短路径。
     *
     * 参数说明：
     *       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
     *     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
     *     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
     */
    public void dijkstra(int vs, int[] prev, int[] dist) {
        // flag[i]=true表示"顶点vs"到"顶点i"的最短路径已成功获取。
        boolean[] flag = new boolean[mVexs.length];
        
        // 初始化
        for (int i = 0; i < mVexs.length; i++) {
            flag[i] = false;            // 到顶点i的最短路径还没获取到。
            prev[i] = 0;                // 到顶点i的前驱顶点为0。
            dist[i] = getWeight(vs, i); // 到顶点i的最短路径为"顶点vs"到"顶点i"的权。
        }

        // 对"顶点vs"自身进行初始化
        flag[vs] = true;
        dist[vs] = 0;

        // 遍历mVexs.length-1次；每次找出一个顶点的最短路径。
        int k = 0;
        for (int i = 1; i < mVexs.length; i++) {
            // 寻找当前最小的路径；
            // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
            int min = INF;
            for (int j = 0; j < mVexs.length; j++) {
                if (flag[j]==false && dist[j]<min) {
                    min = dist[j];
                    k = j;
                }
            }
            // 标记"顶点k"为已经获取到最短路径
            flag[k] = true;

            // 修正当前最短路径和前驱顶点
            // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
            for (int j = 0; j < mVexs.length; j++) {
                int tmp = getWeight(k, j);
                tmp = (tmp==INF ? INF : (min + tmp)); // 防止溢出
                if (flag[j]==false && (tmp<dist[j]) )
                {
                    dist[j] = tmp;
                    prev[j] = k;
                }
            }
        }

        // 打印dijkstra最短路径的结果
        System.out.printf("dijkstra(%c): \n", mVexs[vs].data);
        for (int i = 0; i < mVexs.length; i++)
            System.out.printf("  shortest(%c, %c)=%d\n", mVexs[vs].data, mVexs[i].data, dist[i]);
    }
    
    /*
     * 打印矩阵队列图
     */
    public void print() {
        System.out.printf("List Graph:\n");
        for (int i = 0; i < mVexs.length; i++) {
            System.out.printf("%d(%c): ", i, mVexs[i].data);
            ENode node = mVexs[i].firstEdge;
            while (node != null) {
                System.out.printf("%d(%c)[%d] ", node.ivex, mVexs[node.ivex].data, node.weight);
                node = node.nextEdge;
            }
            System.out.printf("\n");
        }
    }

     // 边的结构体
    private static class EData {
        char start; // 边的起点
        char end;   // 边的终点
        int weight; // 边的权重

        public EData(char start, char end, int weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }
    };
    
    public static void main(String[] args) {
        char[] vexs = {'A', 'B', 'C', 'D', 'E'}; 
        EData[] edges = {
                   // 起点 终点 权
            new EData('A', 'B', 5),  
            new EData('B', 'C', 4),  
            new EData('C', 'D',  8), 
            new EData('D', 'C',  8), 
            new EData('D', 'E',  6), 
            new EData('A', 'D',  5), 
            new EData('C', 'E',  2), 
            new EData('E', 'B',  3),
            new EData('A', 'E',  7),
        };
        ListDG pG;

        // 自定义"图"(输入矩阵队列)
        //pG = new ListDG();
        // 采用已有的"图"
        pG = new ListDG(vexs, edges);

        pG.print();   // 打印图
        
        int[] prev = new int[pG.mVexs.length];
        int[] dist = new int[pG.mVexs.length];
        //0 'A'
        //1 'B'
        //2 'C'
        //3 'D'
        //4 'E'
        // dijkstra算法获取"第4个顶点"到其它各个顶点的最短距离
        pG.dijkstra(3, prev, dist);
        // dijkstra算法获取"第1个顶点"到其它各个顶点的最短距离
        pG.dijkstra(0, prev, dist);
    }
}