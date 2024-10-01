package LeetCode.daily;

import java.util.*;


public class CustomStack {

    int[] _stack;  
    int _maxSize;
    int _topPointer;

    public CustomStack(int maxSize) {
        this._stack = new int[maxSize];
        this._maxSize = maxSize;
        this._topPointer = -1;
    }
    
    public void push(int x) {

        if(this._topPointer < this._maxSize -1 ){
            this._topPointer++;
            this._stack[_topPointer] = x;
        }

        
    }
    
    public int pop() {
         
        if(this._topPointer == -1){
            return -1;
        }
        this._topPointer--;
        return  this._stack[_topPointer + 1];
    }
    
    public void increment(int k, int val) {

        if(k < this._maxSize ){
            for(int i = 0; i < k ; i++){
            _stack[i] += val;
            }
        }else{
            for(int i = 0; i < this._maxSize ; i++){
            _stack[i] += val;
            }
        }
        

      
        
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */