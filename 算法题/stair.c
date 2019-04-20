#include<stdio.h>
//#include<math.h>
int PermuteCombine(int WayNum,int StairsNum)//ȫ���Ⱦ����ܶ��ת��Ϊһ��2��̨�׵ķ��������ٽ�һ��2��̨�ײ��Ϊ����һ��̨�ף������ܴ�����������ϡ� 
{
	int i;
	if(StairsNum%2==0)//�ܽ���������ż�ж� �������ͬС�죬���Ӷ����¡��Ե����ķ��������� ����Ϊһ����ģ�Դ������ 
		for(i=0;i<=StairsNum/2;i++)
			WayNum+=C(StairsNum/2+i,StairsNum/2-i);
	else
		for(i=0;i<(StairsNum+1)/2;i++)
			WayNum+=C((StairsNum+1)/2+i,(StairsNum-1)/2-i); 
	return WayNum;
}
int factorial(int n)//�׳˺��� n�� 
{
	if(n==1)	return 1;//�ݹ���� 
	return n*factorial(n-1);
}
int C(int n,int m)//������ѧ������������ ,n����ͬԪ����ȡ��m��Ԫ�ص���������÷��� C(n,m) ��ʾ
{
	if(m==0||n==m)//����������� 
		return 1;
	else
		return (factorial(n)/(factorial(n-m)*factorial(m)));//���㹫ʽC(n,m)=n!/[m!*(n-m)!]��������� 
}


int recursion(int NowNum,int StairsNum)//��0��̨�׿�ʼģ����¥�ݣ�����һ���ݹ��� ��ÿһ�㶼��������֧ѡ��+1��+2�� 
{						//�����ݹ���� 
	if(NowNum>StairsNum)//��һ�׼�2�󳬳��ܽ��� ��˷�����Ч������ 
		return 0;
	if(NowNum==StairsNum)//�պ������ܽ���   ��˷������ڵݹ����еķ�֧·������Ч��һ�� 
		return 1;
	return recursion(NowNum+1,StairsNum)+recursion(NowNum+2,StairsNum);// ����ǰ������·�������������һ�㣬ֱ������ ����һ�㷽�����²㷽�����ܺͣ�ÿ�㶼��������֧�� 
}



int MemoRecur(int NowNum,int StairsNum,int memo[])// ֮ǰ�ĵݹ�����д������ظ����㣬�Ľ����ÿһ������������������Ա���Ҫ��ʱ��ֱ��ʹ�þͲ����ٴν���ݹ���㣬����ʱ�䣬���������ռ��n��С�Ŀռ� 
{
	if(NowNum>StairsNum)
		return 0;
	if(NowNum==StairsNum)
		return 1;
	if(memo[NowNum]>0)
		return memo[NowNum];
	memo[NowNum]=MemoRecur(NowNum+1,StairsNum,memo)+MemoRecur(NowNum+2,StairsNum,memo);
	return memo[NowNum]; 
}


int DynamicProgram(int StairsNum)
{
	int dp[StairsNum+1],i;
	dp[1]=1,dp[2]=2;
	for(i=3;i<StairsNum+1;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp[StairsNum];
}

int Fib(int StairsNum)//ֱ��ʹ�ù�ʽ,�ռ�O(1),����ʹ��POW������ʱ���ΪO(log n) 
{
	double s5=sqrt(5);
	return	(int)(1/s5*(pow((1+s5)/2,StairsNum+1)-pow((1-s5)/2,StairsNum+1)));//�������ڼ��㾫�����⣬���ٲ��ִ���׼ȷֵ���1�� 
}

int Binest(int StairsNum)//����һ��2*2��ʼ����1110���Լ�һ�����ڼ���ľ���Q�����Խ���Ϊ��n+1��쳲��������к͵�n-1��쳲��������У����Խ��߾�Ϊ��n��쳲��������У�Q��n-1�η������Ͻ���Ϊ��n��쳲��������� 
{
	int Q[2][2]={{1,1},{1,0}};//��ʼ���� 
	int result=POW(Q,StairsNum);
	return result;
}
int POW (int Q [2][2],int StairsNum)
{
	int tep[2][2],i,j,k,init[2][2]={{1,1},{1,0}};
	for(i=1;i<StairsNum;i++)
	{
		for(j=0;j<2;j++)//����Q�������ڼ��� 
			for(k=0;k<2;k++)
				tep[j][k]=Q[j][k];
		for(j=0;j<2;j++)//�˳�ʼ���� 
			for(k=0;k<2;k++)
				Q[j][k]=tep[0][k]*init[j][0]+tep[1][k]*init[j][1];
	}
	return Q[0][0];
}
int main(void)
{
	int StairsNum,WayNum;
	while(1)
	{
	scanf("%d",&StairsNum);
	//WayNum=PermuteCombine(WayNum=0,StairsNum);//Permutation and combination ������Ϸ��������ܷ�������ʼ������������Ϲ�ʽ�㡣 
	//WayNum=recursion(0,StairsNum);//���εݹ飬ʱ�临�Ӷ�O(2^n),�ռ����δ�С2^n 
	/*int memo[StairsNum+1],i;
	for(i=0;i<StairsNum+1;i++)//�����������鳤�Ⱥ��޷�ֱ�ӳ�ʼ�������������ѭ����ʼ�����顣 
		memo[i]=0;
	WayNum=MemoRecur(0,StairsNum,memo);//�Ľ�֮ǰ�ĵݹ鷽�������������Ϊ���仯�ݹ� */
	//WayNum=DynamicProgram(StairsNum); //���������������Ž⹹���������Ž⣬���ö�̬�滮�����i�׿���(i-1)����1�׻�(i-2)�������׵õ����滮��������������ɵڶ�����1�׻��1�������׵õ������Ľ���������1��2����2...���� 
	//WayNum=Fib(StairsNum);//ÿ��ֻ����һ����ף��䶯̬�滮����쳲��������У�ֱ�Ӽ���ͨ��� ��쳲���������ͨ�ʽ�õ��� 
	//WayNum=Binest(StairsNum);
	printf("%d\n",WayNum);
	}
}
/*�ܽ᣺��¥�������ڱ�������˵���ǽ��������Ž�ת��Ϊ���������Ž⣬��ѡ����������̬�滮��̰���㷨��
���嵽��������쳲��������е�Ӧ���Լ��򻯣����Ƕ�̬�滮�ڴ������µ���ѧ�Ż�����������Ϸ�������̰���㷨�����֣�
����������������һ�㻯��ͨ�õĽ���������ôӱ��ʵĶ�̬�滮��̰�����֣�����̬�滮�����̰���������ʵ�֣�
 ��̰�ĵ�ÿһ����������Խ������ֱ��Ӱ�죬����̬�滮���԰�֮ǰ�����ݱ����������Ի��ˣ����ݸ����壬�ɲ����Ը�ǿ��*/
