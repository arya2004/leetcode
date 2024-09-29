package LeetCode.daily;

import java.util.*;

public class MyCircularDeque {

    private ArrayList<Integer> arr;
    private int currentCapacity;
    private int maxCapacity;

    public MyCircularDeque(int k) {
        this.arr = new ArrayList<>(k);
        this.currentCapacity = 0;
        this.maxCapacity = k;
    }
    
    public boolean insertFront(int value) {
        if(currentCapacity == maxCapacity){
            return false;
        }
        arr.add(0, value);
        currentCapacity ++;
        return true;
    }
    
    public boolean insertLast(int value) {
        if(currentCapacity == maxCapacity){
            return false;
        }
        arr.add(value);
        currentCapacity ++;
        return true;
    }
    
    public boolean deleteFront() {
        if(currentCapacity == 0){
            return false;
        }
        arr.remove(0);
        currentCapacity--;
        return true;
    }
    
    public boolean deleteLast() {
        if(currentCapacity == 0){
            return false;
        }
        arr.remove(arr.size() -1);
        currentCapacity--;
        return true;
    }
    
    public int getFront() {
        if(currentCapacity == 0){
            return -1;
        }
        return arr.get(0);
        
    }
    
    public int getRear() {
        if(currentCapacity == 0){
            return -1;
        }
        return arr.get(arr.size() - 1);
    }
    
    public boolean isEmpty() {
        return arr.isEmpty();
    }
    
    public boolean isFull() {
        return currentCapacity == maxCapacity;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */