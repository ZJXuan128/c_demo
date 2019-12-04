#include<stdlib.h>
int getKth(int nums1[],int start1,int end1,int nums2[],int start2,int end2,int k)
{//�����Сʼ�ղ��䣬���ñ�־λ��ȷ����ǰ��Ҫ�Ĳ��֡� 
	int len1=end1-start1+1,len2=end2-start2+1;
	if(len1>len2) return getKth(nums2,start2,end2,nums1,start1,end1,k);
	/*���̵�������Ϊnums1���㴦��*/
	
 	if(len1==0) return nums2[start2+k-1];
	/*һ������Ϊ�գ�����һ������ĵ�k�������أ����ҵ���kС����*/ 
	
	if(k==1) return nums1[start1]<nums2[start2]?nums1[start1]:nums2[start2];
	/*��ʱ����Ҫ�ҵ� 1 С�����֣�����ֻ���ж����������е�һ�������ĸ�С�Ϳ�����*/
	
	int i=start1+(len1<k/2?len1:k/2)-1;
	int j=start2+(len2<k/2?len2:k/2)-1;
	if(nums1[i]>nums2[j]) return getKth(nums1,start1,end1,nums2,j+1,end2,k-(j-start2+1));
	else return getKth(nums1,i+1,end1,nums2,start2,end2,k-(i-start1+1));
	/*�����������±�Ϊk/2ʱ��ֵ����С�����顮�Ƴ���ǰk/2��Ԫ�أ�k���٣���Ĳ���*/ 
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int left=(nums1Size+nums2Size+1)/2,right=(nums1Size+nums2Size+2)/2;
    //ż������λ�����м������������ľ�ֵ������Ϊ��������λ�����м䵥���������Լ��ľ�ֵ�� 
    return (getKth(nums1,0,nums1Size-1,nums2,0,nums2Size-1,left)+getKth(nums1,0,nums1Size-1,nums2,0,nums2Size-1,right))*0.5;
}


int main(void)
{
	int nums1[]={1},nums2[]={2,3};
	int nums1Size=1,nums2Size=2;
	double num=findMedianSortedArrays(nums1,nums1Size,nums2,nums2Size);
	printf("%lf",num);
}
