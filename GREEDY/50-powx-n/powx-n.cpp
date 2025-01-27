class Solution {
public:
    double myPow(double x, int n) {

        if(n==0){
            return 1.0;
        }

        long long exp=n;
        if(exp<0){
            x=1/x;
            exp=-exp;
        }

        double smallans =myPow(x, exp/2);

        if(exp%2==0){
            return smallans*smallans;
        }
        else{
            return x*smallans*smallans;
        }


    }
 
};