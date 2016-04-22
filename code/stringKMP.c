#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
typedef char String[MAXSIZE + 1];/*第零位用于存储字符长度*/
void get_nextval(String T,int *nextval);
int Index(String S, String T, int pos);
int main() {
	
	String S="4abca", T;/*字符数组在初始化的同时一起赋值，否则只能如下单独赋值，用指针操作也只能单独赋值*/
	//S[0] = 4;
	//S[1] = 'a';
	//S[2] = 'b';
	//S[3] = 'c';
	//S[4] = 'a';
	/*char *p = S;
	p= "4abca";*/
	T[0] = 3;
	T[1] = 'b';
	T[2] = 'c';
	T[3] = 'a';
	printf("主串和子串在第%d个字符处首次匹配（KMP改良算法） \n", Index(S, T, 1));
	return 0;
}
/*获取j的回溯位置*/
void get_nextval(String T,int *nextval) {
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i<T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
				if (T[i] != T[j])
					nextval[i] = j;
				else
					nextval[i] = nextval[j];

		}
		else
			j = nextval[j];/*游标回溯进行下一轮搜索*/
	}
}
/*两个字符串进行扫描操作,返回一个位置值pos*/
int Index(String S, String T, int pos) {
	int i = pos;
	int j = 1;
	int nextval[255];
	get_nextval(T, nextval);
	while (i<=(S[0]-'0')&&j<=T[0])
	{
		if (j==0||S[i]==T[j])
		{
			++i;
			++j;
		}
		else
		{
			j = nextval[j];
		}
	}/*若跳出while循环，则T[0]全部扫描完成*/
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}