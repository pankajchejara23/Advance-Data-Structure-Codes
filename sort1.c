#include<stdio.h>
int main()
 { FILE * f,*of;
 void bubblesort(int *,int);
 void selectionsort(int *,int);
 void insertionsort(int *,int);
 int * a,ch,size,i;
 printf("Enter size of array");
 scanf("%d",&size);
 a=(int *)malloc(sizeof(int)*size);
 f=fopen("data3.txt","r");
 for(i=0;i<size;i++)
  fscanf(f,"%d",&a[i]);
   while(ch!=4)
	{
	printf("\n=======================Sorting Technique=========================");
	printf("\n\t1.BUBBLE SORT");
	printf("\n\t2.SELECTION SORT");
	printf("\n\t3.INSERTION SORT");
	printf("\n\t4.EXIT");
	printf("\n\t\tEnter choice..........");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:bubblesort(a,size);
		break;
	case 2:selectionsort(a,size);
		break;
	case 3:insertionsort(a,size);
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
 void bubblesort(int *a,int size)
  {
   int i,j,t;
   FILE * of;
   for(i=0;i<size-1;i++)
     for(j=0;j<size-1-i;j++)
      {
         if(a[j]>a[j+1])
           { 
		t=a[j];
                a[j]=a[j+1];
       	        a[j+1]=t;
           }
	}
  of=fopen("out1.txt","a");
 fprintf(of,"\n%s","Bubble Sort:");
 for(i=0;i<size;i++)
  fprintf(of,"%d\t",a[i]);	
  }
 void selectionsort(int *a,int size)
  {
   FILE * of;
   int i,j,t;
   int in;
   for(i=0;i<size-1;i++)
    {
     in=i;
     for(j=i+1;j<size;j++)
        { 
          if(a[in]>a[j])
            {
              in=j;
             }
          }
     if(i!=in)
      {
        t=a[i];
        a[i]=a[in];
        a[in]=t;
       }
   }
   of=fopen("out1.txt","w");
  fprintf(of,"\n%s","Selection Sort:");
 for(i=0;i<size;i++)
  fprintf(of,"%d\t",a[i]);	
 }
void insertionsort(int *a,int size)
  {
	FILE * of;
	int i,j,t;
  for(i=1;i<size;i++)
    { t=a[i];
      j=i-1;
    while((t<a[j])&&(j>=0))
      { a[j+1]=a[j];
        j--;
      }
   a[j+1]=t;
    }
of=fopen("out1.txt","a");
 fprintf(of,"\n%s","Insertion Sort:");
 for(i=0;i<size;i++)
  fprintf(of,"%d\t",a[i]);	
  }


