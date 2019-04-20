#include <stdio.h>
int coins[101]={0};//硬币数组，假币值存为-1，真币值为0 
int FindCoin(int right,int left)
{
	int n=right-left+1;//n为该堆硬币数量 
	int k1=left+Judgement(n)-1;//k1为第一堆最后一个下标 
	int k2=left+2*Judgement(n)-1;//k2为第二堆最后一个下标
	if(Weight(left,k1) == Weight(k1+1,k2))//前两堆相等，假币在第三堆
	{
		if(right-k2==1)//如果最后一堆只有一个，则该硬币为假币 
			return right;
		else
		{
			left=k2+1;//否则继续对最后一堆查找 (递归) 
			return FindCoin(left,right);
		}
	} 
	else if(Weight(left,k1)<Weight(k1+1,k2))//如果第一堆小于第二堆，查找第一堆 
	{
		if(k1==left)//如果第一堆只有一个，则为假币 
            return left;
		else 
		{
        	right=k1;//否则继续查找第一堆 
            return FindCoin(left,right);
        }
	} 
	else//第二堆小于第一堆，查找第二堆 
	{
		if ((k2-k1)==1)
        	return k2;
         else 
		 {
            left=k1+1;
            right=k2;
            return FindCoin(left,right);
        }
	}
}
int Judgement(int n)//判断是否是三的倍数，并分别处理 
{
	if(n%3==0)
		return n/3;
	else
		return n/3+1;
}
int Weight(int left,int right)//硬币总重量
{
	int sum = 0;
	int i;
	for(i=left;i<right+1;i++)
		sum += coins[i];
	return sum;
}
int main()
{
	int n,num,index;
	printf("请输入硬币数量：");
	scanf("%d",&n);
	printf("请输入假币编号：\n");
	scanf("%d",&num);
	coins[num] = -1;
	index = FindCoin(0 , n);
	printf("假币编号为:%d",index);
}

