#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
typedef char String[MAXSIZE + 1];/*����λ���ڴ洢�ַ�����*/
void get_nextval(String T,int *nextval);
int Index(String S, String T, int pos);
int main() {
	
	String S="4abca", T;/*�ַ������ڳ�ʼ����ͬʱһ��ֵ������ֻ�����µ�����ֵ����ָ�����Ҳֻ�ܵ�����ֵ*/
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
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�����㷨�� \n", Index(S, T, 1));
	return 0;
}
/*��ȡj�Ļ���λ��*/
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
			j = nextval[j];/*�α���ݽ�����һ������*/
	}
}
/*�����ַ�������ɨ�����,����һ��λ��ֵpos*/
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
	}/*������whileѭ������T[0]ȫ��ɨ�����*/
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}