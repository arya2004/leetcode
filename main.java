import java.util.Scanner;

/**
 * Little Rosie has a phone with a desktop (or launcher, as it is also called). The desktop can consist of several screens. Each screen is represented as a grid of size 5×3
, i.e., five rows and three columns.

There are x
 applications with an icon size of 1×1
 cells; such an icon occupies only one cell of the screen. There are also y
 applications with an icon size of 2×2
 cells; such an icon occupies a square of 4
 cells on the screen. Each cell of each screen can be occupied by no more than one icon.

Rosie wants to place the application icons on the minimum number of screens. Help her find the minimum number of screens needed.

Input
The first line of the input contains t
 (1≤t≤104
) — the number of test cases.

The first and only line of each test case contains two integers x
 and y
 (0≤x,y≤99
) — the number of applications with a 1×1
 icon and the number of applications with a 2×2
 icon, respectively.

Output
For each test case, output the minimal number of required screens on a separate line.
 */
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); 

        for (int i = 0; i < t; i++) {
            int x = scanner.nextInt(); 
            int y = scanner.nextInt(); 

            if(x == 0 && y == 0){
                System.out.println(0);
                continue;
            }
            if(x == 0){
                System.out.println((y / 2) + (y % 2));
                continue;
            }
            if(y == 0){
                System.out.println(x / 15 + (x % 15 == 0 ? 0 : 1));
                continue;
            }

           int screensFor2x2 = (y / 2);
           if(y % 2 == 1){
               screensFor2x2++;
           }
           int total  = screensFor2x2;

           int remaining = x - (screensFor2x2 * 7);
           if(y % 2 == 1){
                remaining -= 4;
           }
           if(remaining > 0){
               total += (remaining) / 15;
               total += (remaining % 15 == 0 ? 0 : 1);
               
           }

            System.out.println(total);
        }

        scanner.close();
    }
}