#include<stdio.h>
#define true 1
#define false 0
int ugly(int num)
{
	if(num<=1)
		return (num==1)?true:false;
        while(num>1)
		{
            int t = num;
            while(t%2==0) t/=2;
            while(t%3==0) t/=3;
            while(t%5==0) t/=5;
            if(t==num)
				return false;
            num=t;
        }
        return true;
}
int main(void)
{
	int num;
	char re[10];
	scanf("%d",&num);
	printf("%s",(ugly(num))?"true":"flase");
}
