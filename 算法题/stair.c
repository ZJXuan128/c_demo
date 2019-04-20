#include<stdio.h>
//#include<math.h>
int PermuteCombine(int WayNum,int StairsNum)//全部先尽可能多的转化为一次2个台阶的方法，，再将一次2个台阶拆解为两个一次台阶，在在总次数中排列组合。 
{
	int i;
	if(StairsNum%2==0)//总阶数进行奇偶判断 ，处理大同小异，均从顶向下、以迭代的方法将问题 扩大为一个规模稍大的问题 
		for(i=0;i<=StairsNum/2;i++)
			WayNum+=C(StairsNum/2+i,StairsNum/2-i);
	else
		for(i=0;i<(StairsNum+1)/2;i++)
			WayNum+=C((StairsNum+1)/2+i,(StairsNum-1)/2-i); 
	return WayNum;
}
int factorial(int n)//阶乘函数 n！ 
{
	if(n==1)	return 1;//递归出口 
	return n*factorial(n-1);
}
int C(int n,int m)//利用数学定义计算组合数 ,n个不同元素中取出m个元素的组合数。用符号 C(n,m) 表示
{
	if(m==0||n==m)//特殊情况处理 
		return 1;
	else
		return (factorial(n)/(factorial(n-m)*factorial(m)));//计算公式C(n,m)=n!/[m!*(n-m)!]将结果返回 
}


int recursion(int NowNum,int StairsNum)//从0阶台阶开始模拟爬楼梯，构建一个递归树 ，每一层都有两个分支选择，+1或+2。 
{						//两个递归出口 
	if(NowNum>StairsNum)//上一阶加2后超出总阶数 则此方法无效不计数 
		return 0;
	if(NowNum==StairsNum)//刚好满足总阶数   则此方法（在递归树中的分支路径）有效记一次 
		return 1;
	return recursion(NowNum+1,StairsNum)+recursion(NowNum+2,StairsNum);// 将当前方法（路径）继续深化到下一层，直到返回 。上一层方法是下层方法的总和，每层都有两个分支。 
}



int MemoRecur(int NowNum,int StairsNum,int memo[])// 之前的递归过程有大量的重复计算，改进后把每一步结果都储存下来，以便需要的时候直接使用就不用再次进入递归计算，减少时间，定义数组会占用n大小的空间 
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

int Fib(int StairsNum)//直接使用公式,空间O(1),由于使用POW函数，时间变为O(log n) 
{
	double s5=sqrt(5);
	return	(int)(1/s5*(pow((1+s5)/2,StairsNum+1)-pow((1-s5)/2,StairsNum+1)));//可能由于计算精度问题，极少部分答案与准确值相差1， 
}

int Binest(int StairsNum)//设置一个2*2初始矩阵1110，以及一个用于计算的矩阵Q，主对角线为第n+1项斐波那契数列和第n-1项斐波那契数列，副对角线均为第n项斐波那契数列，Q的n-1次方的左上角项为第n项斐波那契数列 
{
	int Q[2][2]={{1,1},{1,0}};//初始矩阵 
	int result=POW(Q,StairsNum);
	return result;
}
int POW (int Q [2][2],int StairsNum)
{
	int tep[2][2],i,j,k,init[2][2]={{1,1},{1,0}};
	for(i=1;i<StairsNum;i++)
	{
		for(j=0;j<2;j++)//复制Q矩阵用于计算 
			for(k=0;k<2;k++)
				tep[j][k]=Q[j][k];
		for(j=0;j<2;j++)//乘初始矩阵 
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
	//WayNum=PermuteCombine(WayNum=0,StairsNum);//Permutation and combination 排列组合方法，将总方法数初始化。用排列组合公式算。 
	//WayNum=recursion(0,StairsNum);//树形递归，时间复杂度O(2^n),空间树形大小2^n 
	/*int memo[StairsNum+1],i;
	for(i=0;i<StairsNum+1;i++)//变量定义数组长度后无法直接初始化，定义完后用循环初始化数组。 
		memo[i]=0;
	WayNum=MemoRecur(0,StairsNum,memo);//改进之前的递归方案，增加数组变为记忆化递归 */
	//WayNum=DynamicProgram(StairsNum); //可以由子问题最优解构建整体最优解，采用动态规划，如第i阶可由(i-1)阶爬1阶或(i-2)阶爬两阶得到，规划到最初，第三阶由第二阶爬1阶或第1阶爬两阶得到，第四阶是三阶爬1或2阶爬2...类推 
	//WayNum=Fib(StairsNum);//每次只能走一或二阶，其动态规划符合斐波那契数列，直接计算通项即可 由斐波那契数列通项公式得到答案 
	//WayNum=Binest(StairsNum);
	printf("%d\n",WayNum);
	}
}
/*总结：爬楼梯问题在本质上来说就是将整体最优解转化为子问题最优解，可选方案包括动态规划与贪心算法，
具体到本问题中斐波那契数列的应用以及简化，都是动态规划在此情形下的数学优化，而排列组合方法则是贪心算法的体现，
如果将问题的特征更一般化，通用的解决方案还得从本质的动态规划和贪心入手，而动态规划相比于贪心则更容易实现，
 且贪心的每一个操作都会对结果产生直接影响，而动态规划可以把之前的数据保存下来可以回退，数据更立体，可操作性更强。*/
