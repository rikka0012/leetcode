/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;

// 思路：同向快慢指针,右指针指向当前处理的元素，左指针指向要存储的位置
// 时间复杂度O(n),空间复杂度O(1)
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0;
        int fast = 0;
        int len = nums.size();
        int n = 0;
        while (fast < len)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
                fast++;
                n++;
            }
            else
            {
                fast++;
            }
        }
        return n;
    }
};
// @lc code=end
