/* Reverse Linked List */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;
nodeptr getnode();
nodeptr reverse(nodeptr);
void traversal(nodeptr);
nodeptr create();
main()
{
	nodeptr first,last;
	clrscr();
	first=create();
	traversal(first);
	printf("\nReversing list is\n");
	last=reverse(first);
	traversal(last);
	getch();
}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->info=0;
	p->next=0;
	return p;
}
nodeptr reverse(nodeptr p)
{
	nodeptr p1,p2,p3;
	p1=p;
	p2=getnode();
	p2->info=p1->info;
	while(p1->next!=NULL)
	{
		p1=p1->next;
		p3=getnode();
		p3->info=p1->info;
		p3->next=p2;
		p2=p3;
	}
	return p2;
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