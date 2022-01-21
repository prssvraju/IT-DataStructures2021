/* Deletion operations in DOUBLE Linked List */
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
void del();
void traversal();
void deletebeg();
void deleteend();
void deletebefore();
void deleteafter();
nodeptr first,last;
main()
{
	int choice;
	create();
	traversal();
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.delete a node\n2.traversal\n");
		printf("3.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	del();
				traversal();
				break;
			case 2: traversal();
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
void del( )
{

	int c;
	if(first==NULL)
	{
		printf("\nlist is empty");

	}
	else if(first==last)
		first=last=NULL;

	else
	{
		printf("\nDelete\n1.at begining\n2.at end\n3.delete before\n4.delete after");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	deletebeg();				
				break;
			case 2:	deleteend();
				break;
			case 3:	deletebefore();
				break;
			case 4: deleteafter();
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
void deletebeg()
{
	nodeptr temp;
	temp=first;
	first=first->next;
	temp->next=NULL;
	first->prev=NULL;
}
void deleteend()
{
	nodeptr temp;
	temp=last;
	last=last->prev;
	last->next=NULL;
	temp->prev=NULL;
}
void deletebefore()
{
	nodeptr temp1,temp2,temp3;
	int k;
	printf("\nenter the element delete before:");
	scanf("%d",&k);
	if(first->info==k)
		printf("\nDeletion is not possible");
	else if(first->next->info==k)
	{
		temp1=first;
		first=first->next;
		temp1->next=NULL;
		first->prev=NULL;
	}
	else
	{
		temp1=first;
		while(temp1->next->info!=k)
			temp1=temp1->next;
		temp2=temp1->prev;
		temp3=temp1->next;
		temp2->next=temp3;
		temp3->prev=temp2;
		temp1->next=NULL;
		temp1->prev=NULL;
	}
}
void deleteafter()
{
	nodeptr temp1,temp2,temp3;
	int k;
	printf("\nEnter the element delete after:");
	scanf("%d",&k);
	temp1=first;
	while(temp1->info!=k)
		temp1=temp1->next;
	if(temp1->next==NULL)
		printf("\ndeletion is not possible");
	else if(temp1->next->next==NULL)
	{
		temp2=temp1->next;
		temp1->next=NULL;
		temp2->prev=NULL;
		last=temp1;
	}
	else
	{
		temp2=temp1->next;
		temp3=temp2->next;
		temp1->next=temp3;
		temp3->prev=temp1;
		temp2->next=NULL;
		temp2->prev=NULL;
	}
}
void create()
{

       nodeptr head,firstnode,newnode,temp;
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
	temp=head->next;
	head->next=NULL;
	temp->prev=NULL;
	first=temp;
	last=firstnode;
}