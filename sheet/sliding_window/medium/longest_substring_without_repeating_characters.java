package sheet.sliding_window.medium;

public class longest_substring_without_repeating_characters {
    
    // 2 pointer and sliding window problem
    
    public int lengthOfLongestSubstring(String s) {
       
        int n = s.length();
        int[] freq = new int[256];
        for (int i = 0; i < 256; i++) {
            freq[i] = -1;
        }

        int l = 0;
        int r = 0;
        int max_len = - 0;

        while (r < n) {
            
            if(freq[s.charAt(r)] != -1){

                if(freq[s.charAt(r)] >= l){
                    l = freq[s.charAt(r)] + 1;
                }

            }
            max_len = Math.max(max_len, r - l + 1);

            freq[s.charAt(r)] = r;
            r++;

        }

        return max_len;
    }
}


/*
 * 

Explanation:

The code defines a class called longest_substring_without_repeating_characters.

Inside the class, there is a method called lengthOfLongestSubstring which takes a string s as input and returns an integer.

The variable n is initialized with the length of the input string s.

An integer array freq of size 256 is created. This array will be used to store the frequency of characters encountered in the string.

The freq array is initialized with -1 for all elements using a for loop.

Two pointers l and r are initialized to 0. These pointers will be used to define a sliding window.

The variable max_len is initialized to -0. This variable will store the length of the longest substring without repeating characters.

The while loop runs until the right pointer r reaches the end of the string.

Inside the while loop, the code checks if the frequency of the character at index r in the freq array is not -1. If it is not -1, it means the character has already been encountered.

If the frequency of the character is greater than or equal to the left pointer l, it means the character is within the current substring. In this case, the left pointer l is updated to the next index after the last occurrence of the character.

The code then calculates the length of the current substring by subtracting the left pointer l from the right pointer r and adding 1. The Math.max function is used to update the max_len variable with the maximum length encountered so far.

The frequency of the character at index r in the freq array is updated to the current index r.

The right pointer r is incremented to move to the next character.

Once the while loop ends, the function returns the value of max_len, which represents the length of the longest substring without repeating characters.
 

*/