#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
typedef struct node * nodeptr;

nodeptr getnode();
nodeptr insert(nodeptr);
nodeptr insertAtBeg(nodeptr,nodeptr);
nodeptr insertAtEnd(nodeptr,nodeptr);
nodeptr insertBeforElement(nodeptr,nodeptr);
nodeptr insertAfterElement(nodeptr,nodeptr);

nodeptr del(nodeptr);
nodeptr deleteAtBeg(nodeptr);
nodeptr deleteAtEnd(nodeptr);
nodeptr deleteBeforElement(nodeptr);
nodeptr deleteAfterElement(nodeptr);


void traversal(nodeptr);

main()
{
    nodeptr head;
	int choice;
	head=NULL;
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("\n1.adding a node\n2.delete a node");
		printf("\n3.traversal\n");
		printf("4.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:	head=insert(head);
				traversal(head);
				break;
			case 2:	head=del(head);
				traversal(head);
				break;
			case 3: traversal(head);
				break;
			case 4:	exit(0);
		}
	}
}

nodeptr getnode()
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(struct node));
	p->data=0;
	p->next=p;
	return p;
}

nodeptr insertAtBeg(nodeptr firtnode,nodeptr newnode)
{
    nodeptr temp;
    temp = firtnode;

    while(temp->next!=firtnode)
    {
        temp=temp->next;
    }

    newnode->next = firtnode;
    temp->next = newnode;
    firtnode = newnode;				
	return firtnode;
}


nodeptr insertAtEnd(nodeptr firtnode,nodeptr newnode)
{
    nodeptr temp;
    temp = firtnode;

    while(temp->next!=firtnode)
    {
        temp=temp->next;
    }
    newnode->next = firtnode;
    temp->next = newnode;

	return firtnode;
}

nodeptr insertBeforeElement(nodeptr firtnode,nodeptr newnode)
{
    nodeptr temp;
    temp = firtnode;
    int k;

    printf("\nEnter the element insert before:");
    scanf("%d",&k);
    if(firtnode->data==k)
    {
        while(temp->next!=firtnode)
        {
            temp = temp->next;
        }
        newnode->next=firtnode;
        temp->next=newnode;
        firtnode=newnode;
    }
    else
    {
        while(temp->next->data!=k)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;   
    }
    return firtnode;
}

nodeptr insertAfterElement(nodeptr firstnode,nodeptr newnode)
{
    nodeptr temp;
    temp = firstnode;
    int k;

    printf("\nEnter the element insetr after:");
    scanf("%d",&k);

    while(temp->data!=k)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
	return firstnode;

}



nodeptr insert(nodeptr head)
{
	nodeptr firstnode,newnode;
	int k,ch,i;
	firstnode=head;
	newnode=getnode();
	printf("\nenter inserted element:");
	scanf("%d",&newnode->data);
	if(firstnode==NULL)
	{
		newnode->next=newnode;
		firstnode=newnode;
		return firstnode;
	}
	else
	{
		printf("\ninsert\n1.at beg\n2.at end\n3.insert before\n4.insert after\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:return(insertAtBeg(firstnode,newnode));
                    break;  
			case 2:return(insertAtEnd(firstnode,newnode));	
                    break;
			case 3:return(insertBeforeElement(firstnode,newnode));	
                    break;
			case 4:return(insertAfterElement(firstnode,newnode));	 
                    break;
		}
	}
}

nodeptr deleteAtBeg(nodeptr firstnode)
{

    nodeptr temp1,temp2;
    temp1 = firstnode;
    if(firstnode->next==firstnode)
    {
        firstnode=NULL;
        return firstnode;
    }
    else
    {
        while(temp1->next!=firstnode)
        {
            temp1=temp1->next;
        }
        
        temp2=firstnode->next;
        temp1->next=temp2;
        firstnode->next=NULL;
        return temp2;
    }
}

nodeptr deleteAtEnd(nodeptr firstnode)
{
    nodeptr temp;
    temp = firstnode;

    if(temp->next==firstnode)
    {
        firstnode=NULL;
        return firstnode;
    }
    while(temp->next->next!=firstnode)
    {
        temp=temp->next;
    }      
    temp->next=firstnode;
    return firstnode;
}

nodeptr deleteBeforElement(nodeptr firstnode)
{
    int k;
    nodeptr temp1,temp2;
    temp1 = firstnode; 

    printf("\nenter the element delete before:");
    scanf("%d", &k);

    
    if (temp1->data == k)
    {
         printf("\nDeletion is not possible");
    } 
    else if (temp1->next->data == k)
    {
        while (temp1->next != firstnode)
        {
            temp1 = temp1->next;
        }
            
        temp1->next = firstnode->next;
        temp2 = firstnode->next;
        firstnode->next = NULL;
        firstnode = temp2;
    }
    else
    {
        while (temp1->next->data != k)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        temp1->next = NULL;
    }
    return firstnode;
}

nodeptr deleteAfterElement(nodeptr firstnode)
{
    int k;
    nodeptr temp1,temp2;
    temp1 = firstnode;
 
    printf("\nEnter the element delete after:");
    scanf("%d",&k);
    while(temp1->data!=k)
    {
        temp1=temp1->next;
    }
    if(temp1->next==firstnode)
        printf("\ndeletion is not possible");
    else
    {
        temp2=temp1->next;
        temp1->next=temp2->next;
        temp2->next=NULL;
    }
    return firstnode;
}


nodeptr del( nodeptr p)
{
	int c,i,k;
	nodeptr firstnode;
	firstnode=p;

	if(firstnode==NULL)
	{
		printf("\nlist is empty");
		return firstnode;
	}
	else
	{
		printf("\nDelete\n1.at begining\n2.at end\n3.delete before\n4.delete after");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:return(deleteAtBeg(firstnode));
				   break;
			case 2:return(deleteAtEnd(firstnode));
				   break;
			case 3:return(deleteBeforElement(firstnode));
				   break;
			case 4:return(deleteAfterElement(firstnode));
				   break;
		  }
	}
}

void traversal(nodeptr head)
{
	nodeptr temp;
	temp=head;
	printf("\nelements are:\n");
	while(temp->next!=head)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}
