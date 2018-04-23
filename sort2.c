#include<stdio.h>
int main()
 { 
 FILE * f,*of;
 void quicksort(int *,int,int);
 void radixsort(int *,int);
 void mergesort(int *,int);
 int * a,ch,size,i;
 printf("Enter size of array");
 scanf("%d",&size);
 a=(int *)malloc(sizeof(int)*size);
 f=fopen("data3.txt","r");
 for(i=0;i<size;i++)
 fscanf(f,"%d",&a[i]);
 f=fopen("output.txt","w");
 fprintf(f,"%s","Sorting quick radix merge");
 close(f);
   while(ch!=4)
	{
	printf("\n=======================Sorting Technique=========================");
	printf("\n\t1.QUICK SORT");
	printf("\n\t2.RADIX SORT");	
	printf("\n\t3.MERGE SORT");	
	printf("\n\t4.EXIT");
	printf("\n\t\tEnter choice..........");
	scanf("%d",&ch);
	switch(ch)
	{
	
	case 1:quicksort(a,0,size-1);
		break;
	case 2:radixsort(a,size);
		break;
	case 3:mergesort(a,size);
		break;
	defaul:ch=4;
		break;
	}
       for(i=0;i<size;i++)
          printf("\n%d",a[i]);
        printf("\n");
        }

 printf("\n");

 return 0;
}
 void  quicksort(int * a,int l,int r)
  { FILE * of;
    int q,i;
     if(l<r)
	{
         q=partition(a,l,r);
	 quicksort(a,l,q-1);
	 quicksort(a,q+1,r);
	}
  of=fopen("output.txt","w");
 if(of==NULL)
	printf("\nError occured");
 fprintf(of,"%s","Quick Sort:");
 for(i=l;i<=r;i++)
  fprintf(of,"%d\t",a[i]);
 fclose(of);	
  }

 

int partition(int * a,int lb,int ub)
{
 int down,up,t,pivot;
down=lb;
up=ub;
pivot=a[lb];
while(down<up)
{
 while(a[down]<=pivot && down<up)
down++;
while(a[up]>pivot)
up--;
if(down<up)
{
t=a[down];
a[down]=a[up];
a[up]=t;
}
}
a[lb]=a[up];
a[up]=pivot;
return(up);
}	
	
 int digit(int n,int k)
{
int d,i=1;
while(i<=k)
{
d=n%10;
n=n/10;
i++;
}
return(d);
}
void radixsort(int* a,int n)
{
FILE *of;
int mat[10][n],i,j,k,l,row,col,m,d;
m=0;
for(i=0;i<n;i++)
  if(m<a[i])
    m=a[i];

while(m>0)
  {d++;
   m=m/10;
   }
for(k=1;k<=d;k++)
{
 for(i=0;i<10;i++)
	for(j=0;j<n;j++)
           mat[i][j]=-1;
for(i=0;i<n;i++)
{
 row=digit(a[i],k);
col=0;
while(mat[row][col]!=-1)
  col++;
mat[row][col]=a[i];
}
l=0;
for(i=0;i<10;i++)
	for(j=0;j<n;j++)
	if(mat[i][j]!=-1)
a[l++]=mat[i][j];
}
of=fopen("output.txt","a");
 fprintf(of,"\n%s","Radix Sort:");
 for(i=0;i<n;i++)
  fprintf(of,"%d\t",a[i]);
 fclose(of);
}            
void mergesort(int *a,int n)
{
 FILE *fp;
int i,j,k,lb1,lb2,ub1,ub2,t[n],sz;
sz=1;
while(sz<n)
{
 lb1=0;
k=0;
while((lb1+sz)<n)
{
lb2=lb1+sz;
ub1=lb2-1;
ub2=(ub1+sz)<n?(ub1+sz):n-1;
for(i=lb1,j=lb2;i<=ub1&&j<=ub2;k++)
{
if(a[i]<a[j])
t[k]=a[i++];
else
t[k]=a[j++];
}
while(i<=ub1)
t[k++]=a[i++];
while(j<=ub2)
t[k++]=a[j++];
lb1=ub2+1;
}
while(k<n)
{
t[k]=a[k];
k++;}
for(i=0;i<n;i++)
a[i]=t[i];
sz=2*sz;
}
fp=fopen("output.txt","a");
fprintf(fp,"\n%s","merge Sort:");
for(i=0;i<n;i++)
{
fprintf(fp,"%d\t",a[i]);
}
fclose(fp);
}

