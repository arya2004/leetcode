package sheet.sorting;

import java.util.*;

/*
 * Step1 = Compare the first two elements and swap if the first element is greater than the second element
 * Step2 = Compare the second and third elements and swap if the second element is greater than the third element
 * StepN = Compare the Nth and N+1th elements and swap if the Nth element is greater than the N+1th element
 * 
 * Time Complexity = O(n^2)
 * Space Complexity = O(1)
 * 
 * Best Case Time Complexity = O(n) when the array is already sorted
 */

public class bubble {
    static ArrayList<Integer> bubbleSort(ArrayList<Integer> arr){
        
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if(arr.get(j) > arr.get(j + 1)){
                    //swap
                    int temp = arr.get(j);
                    arr.set(j, arr.get(j + 1));
                    arr.set(j + 1, temp);
                }
            }
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
        arr = bubbleSort(arr);
        for (int i = 0; i < n; i++) {
            System.out.print(arr.get(i) + " ");
        }
        sc.close();
        
    }
}
