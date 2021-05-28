//有很多种解法，这里使用空间复杂度为O(1)，时间复杂度为O(n)的环状替换法
//将数组移位看作是在圆圈内移动，移动一位到某位置后，继续将此位置的旧元素移动到下一位。
//注意：当绝对偏移量offset与数组长度有非1的公约数时，在移动最大公约数的倍数次时，会重复移动，所以需要根据次数，改变移动起点。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size(),offset=k%size;
        if(offset!=0)
        {   
           int gcd=std::gcd(size,offset); //求最大公约数，这里使用numeric的函数，下面注释是其一种实现方式
/*            int max=size,min=offset,gcd;
            while(min!=0)
            {
                gcd=min;
                min=max%gcd;
                max=gcd;
            }
*/
            int preious,j,multiple=size/gcd;	//preious用来保存被上一位元素替代的元素直，移动multiple次后会重复移动
            for(int i=0;i<size;++i)
            {                   
                if(i%multiple==0)		//判断是否重复移动，并改变移动起点
                {
                    j=i/multiple;
                    preious=nums[i/multiple];
                }
                int temp=nums[(j+offset)%size];
                nums[(j+offset)%size]=preious;			//移动数据
                j=(j+offset)%size;
                preious=temp;
            }
        }
    }
};
