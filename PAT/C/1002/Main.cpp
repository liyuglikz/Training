#include <stdio.h>
#include <string.h>
/*
   题意：将一个数每位相加，结果以拼音方式输出
   比如输入：123，输出：liu
   */

const int MAXN = 105;
char s[MAXN];//存储输入的数字
char num[][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};//数字到拼音
int ans[30];//暂存答案
int len = 0;

int main()
{
	int sum = 0;	

	scanf("%s", s);//输入数字
	for(int i = 0; i < strlen( s ); ++i)
		sum += (s[i] - '0');	//求和

	while( sum )
	{
		ans[len++] = sum % 10;
		sum /= 10;
	}//将答案的每一位分解

	if( len == 0 )
	{
		puts( num[0] );
		return 0;
	}//特殊情况：只有一个零的时候

	while( len )
	{
		printf("%s", num[ ans[--len] ]);
		if( len != 0 )
			printf(" ");//最后一位不需要空格
	}//将答案每一位对应的拼音输出
	printf("\n");
	return 0;
}
