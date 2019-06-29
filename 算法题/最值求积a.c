#include<stdio.h> 
int maximumProduct(int* nums,int numsSize)
{
	
	int max1=-1001,max2=-1001,max3=-1001,min1=1000,min2=1000;
	int i;
	for(i=0;i<numsSize;i++)
	{
		if(nums[i]>max1)
		{
			max3=max2;
			max2=max1;
			max1=nums[i];
		}
		else if(nums[i]>max2)
		{
			max3=max2;
			max2=nums[i];
		}
		else if(nums[i]>max3)
			max3=nums[i];

		if (nums[i]<min1)
		{
			min2=min1;
			min1=nums[i];
		}
		else if(nums[i]<min2)
			min2=nums[i];
	}
	int res=max1*max2*max3;
	if (min1*min2*max1>res)
		res=min1*min2*max1;
	return res;
}
int main(void)
{
	int len,i,res;
	scanf("%d",&len);
	int num[len];
	for(i==0;i<len;i++)
		scanf("%d",&num[i]);
	res=maximumProduct(num,len);
	printf("%d",res);
}
