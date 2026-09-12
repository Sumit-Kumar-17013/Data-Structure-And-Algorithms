class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n - 1;

        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            i++;
            j--;
        }

        int MaxCount = 1;

        for (int k = 1; k < n; k++) {
            if (nums[k] != nums[k - 1]) {
                MaxCount++;
            }

            if (MaxCount == 3) {
                return nums[k];
            }
        }

        return nums[0];
    }
};