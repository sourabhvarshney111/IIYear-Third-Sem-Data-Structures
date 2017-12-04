#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *l,*r; 
}*root,*head;

struct node *getnode(int a)
{
	struct node *t=(struct node *)malloc(sizeof(struct node));
	t->data=a;
	t->l=NULL;
	t->r=NULL;
	return t;
}

int compare(struct node *root,struct node *head)
{
	if(root==NULL&&head==NULL)
	{
		return 1;
	}
	else if(root!=NULL&&head!=NULL)
	{
		return(root->data==head->data&&compare(root->l,head->l)&&compare(root->r,head->r));
	}
	else
	{
		return 0;
	}
}

int main()
{
	int value=0;
	// create a tree
	struct node *temp;
	
	root=getnode(50);
	temp=getnode(20);
	root->l=temp;
	temp=getnode(30);
	root->r=temp;
	temp=getnode(70);
	root->l->l=temp;
	temp=getnode(10);
	root->l->l->l=temp;
	temp=getnode(40);
	root->l->l->r=temp;
	temp=getnode(80);
	root->l->r=temp;
	temp=getnode(60);
	root->l->r->r=temp;
	
	// create a mirror tree
	head=getnode(50);
	temp=getnode(30);
	head->l=temp;
	temp=getnode(20);
	head->r=temp;
	temp=getnode(70);
	head->r->r=temp;
	temp=getnode(10);
	head->r->r->r=temp;
	temp=getnode(40);
	head->r->r->l=temp;
	temp=getnode(80);
	head->r->l=temp;
	temp=getnode(60);
	head->r->l->l=temp;
	
	value=compare(root,head);
	
	if(value==0)
	{
		printf("Not same..");
	}
	else
	{
		printf("Same...\n");
	}
}
