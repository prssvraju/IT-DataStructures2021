/* Insertion operations in DOUBLE Linked List */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next, *prev;
};
typedef struct node *nodeptr;
nodeptr getnode();
void create();
void insert();
void traversal();
void insertbeg(nodeptr);
void insertend(nodeptr);
void insertbefore(nodeptr);
void insertafter(nodeptr);
nodeptr first,last;
main()
{
	int choice;
	create();
	traversal();
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.adding a node\n2.traversal\n");
		printf("3.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	insert();
				traversal();
				break;
			case 2:	traversal();
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
	p->next=NULL;
	p->prev=NULL;
	return p;
}
void insert()
{
	nodeptr newnode;
	int ch;
	newnode=getnode();
	printf("\nenter inserted element:");
	scanf("%d",&newnode->info);
	if(first==NULL)
	{
		first=newnode;
		last=newnode;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert before\n4.insert after\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	insertbeg(newnode);
				break;
			case 2:	insertend(newnode);
				break;
			case 3: insertbefore(newnode);
				break;
			case 4: insertafter(newnode);
				break;
		}
	}
}
void traversal()
{
	nodeptr p1;
	p1=first;
	printf("\nelements are:\n");
	while(p1!=NULL)
	{
		printf("%d-->",p1->info);
		p1=p1->next;
	}
	printf("\nelements in reverse order\n");
	p1=last;
	while(p1!=NULL)
	{
	      printf("<--%d",p1->info);
	      p1=p1->prev;
	}

}
void insertbeg(nodeptr newnode)
{
	newnode->next=first;
	first->prev=newnode;
	first=newnode;
}
void insertend(nodeptr newnode)
{
	
	last->next=newnode;
	newnode->prev=last;
	last=newnode;
}
void insertbefore(nodeptr newnode)
{
	nodeptr temp1,temp2;
	int k;
	printf("\nEnter the element insert before:");
	scanf("%d",&k);
	if(first->info==k)
	{
		newnode->next=first;
		first->prev=newnode;
		first=newnode;
	}
	else
	{
		temp1=first;
		while(temp1->next->info!=k)
        {
            temp1=temp1->next;
        }
		temp2=temp1->next;
		temp1->next=newnode;
		newnode->prev=temp1;
		newnode->next=temp2;
		temp2->prev=newnode;
	}
}
void insertafter(nodeptr newnode)
{
	nodeptr temp1,temp2;
	int k;
	printf("\nEnter the element insetr after:");
	scanf("%d",&k);
	temp1=first;
	while(temp1->info!=k)
    {
        temp1=temp1->next;
    }
	if(temp1->next==NULL)
	{
		temp1->next=newnode;
		newnode->prev=temp1;
		last=newnode;
	}
	else
	{
		temp2=temp1->next;
		temp1->next=newnode;
		newnode->prev=temp1;
		newnode->next=temp2;
		temp2->prev=newnode;
	}
}

void create()
{

       nodeptr head,firstnode,newnode,p3;
       firstnode=getnode();
       head=firstnode;
       newnode=getnode();
       printf("\nEnter the at end -999\n");
       printf("\nEnter the number:");
       scanf("%d",&newnode->info);
       while(newnode->info!=-999)
       {
		firstnode->next=newnode;
		newnode->prev=firstnode;
		firstnode=newnode;
		newnode=getnode();
		printf("\nEnter the number:");
		scanf("%d",&newnode->info);
       }
	p3=head->next;
	head->next=NULL;
	p3->prev=NULL;
	first=p3;
	last=firstnode;
}