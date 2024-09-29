package LeetCode.daily;

import java.util.*;

class Event{
    int start;
    int end;
    
    Event(int _start, int _end){
        this.end = _end;
        this.start = _start;
    }
}

public class MyCalendarTwo {

    public ArrayList<Event> Overlapping;
    public ArrayList<Event> NonOverlapping;

    public MyCalendarTwo() {
        this.Overlapping = new ArrayList<>();
        this.NonOverlapping = new ArrayList<>();
    }
    
    public boolean book(int start, int end) {

        for (Event event : Overlapping) {
            if(!(end <= event.start || event.end <= start)){
                return false;
            }
        }
        
        for (Event event : NonOverlapping) {
            if(!(end <= event.start || event.end <= start)){
               Overlapping.add(new Event(Math.max(start, event.start), Math.min(end, event.end)));

            }

        }
        NonOverlapping.add(new Event(start, end));

        return true;
    }
}