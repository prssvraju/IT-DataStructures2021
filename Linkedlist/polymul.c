/*
Result will have individual like terms

The polynomial 1 is..(4x^3)+(3x^2)+1
The polynomial 2 is..(5x^3)+(7x^1)+5
The Mul of the two polynomials is..(20x^6)+(15x^5)+(28x^4)+(5x^3)+(21x^3)+(20x^3)+(15x^2)+(7x^1)+5

*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef,expo;
    struct node* next;
};
typedef struct node * nodeptr;
nodeptr insertpoly(nodeptr,int,int);
void display(nodeptr);
void displayst(nodeptr);

nodeptr polyMul(nodeptr,nodeptr);
void main()
{
    int a,b,n,i;
    struct node* p1head,* p2head,* p3head;
    p1head=p2head=NULL;

    // Inputing the first polynomial..

    printf("Enter the no of terms of polynomial 1..");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d",&a,&b);
        p1head=insertpoly(p1head,a,b);
    }

    // Inputing the second polynomial..

    printf("\nEnter the no of terms of polynomial 2..");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient and exponent of the term..");
        scanf("%d%d",&a,&b);
        p2head=insertpoly(p2head,a,b);
    }

    //Performing Addition..

    p3head=polyMul(p1head,p2head);

    //Displaying the polynomial..

    printf("\nThe polynomial 1 is..");
    displayst(p1head);
    printf("\nThe polynomial 2 is..");
    displayst(p2head);
    printf("\nThe Mul of the two polynomials is..");
    displayst(p3head);
}

struct node* insertpoly(struct node* thead,int c,int e)
{
    nodeptr temp;
    nodeptr newnode=(nodeptr)malloc(sizeof(struct node));
    newnode->coef=c;
    newnode->expo=e;
    newnode->next = NULL;
    if(thead==NULL || e > thead->expo){            // for inserting the first node..
        newnode->next=thead;
        return newnode;
    }
    else
    {
        temp = thead;
        while(temp->next!=NULL && temp->next->expo > e)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return thead;
}

void display(struct node* thead)
{
    nodeptr temp=thead;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
        //while(temp!=NULL){
            // printf(" %dx^%d +",temp->coef,temp->expo);
            // temp=temp->next;
            printf("(%dx^%d)",temp->coef,temp->expo);
            temp=temp->next;
            if(temp!=NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
       //printf(" %dx^%d ",temp->coef,temp->expo);
       printf("%d",temp->coef);
    }
}
nodeptr polyMul(nodeptr head1,nodeptr head2)
{
    nodeptr ptr1=head1;
    nodeptr ptr2=head2;
    nodeptr head3 = NULL;
    if(head1 == NULL || head2 == NULL)
    {
        printf("Zero Polynomial\n");
    }
    while(ptr1!=NULL)
    {
        while (ptr2!=NULL)
        {
            head3 = insertpoly(head3,ptr1->coef*ptr2->coef,ptr1->expo+ptr2->expo);
            ptr2= ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 =head2;
    } 
    return head3;
}

void displayst(nodeptr head)
{
    nodeptr temp;
    temp = head;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp->next!= NULL)
        {
            printf("%dx^%d",temp->coef,temp->expo);
            temp=temp->next;
            if(temp->next!=NULL)
            {
                printf("+");
            }
        }
        if(temp->expo == 0)
        {
            printf("+%d",temp->coef);
        }
        else
        {
            printf("+%dx^%d",temp->coef,temp->expo);
        }
    }
}