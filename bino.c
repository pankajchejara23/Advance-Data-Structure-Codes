#include<stdio.h>
#include<stdlib.h>
typedef struct nod
{
int key;
struct nod * parent;
struct nod * child;
struct nod * sibling;
int degree;
 }node;
node * head;
int main()
 {
  int val,ch;
  node * Bin_create(int );
  node * Bin_merge(node *,node *);
  void Bin_link(node *,node *);
  node * Bin_union(node *,node *);
  int Bin_min();
  node *temp,*t;
  head=NULL;
  while(1)
	{
	 printf("\n\t1.INSERT VALUE");
	 printf("\n\t2.FIND MINIMUM");
	 printf("\n\t3.PRINT ROOT LIST");
	 printf("\n\t4.EXIT");
	 printf("\n Enter choice.......");
	 scanf("%d",&ch);
	 switch(ch)
		{
		case 1:scanf("%d",&val);
			head=Bin_create(val);
			break;
		case 2:printf("\n Minimun Value is:%d",Bin_min());	
			break;
		case 3:temp=head;
		       while(temp!=NULL){
			 printf("\t%d",temp->key);
			 temp=temp->sibling;
			}
			 
			break;
		case 4:exit(1);
		}
         }
  return 0;
}
node * Bin_merge(node * h1,node * h2)
  {
	node * h,*cur1,*cur2,*t;
	if(h1->key<h2->key)
	 {
	   h=h1;
	   cur1=h1->sibling;
	   cur2=h2;
	}
	else
	 {
	   h=h2;
	   cur1=h2->sibling;
	   cur2=h1;
	 }
	 t=h;
	while((cur1!=NULL)&&(cur2!=NULL))
	  {
		if(cur1->key<cur2->key)
		 {
			h->sibling=cur1;
			h=h->sibling;
			cur1=cur1->sibling;
		}
		else
		{
			h->sibling=cur2;
			h=h->sibling;
			cur2=cur2->sibling;
		}
	    }
	if(cur1==NULL)
		cur1=cur2;
  	while(cur1!=NULL)
	{
	 h->sibling=cur1;
	 cur1=cur1->sibling;
	 h=h->sibling;
	}
	return t;
   }


void Bin_link(node * par,node * chil)
	{	
	chil->parent=par;
	par->degree++;
	chil->sibling=par->child;
	par->child=chil;
	}
node * Bin_union(node * h1,node * h2)
	{
	node *h3,*pre,*cur,*nex;
	h3=Bin_merge(h1,h2);
	pre=NULL;
	cur=h3;
	nex=cur->sibling;
	while(nex!=NULL)
	{
	  if(cur->degree!=nex->degree)
		{
		pre=cur;
		cur=nex;
		nex=nex->sibling;
		}
	 else
	      {
		if(cur->key<=nex->key)
		  {
		   cur->sibling=nex->sibling;
		   Bin_link(cur,nex);
		  }
		else
		    {
		   if(pre!=NULL)
			{
			pre->sibling=nex;
			Bin_link(nex,pre);
			}
		   else
			{
			 h3=nex;
			 Bin_link(nex,cur);
			}
		     }
		 }
	}
 return h3;
  }
 node * Bin_create(int k)
 {
  node * t;
  t=(node *)malloc(sizeof(node));
  t->key=k;
  t->parent=NULL;
  t->sibling=NULL;
  t->child=NULL;
  t->degree=0;
  if(head!=NULL)
	{
	 head=Bin_union(head,t);
	 return head;
	}
  else 
        return t;
 }
int  Bin_min()
	{
	node * t;
	t=head;
	int min;
	if(head==NULL)
	 return 0;
	else
	  min=t->key;
	t=t->sibling;
	while(t!=NULL)
	  {
		if(min>t->key)
			min=t->key;
		t=t->sibling;
	  }
	 return min;
         }

    
