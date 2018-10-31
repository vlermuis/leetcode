/*
* 560. Subarray Sum Equals K (Medium) 
* https://leetcode.com/problems/subarray-sum-equals-k/description/
*
*/
int subarraySum(int* nums, int numsSize, int k) {
    int result = 0;
    int i,start, end;
    int* psum = (int*)malloc(sizeof(int)*(numsSize + 1));
    psum[0] = 0;
    for (i = 1; i <= numsSize; i++)
    {
        psum[i] = psum[i - 1] + nums[i - 1];
    }
    for (start = 0; start < numsSize; start++)
    {
        for (end = start + 1; end <= numsSize; end++)
        {
            if (psum[end] - psum[start] == k)
                result++;
        }
    }
    return result;
}
