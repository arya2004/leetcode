import  java.util .*;



class online_stock_span {
    
    Stack<int[]> st;
    
    public online_stock_span() {
        st = new Stack<>();
    }
    
    public int next(int price) {
        
        int span = 1;
        
        while(st.size() > 0 && price >= st.peek()[0]){
            span += st.pop()[1];
        }
        
        st.push(new int[]{price, span});
        
        return span;
    }
}