/* Create a singly linked list */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;
nodeptr getnode();
void traversal(nodeptr);
nodeptr create();
main()
{
	nodeptr first;
	first=create();
	traversal(first);
}
nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->info=0;
	p->next=NULL;
	return p;
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

       nodeptr head,firstnode,newnode;
       firstnode=getnode();
       head=firstnode;
       newnode=getnode();
       printf("\nEnter the at end -999\n");
       printf("\nEnter the number:");
       scanf("%d",&newnode->info);
       while(newnode->info!=-999)
       {
		firstnode->next=newnode;
		firstnode=newnode;
		newnode=getnode();
		printf("\nEnter the number:");
		scanf("%d",&newnode->info);
       }
	return head->next;
}