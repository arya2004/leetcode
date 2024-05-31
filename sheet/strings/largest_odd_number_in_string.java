package sheet.strings;

public class largest_odd_number_in_string {
    public String largestOddNumber(String num) {
        int index = -1;
        for (int i = num.length() - 1; i >=  0; i--) {
            if(num.charAt(i) - '0' % 2 == 1){
                index = i;
                break;
            }
           
        }
        if(index == -1) return "";
        return num.substring(0, index + 1);
    }

    public static void main(String[] args) {
        largest_odd_number_in_string l = new largest_odd_number_in_string();
        System.out.println(l.largestOddNumber("35427"));
    }
}
