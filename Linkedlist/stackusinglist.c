#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;

struct  node
{
    int data;
    struct node * next;
};
struct  stack
{
    nodeptr top;
};

nodeptr getnode();
void push(struct stack *,int);
void display(struct stack *);
int pop(struct stack *);
int peek(struct stack *);
int empty(struct stack *);

nodeptr getnod()
{
    nodeptr newnode = (nodeptr)malloc(sizeof(struct node));
    newnode->data = 0;
    newnode->next = NULL;
    return newnode;
}


main()
{
    struct stack s;
    s.top = NULL;
    int x;

    int ch, element;
    while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("1.push\n2.pop\n3.empty\n4.peek\n5.display\n");
		printf("6.exit\n*******************\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("\nenter the element:");
			scanf("%d",&element);
			push(&s,element);
			display(&s);
			break;
        case 2:	x=pop(&s);
			if(x==-1)
				printf("\nstack is empty");
			else
				printf("deleted item is:%d\n",x);
			display(&s);
			break;
		case 3:	x=empty(&s);
			if(x==1)
				printf("\nstack is empty");
			else
				printf("\nstack is nonempty");
			break;
		case 4:	x=peek(&s);
			if(x==-1)
				printf("\nStack is empty");
			else
				printf("\ntop element of the stack:%d",x);
			break;
		case 5:	display(&s);
			break;
		
		case 6:	exit(0);
		}
	}


}

void push(struct stack *st,int el)
{
    nodeptr newnode;
    newnode=getnod();
    newnode->data =el;

    if(st->top==NULL)
    {
        st->top = newnode;
    }
    else
    {
        newnode->next = st->top;
        st->top = newnode;
    }

}

int pop(struct stack *st)
{
       int t;
       if(empty(st))
		return -1;
	else
	{
	     t=st->top->data;
	     st->top=st->top->next;
	     return t;
	}
}


void display(struct stack *st)
{
    nodeptr temp = st->top;
    if(st->top == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d <--",temp->data);
            temp= temp->next;
        }

    }

}

int empty(struct stack *st)
{
	if(st->top==NULL)
		return 1;
	else
		return 0;
}
int peek(struct stack *st)
{
	if(st->top==NULL)
		return -1;
	else
		return st->top->data;
}