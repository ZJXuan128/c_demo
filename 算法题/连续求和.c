#include<stdio.h>

int consecutiveNumbersSum(int N)
{
    int start,sum,count=0,n;
    for(start=1;start<=N;start++)
    {
        for(n=1;sum<N;n++)
        {
            sum=start*n+(n*n-n)/2;
            if(sum==N)
                count+=1;
        }
        sum=0;
    }
    return count;
}

int main(void)
{
	int N,res;
	scanf("%d",&N);
	res=consecutiveNumbersSum(N);
	printf("%d",res);
}
