#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int t;
typedef struct ver
 {
  int vert;
  int dfsnum;
  int low;
  int noc;
  int lev;
  }vertex;
int w[20][20],nov;
vertex * vertices;
int main()
 { 
   void Arti(vertex );
   int i,j;
   FILE * fp;
   t=0;
   fp=fopen("arti.txt","r");
   fscanf(fp,"%d",&nov);
   vertices=(vertex *)malloc(sizeof(vertex)*nov);
   //READ WEIGHT MATRIX FROM FILE
      for(i=1;i<=nov;i++)
	for(j=1;j<=nov;j++)
	 fscanf(fp,"%d",&w[i][j]);
      for(i=1;i<=nov;i++)
	{
	 vertices[i].vert=i;
	 vertices[i].dfsnum=-1;
	 vertices[i].low=0;
	 vertices[i].noc=0;
	 vertices[i].lev=0;
	 }
     Arti(vertices[1]);	
    	
   return 0;
 }
 void Arti(vertex v)
 {int i,j;
  
  v.dfsnum=++t;
  v.low=v.dfsnum;
    i=v.vert;
       for(j=1;j<=nov;j++)
	  if(w[i][j]!=0)
		{
		 if(vertices[j].dfsnum==-1)
			{
			 vertices[j].lev=v.lev++;
			 v.noc++;
			 Arti(vertices[j]);
			  if(v.low>vertices[j].low)
			      v.low=vertices[j].low;
			  if(v.dfsnum==1)
			     {
				 if(v.noc>=2)
					printf("\t%d is articulation point",v.vert);	     
			     }
			  else
			     {
			       if(vertices[j].low>=v.dfsnum)
				 printf("\n\t%d is articulation point",vertices[j].vert);
			     }
			  }
		   else 
			{
			 if(vertices[j].lev<v.lev-1)
			    if(v.low>vertices[j].dfsnum)
				v.low=vertices[j].dfsnum;
			}
		}
    }

