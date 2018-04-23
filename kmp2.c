#include<stdio.h>
int main()
 {
char * text,*pat;
int m,n,*pi,i,j,flag=0,q=0;
void Pifun(char *,int *,int);
FILE * fp;
i=0;
j=0;
text=(char *)malloc(sizeof(char)*40);
pat=(char *)malloc(sizeof(char)*10);
pi=(int *)malloc(sizeof(int)*10);
fp=fopen("kmp.txt","r");
fscanf(fp,"%s",text);
n=strlen(text);
fscanf(fp,"%s",pat);
m=strlen(pat);printf("\n text:%s  \npattern:%s\n",text,pat);
Pifun(pat,pi,m);
for(i=1;i<m;i++)
  printf("\nPi[%d]:%d",i,pi[i]);
for(i=1;i<n;i++)
 {
   while((q>0)&&(pat[q+1]!=text[i]))
        q=pi[q];
  if(pat[q+1]==text[i])
       q=q+1;	
  if(q==m-1)
	  {printf("\nPattern match at %d",i-m+1);
      q=pi[q];}
  }
 

printf("\n\n");

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
