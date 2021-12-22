/* Linked List operations */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;
nodeptr getnode();
void search(nodeptr);
void traversal(nodeptr);
nodeptr create();
main()
{
	nodeptr first,last;
	int choice;
	clrscr();
	first=create();
	traversal(first);
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.search an element");
		printf("\n2.traversal\n3.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	search(first);
				break;
			case 2:	traversal(first);
				break;
			case 3:	exit(0);
		}
	}
}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->info=0;
	p->next=0;
	return p;
}
void search(nodeptr p)
{
	int a,i;
	nodeptr p1;
	p1=p;
	printf("\nenter the searching element:");
	scanf("%d",&a);
	i=1;
	while(p1!=NULL)
	{
		if(p1->info==a)
		{
			printf("\nsearching elment is found at location:%d",i);
			return;
		}
		p1=p1->next;
		i++;
	}
	printf("\nsearching element is not found");
}
void traversal(nodeptr p)
{
	nodeptr p1;
	p1=p;
	printf("\nelements are:\n");
	while(p1!=NULL)
	{
		printf("%d-->",p1->info);
		p1=p1->next;
	}
}

nodeptr create()
{

       nodeptr p,p1,p2;
       p1=getnode();
       p=p1;
       p2=getnode();
       printf("\nEnter the at end -999\n");
       printf("\nEnter the number:");
       scanf("%d",&p2->info);
       while(p2->info!=-999)
       {
		p1->next=p2;
		p1=p2;
		p2=getnode();
		printf("\nEnter the number:");
		scanf("%d",&p2->info);
       }
	return p->next;
}