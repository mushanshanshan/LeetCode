class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 1, res = 0;
        
        for (int i=0; i<flowerbed.size(); i++) {
            if (flowerbed[i]==0) {
                count++;
            } else {
                count=0;
            }
            
            if (count==3){
                res++;
                count=1;
            }
        }
        
        if (count==2) res++;
        
        return (res >= n);
    }
};