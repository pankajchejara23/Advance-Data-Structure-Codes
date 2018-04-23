#include<stdio.h>
int t;
int v;
int w[20][20];
int color[20];
int finish[20];
int arrival[20];
typedef struct nod
 {
  int vert;
  struct nod * next;
 }node;
node * head,*n;
int flag;
int main()
 {
  void display();
  void dfs(int);
  int i,j,vertex;
  FILE * fp;
  head=NULL;
  fp=fopen("dfs.txt","r");
  fscanf(fp,"%d",&v);
  flag=0;
//READ WEIGHT MATRIX FROM FILE
    for(i=1;i<=v;i++)
	for(j=1;j<=v;j++)
	   {
	    fscanf(fp,"%d",&w[i][j]);
	   }
     for(i=1;i<=v;i++)
	for(j=1;j<=v;j++)
		if(w[i][j]!=0)
			w[j][i]=0;
         
 	
   for(i=0;i<20;i++)
   	{
	color[i]=0;
	finish[i]=0;
  	arrival[i]=0;
	}
  printf("\nEnter Vertex for traversal:");
  scanf("%d",&vertex);
  dfs(vertex);
  for(i=1;i<=v;i++)
       {
 	printf("\n Arrival[%d]:%d",i,arrival[i]);
        printf("\n Finish[%d]:%d",i,finish[i]);
       }     
       
printf("\n");
return 0;
  }  	
	
void dfs(int ver) 
 {
  t++;
  printf("\t%d",ver);
  arrival[ver]=t;
  int i,j;
  color[ver]=1;
  for(i=1;i<=v;i++)
	
	{
	  if((w[ver][i]!=0)&&(color[i]==2))
		printf("\n Edge:%d----%d is forward edge",ver,i); 
	  if((w[ver][i]!=0)&&(color[i]==1))
		printf("\n Edge:%d----%d is back edge",ver,i);
	  if((w[ver][i]!=0)&&(color[i]==0))
		{ printf("\n Edge:%d----%d is tree edge",ver,i);
		  dfs(i);
	 	}
 	  
	  }
  t++;
  color[ver]=2;
  finish[ver]=t;
 }
