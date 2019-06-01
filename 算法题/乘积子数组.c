#include<stdio.h>
int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    int i,j,product=0,t=0;
    for(i=0;i<numsSize;i++)
			if(nums[i]<k)
				t++;
    for(i=0;i<numsSize-1;i++)
    {
		product=nums[i];
		for(j=i+1;j<numsSize;j++)
    	{
			product*=nums[j];
    		if(product>=k)
    			break;
    		else t++;
		}
	}
	return t;
}
int main(void)
{
	int numsSize,i,ans,k;
	scanf("%d",&numsSize);
	int nums[numsSize];
	for(i=0;i<numsSize;i++)
		scanf("%d",&nums[i]);
	scanf("%d",&k);
	ans=numSubarrayProductLessThanK(nums,numsSize,k);
	printf("%d",ans);
} 
