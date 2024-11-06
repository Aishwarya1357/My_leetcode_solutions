class Solution {
public:
    int bitwiseComplement(int N) {

        if(N==0){
            return 1;
        }
        int m=N;
        int mask=0;
        while(m!=0){
            mask=(mask<<1)|1;
            m=m>>1;
        }

     int ans= (~N)&mask;
     return ans;
    }
 
};