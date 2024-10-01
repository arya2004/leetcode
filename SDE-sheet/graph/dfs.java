import java.lang.reflect.Array;
import java.util.*;

import sheet.sorting.insertion;

public class dfs {
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        boolean[] visitedArray = new boolean[V];
        visitedArray[0] = true;

        ArrayList<Integer> soln = new ArrayList<>();

        rec(0, adj, visitedArray, soln);
        return soln;

    }

    void rec(int N, ArrayList<ArrayList<Integer>> adj, boolean[] visitedArray, ArrayList<Integer> soln){

        visitedArray[N] = true;

        soln.add(N);

        for (Integer i : adj.get(N)) {
            if(!visitedArray[i]){
                rec(i, adj, visitedArray, soln);
            }
        }

    }
}
