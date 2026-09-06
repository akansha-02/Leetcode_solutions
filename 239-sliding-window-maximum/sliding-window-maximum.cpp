class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int right = 0; right < nums.size(); right++) {

            // 1. Remove elements outside the window
            while(!dq.empty() && dq.front() <= right - k) {
                dq.pop_front();
            }

            // 2. Remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // 3. Add current index
            dq.push_back(right);

            // 4. Window size is k
            if(right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};