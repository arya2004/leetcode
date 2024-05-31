package sheet.binary_search;

public class k_th_element_of_two_sorted_array {
    public long kthElement( int arr1[], int arr2[], int n, int m, int k) {
        
        int p1 = 0;
        int p2 = 0;
        int counter  = 0;
        long ele = -1;
        while (counter < k && p1 < n && p2 < m) {
            if(arr1[p1] <= arr2[p2]){
                ele = arr1[p1];
                p1++;
                
            }
            else{
                 ele = arr2[p2];
                p2++;
               
            } 
            counter++;
        }
        while(counter < k && p1 < n){
            ele = arr1[p1];
            p1++;
            counter++;
            
        }
        while(counter < k && p2 < m){
             ele = arr2[p2];
            p2++;
            counter++;
           
        }

        return ele;


        
    }
}
