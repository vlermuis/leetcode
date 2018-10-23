/**
	https://leetcode.com/problems/two-sum/description/
 * Note: The returned array must be malloced, assume caller calls free().
 *  (Easy)
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* p_res = (int*)malloc(sizeof(int) * 2);
    int* pdummy = NULL;
    int p0 = 0;
    int p1 = 0;
    int i,j;
    for (i = 0; i < numsSize; i++)
    {
        pdummy = nums;
        pdummy += i;
        p0 = *pdummy;
        for (j = 0; j < numsSize; j++)
        {
            if (i != j)
            {
                pdummy = nums;
                pdummy += j;
                p1 = *pdummy;
                if ( (p0 + p1) == target)
                {
                    pdummy = p_res;
                    *pdummy = i;
                    pdummy++;
                    *pdummy = j;
                    return p_res;
                }
            }
        }
    }
    return NULL;
}