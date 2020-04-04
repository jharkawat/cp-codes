class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int count = 0;
        vector<int> pos;
        for(int i= 0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                pos.push_back(i);
                count++;
            }
        }
        for(int j = 0; j<count; j++)
        {
            nums.erase(nums.begin() + pos[j] - j);
        }
        for(int j = 0; j<count; j++)
        {
            nums.push_back(0);
        }
        
    }
};