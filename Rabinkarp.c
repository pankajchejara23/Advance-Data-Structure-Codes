#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
 {
  char * text;
  char * pattern;
  int radix,i,s,n,m,t,p,h,temp;
  FILE *fp;
  int prime=13;
  fp=fopen("rabinkarp.txt","r");
  text=(char *)malloc(sizeof(char)*40);
  pattern=(char *)malloc(sizeof(char)*40);
  fscanf(fp,"%d",&radix);
  fscanf(fp,"%s",text);
  fscanf(fp,"%s",pattern);
 
  printf("\n Text:%s \n Pattern:%s \nRadix:%d",text,pattern,radix);
  
  n=strlen(text);
  m=strlen(pattern);
  h=1;
  for(i=0;i<m-1;i++)
     h=h*radix;
  p=0;
  t=0;
  for(i=0;i<m;i++)
    {
    p=(radix*p+(pattern[i]-97)) % prime;
    t=(radix*t+(text[i]-97)) % prime;
    }
  printf("\n p:%d t:%d",p,t);
 i=0;
 for(s=0;s<n-m;s++)
    {
      if(p==t)
	{
	      while(i<m)
		{
		if(pattern[i]==text[s+i])
			i++;
		}
	     if(i==m)
		printf("\nPattern Found at:%d shift",s);
	     else
		printf("\n Spurious hit at:%d",s);
	     i=0;	
	}
        t=( radix *(t - (text[s]-97)*h)+(text[s+m]-97)) % prime;
        temp=(text[s]-97)*h;
        /*printf("\n Minus:%d Adding:%d  ",temp,(text[s+m]-97));
        printf("\nLeaving:%c and Adding:%c",text[s],text[s+m]);
	printf("\n\t\t%d t value:%d",s,t);*/
   }
 printf("\n");
 return 0;
 }
