/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>

using namespace std;
//思路：快慢指针，快指针遍历将非0元素填充至慢指针指向的目标数组末端
//遍历结束后将剩下的位置用0填充
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int h = (int)nums.size();
        for(int i=0;i<h;i++)
        {
            if(nums[i]!=0)
            {
                nums[j++] = nums[i];
            }
        }
        //用fill填充更快
        fill(nums.begin()+j,nums.end(),0);
        //for(;j<h;j++)
        //{
        //    nums[j]=0;
        //}
    }
};
//思路及解法
//使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
//右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。
//注意到以下性质：
//左指针左边均为非零数；
//右指针左边直到左指针处均为零。
//因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。
class Solution_2 {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int h = nums.size();
        for (int i = 0; i < h; i++)
{
    if (nums[i] != 0)
    {
        swap(nums[i], nums[j++]);
    }
}
    }
};
// @lc code=end

