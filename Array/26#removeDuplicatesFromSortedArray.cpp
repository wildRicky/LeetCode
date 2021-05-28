//两种解法
//第一种：利用升序性，依次查找更大的值填充到相应位置
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.empty()){
            int count=1,size=nums.size();
            for(int i=1;i<size;++i)
            {
                if(nums[i]>nums[count-1])
                {       
                        nums[count++]=nums[i];
                }
            }
            return count;
        }
        else
            return 0;
    }
};

//第二种：利用迭代器，直接删除数组重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.empty())
        {
            auto beg=nums.begin(),eof=nums.end();
            int judge=*beg++;
            while(beg!=eof)
            {
                if(judge==*beg)
                {
                    beg=nums.erase(beg);
                    eof=nums.end();
                }
                else
                {
                    judge=*beg++;
                }
            }
            return nums.size();
        }
        else
            return 0;
    }
};
