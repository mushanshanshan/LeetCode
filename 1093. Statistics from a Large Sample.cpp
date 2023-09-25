class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minimum = -1, maximum = -1, mode = 0, mode_count = 0, left_count = 0, right_count = 0;
        long left = 0, right = 255, p_left = -1, p_right = -1;
        long sum = 0;
        float median = 0;

        while (left < right) {
            if (minimum == -1 && count[left] != 0) minimum = left;
            if (maximum == -1 && count[right] != 0) maximum = right;

            if (p_left != left && count[left] > mode_count) {
                mode = left;
                mode_count = count[left];
            }

            if (p_right != right && count[right] > mode_count) {
                mode = right;
                mode_count = count[right];
            }

            if (count[left] != 0 && p_left != left) {
                left_count += count[left];
                sum += left * count[left];

            }

            if (count[right] != 0 && p_right != right) {
                right_count += count[right];
                sum += right * count[right];

            }

            p_left = left;
            p_right = right;

            if (left_count > right_count) {
                right--;
            } else if (left_count < right_count) {
                left++;
            } else {
                right--;
                left++;
                if (left == right && p_left != left && p_right != right) left--;
            }
        }

        if (left_count > right_count) {
            median = (float)left;
        } else if (left_count < right_count) {
            median = (float)right;
        } else {
            median = (float)(left + right) / 2;
        }

        return {(float)minimum, (float)maximum, (float)sum / (left_count + right_count), median, (float)mode};

    }
};