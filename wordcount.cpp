#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int countc(char *file);
int countw(char *file);
int countc(char *file) //�����ļ����ַ��� 
{   
	int zifu=0;
	FILE *f=fopen(file, "r"); 
	char a; 
	if(f==NULL) 
	{ 
		printf("��ȡ�ļ�ʧ��"); 
	} 
	else while (!feof(f)) 
	{ 
		a=fgetc(f);
		if (a != ' ' && a != '\n'&&a != '\t') zifu++; 
	} 
	fclose(f);
	printf("charnum:%d ",zifu); 
	return zifu;
}
int countw(char *file)//�����ļ��ʵ���Ŀ 
{   
	int cword=0,aword;
	FILE *f=fopen(file,"r"); 
	char ch; 
	if(f == NULL) 
	{ 
		printf("��ȡ�ļ�ʧ��"); 
	} 
	else while(!feof(f)) 
	{ 
		ch=fgetc(f); 
		if((ch >= 'a' && ch <= 'z')||(ch>='A' && ch<='Z')||ch=='_'||(ch >= '0' && ch <= '9')) 
			aword=1; 
		else if (aword) 
		{ 
			cword++; 
			aword=0; 
		} 
	} 
	fclose(f); 
	printf("wordnum:%d ",cword); 
	return cword;
}
int main(int argc, char* argv[])             
{
    FILE *fp;
	while(1)
	{
		if((fp=fopen(argv[2],"r"))==NULL)
		{ 
			printf("��ȡ�ļ�ʧ��\n"); 
			scanf("%s%s%s",argv[0],argv[1],argv[2]); 
			continue; 
		} 
		else if(!strcmp(argv[1],"-w")) countw(argv[2]); 
		else if(!strcmp(argv[1],"-c")) countc(argv[2]); 
		else printf("NullPoint\n"); 
		printf("\n\n"); 
		scanf("%s%s%s",argv[0],argv[1],argv[2]); 
	} 
	return 0; 
}
/*#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int CharCount(char* filename);  //�ַ�ͳ�ƺ���
int WordCount(char* filename);  //����ͳ�ƺ���



int CharCount(char* filename) //�ַ�ͳ�ƺ���
{
	FILE* fp = fopen(filename, "r");
	int c = 0;
	char ch;
	if (fp == NULL)
	{
		printf("file read failure.");
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		c++;
		ch = fgetc(fp);
	}
	fclose(fp);
	return c;
}

int WordCount(char* filename) //����ͳ�ƺ���
{
	FILE* fp;
	int w = 0;
	char ch;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("file read failure.");
	}
	ch = fgetc(fp);
	while (ch != EOF)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
		{
			while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')
			{
				ch = fgetc(fp);
			}
			w++;
			ch = fgetc(fp);
		}
		else
		{
			ch = fgetc(fp);
		}
	}

	fclose(fp);
	return w;

}



int main(int argc, char* argv[])
{
	if ((strcmp(argv[1], "-c") == 0))
	{
		int a = CharCount(argv[2]);
		printf("�ַ�����%d", a);
	}

	if ((strcmp(argv[1], "-w") == 0))

	{
		int b = WordCount(argv[2]);
		printf("��������%d", b);
	}
	return 0;
}*/