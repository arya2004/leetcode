package sheet.sorting;

import java.util.*;

/*
 * Step1 = Select Minimmums and swap with the first element
 * Step2 = Select the second minimum and swap with the second element
 * StepN = Select the Nth minimum and swap with the Nth element
 * 
 * Time Complexity = O(n^2)
 * Space Complexity = O(1)
 * 
 */
public class selection {

    static ArrayList<Integer> selectionSort(ArrayList<Integer> arr){
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int mini = i;
            for (int j = i + 1; j < n; j++) {
                if(arr.get(j) < arr.get(mini)){
                    mini = j;
                }
            }
            
            //swap 
            int temp = arr.get(mini);
            arr.set(mini, arr.get(i));
            arr.set(i, temp);

        }

        return arr;

    }


    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
   
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }
        arr = selectionSort(arr);
        for (int i = 0; i < n; i++) {
            System.out.print(arr.get(i) + " ");
        }
        sc.close();
        
    }
}
