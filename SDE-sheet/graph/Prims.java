import java.util.*;


//User function Template for Java

class Pair{
    int wt;
    int node;
    int parent;
    Pair(int w,int n,int p){
        wt=w;
        node=n;
        parent=p;
    }
}

class Pair2{
    int src;
    int dest;
    Pair2(int s,int d){
        src=s;
        dest=d;
    }
}

class Solution {
   
    
    public static int prims(int V, int E, List<List<int[]>> adj ){
        int sum=0;
        PriorityQueue<Pair> p=new PriorityQueue<Pair>(Comparator.comparingInt(pair->pair.wt));
        boolean [] visited=new boolean[V];
        ArrayList<Pair2> p2=new ArrayList<>();
        Pair p3=new Pair(0,0,-1);
        p.add(p3);
        visited[0]=true;
        while(!p.isEmpty()){
            Pair n=p.poll();
            int src=n.node;
            visited[src]=true;
            sum+=n.wt;
            p2.add(new Pair2(n.parent,src));
            for(int[] l:adj.get(src)){
                
                int nextnode=l[0];
                int w=l[1];
                if(visited[nextnode]==false){
                    p.add(new Pair(src,nextnode,w));
                }
                
                
            }
        }
        return sum;
        
    }
    
    
}