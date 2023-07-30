class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1.0;
        long power = n;
        if (power < 0)
        {
            power = -1 * power;
        }
        while (power > 0)
        {
            if (power % 2 == 1)
            {
                ans = ans * x;
                power = power - 1;
            }
            else
            {
                x *= x;
                power /= 2;
            }
        }
        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;

    }
};