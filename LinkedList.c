#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}linked;

linked *start= NULL;

void insert(int n)
{
    linked *temp=malloc(sizeof(linked));
    printf("enter the element to be entered\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if (n==1)
        {
            temp->link=start;
            start =temp;
        }

    else {
    linked *p=start;
    while((n-2)>0)
    {
        p=p->link;
        n--;
    }
    temp->link=p->link;
    p->link=temp;
}
}

void pop(int n)
{
    linked *p1=start;
    if (n==1)
    {
        start=start->link;
        free(p1);
    }
    else{
    while((n-2)>0)
        {
            p1=p1->link;
            n--;
        }
    linked *temp1=p1->link;
    p1->link=p1->link->link;
    free(temp1);
}
}
void display()
{
    linked *p2=start;
    while (p2!=NULL)
    {
        printf("%d->",p2->data);
        p2=p2->link;
    }
    printf("null\n");
}

int main()
{
    printf("enter \n1.for stack implentation thru linked list\n2.for queue implementation thru linked list \n3.for Playing with Linked list\n");
    int ch,ch1,ch2,ch3,n1,n2,rear=1,c=1;
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
           //int ch1;
           while (1)
           {
                printf("enter your choice for stack operations\n 1.for insertion \n2.for deletion \n3.for displaying \n4.for exit\n");
                scanf("%d",&ch1);
                switch(ch1)
                {
                       case 1:
                              insert(1);
                              break;
                       case 2:
                              if (start==NULL)
                                    printf("Stack underflow\n");
                              else
                                    pop(1);
                              break;
                       case 3:
                              display();
                              break;
                       case 4:
                              exit(0);
                              break;
                       default:
                               printf("Invalid input\n");
                               break;
                }
           }
           break;
    case 2:
            //int ch2,rear=0;
            while (1)
            {
                   printf("enter your choice for queue operations\n1.for insertion \n2.for deletion \n3.for displaying \n4.for exit\n");
                   scanf("%d",&ch2);
                   switch(ch2)
                   {
                          case 1:
                                 insert(rear);
                                 rear++;
                                 break;
                          case 2:
                                 if (start==NULL)
                                    printf("Queue Empty\n");
                                 else
                                    pop(1);
                                 break;
                          case 3:
                                 display();
                                 break;
                          case 4:
                                 exit(0);
                                 break;
                          default:
                                  printf("Invalid input\n");
                                  break;
                    }

            }
            break;
    case 3:
           //int ch3,n1,n2,c=1;
           while (1)
           {
                   printf("enter your choice to play with linked list\n1.for insertion \n2.for deletion \n3.for displaying \n4.for exit\n");
                   scanf("%d",&ch3);
                   switch(ch3)
                   {
                       case 1:
                              printf("enter the position where node is to be inserted\n");
                              scanf("%d",&n1);
                              if (c>=n1&&n1>0)
                                  {insert(n1);c++;}
                              else
                                  printf("The position entered does not exist for the List!!!\n");
                              break;
                       case 2:
                              if (start==NULL)
                                printf("Empty list");
                              else
                                {
                                    printf("enter the position from where node is to be deleted\n");
                                    scanf("%d",&n2);
                                    pop(n2);
                                }
                              break;
                       case 3:
                              display();
                              break;
                       case 4:
                              exit(0);
                              break;
                       default:
                               printf("Invalid input\n");
                               break;
                   }
             }
             break;
     default:
             printf("Invalid input\n");
             break;
    }
    return 0;
}
