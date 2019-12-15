#include<stdio.h>

int maximumGap(int* nums, int numsSize)
{
	if(numsSize<2) return 0;
	int intMax=-2147483647;
	int intMin=2147483647;
	int maxval=intMax,minval=intMin;
	int i;
	for(i=0;i<numsSize;i++)
	{
		if(nums[i]>maxval) maxval=nums[i];
		if(nums[i]<minval) minval=nums[i];
	}
	if(minval==maxval) return 0;
	 
	if(numsSize==2) return maxval-minval;
	 
	int len=(maxval-minval)/(numsSize-1)+((maxval-minval)%(numsSize-1)!=0);//向上取整 
	int n=(maxval-minval)/len;
	int maxBuk[n+1];
	int minBuk[n+1];
	for(i=0;i<n+1;i++)
	{
		maxBuk[i]=intMax;
		minBuk[i]=intMin;
	}
	int temp;
	for(i=0;i<numsSize;i++)
	{
		temp=(nums[i]-minval)/len;
		maxBuk[temp]=nums[i]>maxBuk[temp]?nums[i]:maxBuk[temp];
		minBuk[temp]=nums[i]<minBuk[temp]?nums[i]:minBuk[temp];
	}
	 
	int gap=0;
	int pre =maxBuk[0];
	for(i=1;i<=n;i++)
	{
		if(maxBuk[i]==intMax&&minBuk[i]==intMin)
		{
			continue;
		}
		gap=gap>minBuk[i]-pre?gap:minBuk[i]-pre;
		pre=maxBuk[i];
	}
	return gap;
}

int main(void)
{
	int num[]={3,6,9,1},len=4;
	printf("%d",maximumGap(num,len));
}
