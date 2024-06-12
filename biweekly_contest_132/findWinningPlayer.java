package biweekly_contest_132;

import java.util.*;



public class findWinningPlayer {
    public int findWinningPlayer(int[] skills, int k) {
        int n = skills.length;


        if(k > n){
            int skillMax = 0;
            int maxi = 0;
            for (int i = 0; i < n; i++) {
                if(skills[i] > skillMax){
                    maxi = i;
                    skillMax = skills[i];
                }
            }
            return maxi;
        }


        Queue<Integer> q = new LinkedList<>();

        for(int i = 0;i < skills.length; i++){
            q.add(i);
            
        }

        int consecutiveWinns = 0;
        int currentIndex = q.remove();

        while (consecutiveWinns < k) {
            int nextIndex = q.remove();
            if(skills[currentIndex] > skills[nextIndex]){
                consecutiveWinns++;
                q.add(nextIndex);
            }else{
                consecutiveWinns = 1;
                q.add(currentIndex);
                currentIndex = nextIndex;
            }

        }

        return currentIndex;

    }
}
