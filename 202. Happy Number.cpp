class Solution {
public:
    int cal_sum(int n){
        int sum = 0;
        while (n != 0){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    
    
    bool isHappy(int n) {
        unordered_set<int> count;
        
        while (true){
            int sum = cal_sum(n);
            
            if (count.find(sum) != count.end()){
                return false;
            }
            
            count.insert(sum);
            
            if (sum == 1){
                return true;
            }
            
            n = sum;
        }
    }
};