package sheet.sorting;

import java.util.ArrayList;
import java.util.Scanner;

/*
 * Insertion Sort Algorithm:
 * 
 * ASsume the first element is sorted and the rest of the elements are unsorted
 * Place the first unsorted element in its correct position in the sorted part of the array
 * Place the Nth element in its correct position in the sorted part of the array
 * 
 * Time Complexity = O(n^2)
 * Space Complexity = O(1)
 * 
 * Best Case Time Complexity = O(n) when the array is already sorted
 */

public class insertion {
    static ArrayList<Integer> insertionSort(ArrayList<Integer> arr){
        
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int j = i;

            while (j > 0 && arr.get(j - 1) > arr.get(j)) {
                //swap
                int temp = arr.get(j - 1);
                arr.set(j -1 , arr.get(j));
                arr.set(j, temp);

                j--;
            }

            System.out.println(arr);

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
        arr = insertionSort(arr);
        System.out.println(arr);
        sc.close();
        
    }
}
