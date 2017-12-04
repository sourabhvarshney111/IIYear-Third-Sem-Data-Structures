#include<stdio.h>
#include<string.h>
#define MAX 20
struct book{
char book_name[80];
char id[80];
float price;
};
struct st{
	struct book stack[MAX];
	int top;
	}st1;
void push(struct book b1)
{
	if(st1.top==MAX-1)
	{
		printf("Stack Overflow\n");
		return;
	}
	else
	{
		printf("Entry pushed\n");
		st1.top++;
		strcpy(st1.stack[st1.top].book_name,b1.book_name);
		strcpy(st1.stack[st1.top].id,b1.id);
		st1.stack[st1.top].price=b1.price;
	}
}
struct book pop()
{
	struct book b1;
	if(st1.top==-1)
	{
		printf("Stack Underflow\n");
		exit(0);
	}
	else
	{
		strcpy(b1.book_name,st1.stack[st1.top].book_name);
		strcpy(b1.id,st1.stack[st1.top].id);
		b1.price=st1.stack[st1.top].price;
		st1.top--;
	}
	return b1;
}
void peep()
{
	struct book b1;
	if(st1.top==-1)
	{
		printf("Stack Underflow\n");
		exit(0);
	}
	else
	{
		printf("\nThe Top Element is:");
		printf("\nBook Name: %s",st1.stack[st1.top].book_name);
		printf("\nBook Id: %s",st1.stack[st1.top].id);
		printf("\nPrice %f\n",st1.stack[st1.top].price);
	}
}
void display()
{
	int i;
	if(st1.top==-1)
		printf("Stack Empty!!!\n");
	else
	{
		printf("The Stack is:\n");
		for(i=st1.top;i>=0;i--)
		{
			printf("\nBook Name: %s",st1.stack[i].book_name);
			printf("\nBook Id: %s",st1.stack[i].id);
			printf("\nPrice %f\n",st1.stack[i].price);
		}
	}
}
void main()
{
	struct book b;
	st1.top=-1;
	char ch='y';
	int cho;
	while(ch=='y'||ch=='Y')
	{
		printf("\t\t\t\tStack Menu\n");
		printf("\t\t\t\t1.Push operation\n");
		printf("\t\t\t\t2.Pop Operation\n");
		printf("\t\t\t\t3.Peep Operation\n");
		printf("\t\t\t\t4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1:printf("Enter Book name:");
			       gets( b.book_name);
			       gets(b.book_name);
			       printf("Enter Book id:");
			       gets(b.id);
			       printf("Enter Book price:");
			       scanf("%f",&b.price);
			       push(b);
			       display();
			       break;
			case 2:b=pop();
			       printf("Top Entry popped\n");
			       printf("The deleted entry is:\n");
			       printf("\nBook Name: %s",b.book_name);
			       printf("\nBook Id: %s",b.id);
			       printf("\nPrice %f\n",b.price);
			       display();
			       break;
			case 3:peep();
			       break;
			case 4:exit(0);
			       break;
			default:printf("Wrong choice\n");
				break;
		}
		printf("\nDo you want to continue(y for yes,n for no)?\n");
		scanf(" %c",&ch);
	}
}
