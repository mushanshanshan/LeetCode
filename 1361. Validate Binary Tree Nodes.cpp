class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int count = 0, root = 0;
        stack<int> st;
        vector<int> temp(n, 0);

        for (auto l: leftChild) if (l != -1) temp[l]++;
        for (auto r: rightChild) if (r != -1) temp[r]++;

        for (auto t: temp) {
            if (t == 0) {
                count++;
                root = t;
            }
        }

        if (count != 1) return false;

        st.push(root);

        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            int left = leftChild[cur];
            int right = rightChild[cur];
            if (left != -1) {
                if (temp[left] == -2) return false;
                temp[left] = -2;
                st.push(left);
            }

            if (right != -1) {
                if (temp[right] == -2) return false;
                temp[right] = -2;
                st.push(right);
            }
        }

        return true;

    }
};