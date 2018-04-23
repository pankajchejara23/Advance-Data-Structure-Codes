#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
 {
char * text,*pat;
int * gama,*delta;
int m,n,*pi,i,j,flag=0,q=0,s;
FILE *fp;

void Pifun(char *,int *,int);
void Lastoccur(char *,int *,int );
void Computesuffix(char *,int *,int);
fp=fopen("moore.txt","r");
xt=(char *)malloc(sizeof(char)*40);
pat=(char *)malloc(sizeof(char)*10);

fscanf(fp,"%s",text);
n=strlen(text);
fscanf(fp,"%s",pat);
m=strlen(pat);
printf("Text:%s \n  Pattern:%s",text,pat);
Lastoccur(pat,delta,m);
Computesuffix(pat,gama,m);
s=0;
for(i=0;i<m;i++)
  printf("\n%c:%d",pat[i],delta[pat[i]-97]);

 while(s<=(n-m))
	{
	 j=m;
	 while((j>0)&&(pat[j]==text[s+j]))
		j--;
	 if(j==0)
		{
		printf("Pattern found at:%d shift",s);
		s=s+gama[0];
		}
	else
		s=s+max(gama[j],j-delta[text[s+j]]);
        }

printf("\n");
return 0;
 }
void Pifun(char *pat,int * pi,int m)
 {
  int k,q;
  pi[1]=0;
  k=0;
  for(q=2;q<m;q++)
	{
	  while((k>0)&&(pat[q]!=pat[k+1]))
	   k=pi[q];
	 if(pat[q]==pat[k+1])
	  k=k+1;
	 pi[q]=k;
	}
 }
void Lastoccur(char * pattern,int * delta,int m)
 {
  int i;
  for(i=0;i<m;i++)
	delta[(pattern[i]-97)]=i;
  }

void Computesuffix(char * pattern,int * gama,int m)
 {
int * pi,*pi1;
  char * reverse;
  int i,j,l;
  j=0;
  pi=(int *)malloc(sizeof(int)*m);
  pi1=(int *)malloc(sizeof(int)*m);
  reverse=(char *)malloc(sizeof(char)*m);
  for(i=m-1;i>=0;i--)
	reverse[j++]=pattern[i];
  reverse[j]='\0';
   printf("\n Reverse is:%s",reverse);
  Pifun(pattern,pi,strlen(pattern));
  for(i=0;i<m;i++)
    printf("\n %c:%d",pattern[i],pi[i]);
  Pifun(reverse,pi1,strlen(reverse));
  printf(" char     position        Pi          Pi1");
  for(i=1;i<m;i++)
	 printf("%c     %d           %d        %d",pattern[i],i,pi[i],pi1[i]);



  for(j=0;j<m;j++)
	gama[j]=m-pi[m];
  for(l=1;l<=m;l++)
	{
	j=m-pi1[l];
	 if(gama[j]>(l-pi1[l]))
		gama[j]=l-pi1[l];
  	}
  }
  
