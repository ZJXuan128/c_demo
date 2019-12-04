#include<stdlib.h>
int getKth(int nums1[],int start1,int end1,int nums2[],int start2,int end2,int k)
{//数组大小始终不变，设置标志位来确定当前需要的部分。 
	int len1=end1-start1+1,len2=end2-start2+1;
	if(len1>len2) return getKth(nums2,start2,end2,nums1,start1,end1,k);
	/*将短的数组置为nums1方便处理*/
	
 	if(len1==0) return nums2[start2+k-1];
	/*一个数组为空，将另一个数组的第k个数返回，即找到第k小个数*/ 
	
	if(k==1) return nums1[start1]<nums2[start2]?nums1[start1]:nums2[start2];
	/*此时我们要找第 1 小的数字，所以只需判断两个数组中第一个数字哪个小就可以了*/
	
	int i=start1+(len1<k/2?len1:k/2)-1;
	int j=start2+(len2<k/2?len2:k/2)-1;
	if(nums1[i]>nums2[j]) return getKth(nums1,start1,end1,nums2,j+1,end2,k-(j-start2+1));
	else return getKth(nums1,i+1,end1,nums2,start2,end2,k-(i-start1+1));
	/*两个数组在下标为k/2时的值，将小的数组‘移除’前k/2个元素，k减少，大的不变*/ 
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int left=(nums1Size+nums2Size+1)/2,right=(nums1Size+nums2Size+2)/2;
    //偶数的中位数是中间两个数产生的均值，而认为奇数的中位数是中间单独的数和自己的均值。 
    return (getKth(nums1,0,nums1Size-1,nums2,0,nums2Size-1,left)+getKth(nums1,0,nums1Size-1,nums2,0,nums2Size-1,right))*0.5;
}


int main(void)
{
	int nums1[]={1},nums2[]={2,3};
	int nums1Size=1,nums2Size=2;
	double num=findMedianSortedArrays(nums1,nums1Size,nums2,nums2Size);
	printf("%lf",num);
}
