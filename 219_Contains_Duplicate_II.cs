/*
* 219. Contains Duplicate II (Easy)
* https://leetcode.com/problems/contains-duplicate-ii/description/
*
*/

public class Solution {
        public bool ContainsNearbyDuplicate(int[] nums, int k)
        {
            if (nums == null || nums.Length == 0 || k <= 0)
                return false;

            var len = nums.Length;

            var hh = new HashSet<int>();

            for (int i = 0; i < len; i++)
            {
                if (hh.Contains(nums[i]))
                {
                    return true;
                }
                hh.Add(nums[i]);
                if (i >= k)
                {
                    hh.Remove(nums[i - k]);
                }
            }
            return false;

        }
}

