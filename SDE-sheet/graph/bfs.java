class Solution {
  
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
       
        ArrayList<Integer> list=new ArrayList<>();
        
        
        Queue<Integer> q=new LinkedList<>();
        q.add(0);
        
        while(!q.isEmpty()){
            int pop=q.poll();
            if(!list.contains(pop))list.add(pop);
            for(Integer i:adj.get(pop)){
                
                if(!list.contains(i)){
                    q.add(i);
                }
            }
        }
        
        return list;
        
    }
}

