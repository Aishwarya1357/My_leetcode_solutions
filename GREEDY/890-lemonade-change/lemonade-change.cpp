class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives=0;
        int tens=0;

        for(const int bill:bills){
            if(bill==5){
                ++fives;
            }
            else if(bill==10){
                if(fives>0){
                ++tens;
                --fives;}
                else{
                    return false;}
                
            }
            else{
                if(fives>0&tens>0){
                    --tens;
                    --fives;
                }
                else if(tens==0&fives>=3){
                    fives=fives-3;

                }
                else{
                    return false;
                }
            }
        }

        if(fives<0){
            return false;
        }

        


        return true;

        
    }
};