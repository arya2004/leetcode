
import  java.util .*;



public class subset_sums {
    ArrayList<Integer> subsetSums(ArrayList<Integer> arr, int n) {
        // code here
        ArrayList<Integer> sumSubset = new ArrayList<>();
        rec(0,0, arr,n, sumSubset);
        Collections.sort(sumSubset);
        return sumSubset;
    }


    void rec(int index, int sum, ArrayList<Integer> arr, int N, ArrayList<Integer> sumSubset){

        if(index == N){
            sumSubset.add(sum);
            return;
        }

        //pick
        rec(index + 1, sum + arr.get(index), arr, N, sumSubset);


        //not pick
        rec(index + 1, sum , arr, N, sumSubset);

    }
}