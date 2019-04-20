#include <stdio.h>
int coins[101]={0};//Ӳ�����飬�ٱ�ֵ��Ϊ-1�����ֵΪ0 
int FindCoin(int right,int left)
{
	int n=right-left+1;//nΪ�ö�Ӳ������ 
	int k1=left+Judgement(n)-1;//k1Ϊ��һ�����һ���±� 
	int k2=left+2*Judgement(n)-1;//k2Ϊ�ڶ������һ���±�
	if(Weight(left,k1) == Weight(k1+1,k2))//ǰ������ȣ��ٱ��ڵ�����
	{
		if(right-k2==1)//������һ��ֻ��һ�������Ӳ��Ϊ�ٱ� 
			return right;
		else
		{
			left=k2+1;//������������һ�Ѳ��� (�ݹ�) 
			return FindCoin(left,right);
		}
	} 
	else if(Weight(left,k1)<Weight(k1+1,k2))//�����һ��С�ڵڶ��ѣ����ҵ�һ�� 
	{
		if(k1==left)//�����һ��ֻ��һ������Ϊ�ٱ� 
            return left;
		else 
		{
        	right=k1;//����������ҵ�һ�� 
            return FindCoin(left,right);
        }
	} 
	else//�ڶ���С�ڵ�һ�ѣ����ҵڶ��� 
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
int Judgement(int n)//�ж��Ƿ������ı��������ֱ��� 
{
	if(n%3==0)
		return n/3;
	else
		return n/3+1;
}
int Weight(int left,int right)//Ӳ��������
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
	printf("������Ӳ��������");
	scanf("%d",&n);
	printf("������ٱұ�ţ�\n");
	scanf("%d",&num);
	coins[num] = -1;
	index = FindCoin(0 , n);
	printf("�ٱұ��Ϊ:%d",index);
}

