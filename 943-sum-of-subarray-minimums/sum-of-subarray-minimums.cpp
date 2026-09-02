class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        const long long MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;

        // Previous strictly smaller
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next smaller or equal
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            long long contribution =
                (long long)arr[i] *
                leftCount *
                rightCount;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};