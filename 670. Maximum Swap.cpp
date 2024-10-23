class Solution {
public:
    int maximumSwap(int num) {
        vector<int> ns;
        vector<int> max_record;
        int max = 0, temp = 0;

        while (num > 0) {
            temp = num % 10;
            ns.push_back(temp);
            if (temp > max) {
                max = temp;
            }
            max_record.push_back(max);
            num /= 10;
        }

        for (int i=ns.size()-1; i>0; i--) {
            if (ns[i] < max_record[i]) {
                max = max_record[i];
                temp = ns[i];
                ns[i] = max;
                break;
            }
        }

        for (int i=0; i<ns.size(); i++) {
            if (ns[i] == max) {
                ns[i] = temp;
                break;
            }
        }

        for (int i=ns.size()-1; i>=0; i--) {
            num = num * 10 + ns[i];
        }

        return num;
    }
};