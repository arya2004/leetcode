
import java.util.*;

public class collections {
    

    public void list() {
        
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);

        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }

        //iterator
        for (Integer i : list) {
            System.out.println(i);
        }

        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }



        list.set(2, 80);

        System.out.println(list);

        list.add(0, 35);
        System.out.println(list);
            
        List<Integer> list2 = new ArrayList<>();
        list2.addAll(list);
        System.out.println(list2);

        list.remove(0);
        list.remove(Integer.valueOf(2));
        System.out.println(list);

        list.clear();
        System.out.println(list);
        //when printing , toString() is called implicitly

        //return bool
        list.contains(40);

    }

    public void stack() {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        System.out.println(stack);

        stack.pop();
        System.out.println(stack);

        
        System.out.println(stack.peek());

        
        System.out.println(stack.search(2));

       
        System.out.println( stack.empty());

    }


    public void queue() {
        //Same for lined list
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.add(4);

        System.out.println(queue);

        queue.remove();
        System.out.println(queue);

        System.out.println(queue.peek());

        System.out.println(queue.poll());
        System.out.println(queue);

        System.out.println(queue.element());
        System.out.println(queue);

        System.out.println(queue.offer(5));
        System.out.println(queue);

        System.out.println(queue.size());
        System.out.println(queue.isEmpty());

    }

    public void p_queue() {
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        PriorityQueue<Integer> pq_max_heap = new PriorityQueue<>(Comparator.reverseOrder());    
        pq.add(1);
        pq.add(2);
        pq.add(3);
        pq.add(4);

        System.out.println(pq);

        System.out.println(pq.poll());
        System.out.println(pq);

        System.out.println(pq.peek());
        System.out.println(pq);

        System.out.println(pq.remove());
        System.out.println(pq);

        System.out.println(pq.offer(5));
        System.out.println(pq);

        System.out.println(pq.size());
        System.out.println(pq.isEmpty());
    }

    public void de_queue() {
        
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.add(1);
        dq.add(2);
        dq.add(3);
        dq.add(4);

        System.out.println(dq);

        dq.addFirst(0);
        System.out.println(dq);

        dq.addLast(5);
        System.out.println(dq);

        System.out.println(dq.pollFirst());
        System.out.println(dq);

        System.out.println(dq.pollLast());
        System.out.println(dq);

        System.out.println(dq.peekFirst());
        System.out.println(dq);

        System.out.println(dq.peekLast());
        System.out.println(dq);

        System.out.println(dq.removeFirst());
        System.out.println(dq);

        System.out.println(dq.removeLast());
        System.out.println(dq);

        System.out.println(dq.offerFirst(0));
        System.out.println(dq);

        System.out.println(dq.offerLast(5));
        System.out.println(dq);

        System.out.println(dq.size());
        System.out.println(dq.isEmpty());
    }

    public void hash_set() {
        
        Set<String> set = new HashSet<>();
        set.add("arya");
        set.add("arya");
        set.add("qwer");
        set.add("zxcv");
        set.add("sdgg");
        System.out.println(set);

        System.out.println(set.contains("arya"));
        set.remove("qwer");

        System.out.println(set);

        System.out.println(set.size());

        System.out.println(set.isEmpty());

        //LinkedHashSet - maintains insertion order
        //TreeSet - sorts the elements

    }

    public void mapper() {

        //TreeMap - sorts the elements based on keys
        
        Map<String, Integer> map = new HashMap<>();
        map.put("arya", 1);
        map.put("qwer", 2);
        map.put("zxcv", 3);
        map.put("sdgg", 4);

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }

        System.out.println(map);

        System.out.println(map.get("arya"));

        System.out.println(map.containsKey("qwer"));

        System.out.println(map.containsValue(2));

        System.out.println(map.size());

        System.out.println(map.isEmpty());

        System.out.println(map.keySet());

        System.out.println(map.values());

        System.out.println(map.entrySet());

        map.remove("arya");

        System.out.println(map);

        //LinkedHashMap - maintains insertion order
        //TreeMap - sorts the elements

    }

    public void arrays() {
        
        int a[] = new int[5];
        int idex = Arrays.binarySearch(a, 2);
        //need array to be ssroted

        Arrays.sort(a);
    

    }

    public void collect() {
        
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);

        List<Integer> list2 = new ArrayList<>();
        list2.add(5);
        list2.add(6);
        list2.add(7);
        list2.add(8);

        Collections.sort(list);
        Collections.reverse(list);
        Collections.shuffle(list);
        Collections.swap(list, 0, 1);
        Collections.copy(list, list2);
        Collections.fill(list, 0);
        Collections.replaceAll(list, 0, 1);
        System.out.println(Collections.frequency(list, 1));
        System.out.println(Collections.min(list));
        System.out.println(Collections.max(list));
        System.out.println(Collections.disjoint(list, list2));
        System.out.println(Collections.disjoint(list, list));
    }

    public static void main(String[] args) {
          

        String[] arr = new String[20];
        arr[0] = "arya2004";
        //static size

        ArrayList<String> student = new ArrayList<>();;
        student.add("arya2004");
        student.add("arya2005");
        //dynamic size

        collections c = new collections();
        c.collect();


    }


}
