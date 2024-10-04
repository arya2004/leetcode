package LeetCode.daily.october;

import java.util.*;


public class divide_players_into_teams_of_equal_skill {
    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);
        int n = skill.length;
        long sum = 0;
        for(int i = 0; i < n; i++){
            sum += skill[i];
        }

        long target = sum / (n / 2 );

        long total = 0;
        int front = 0;
        int back = n - 1;
        while(front < back){
            if(skill[front] + skill[back] != target){
                return -1;
            }else{
                total += (skill[front] * skill[back]);
            }
            front++;
            back--;
        }

        return  total;

    }
}