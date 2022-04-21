#include<stdio.h>
#include<stdlib.h>

typedef struct loopdetect
{
int data;
struct loopdetect *next;
}loop;

loop *createnode(loop **new_arg)
{
   *new_arg =(loop*)malloc(sizeof(loop));
   printf("Enter data\n");
   scanf("%d",&(*new_arg)->data);
   (*new_arg)->next=0;
   return *new_arg;
}

void insertnode(loop **head_ins,loop **latest_loop)
{
    loop *new = NULL;
    new = createnode(&new);
    if(*head_ins==NULL)
      *head_ins=new;
    else
      (*latest_loop)->next=new;
    *latest_loop = new;
}

void traverse(loop **head_arg)
{
 loop *temp = *head_arg;   
 while(temp)
 {
 printf("data: %d\n",temp->data);
 temp=temp->next;
 }
}

/****** Count nodes inbetween the loops Logic code ******/

int countnode (loop **count_ptr)
{
    int counter = 1;
    loop *temp = *count_ptr;
    while (temp->next != temp)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

/***** LOOP DETECTION LOGIC CODE**********/

void detectloop(loop **head_arg) 
{
 loop *p=*head_arg,*q=*head_arg;
 
 while(p!=q)
 {
  
  if (p != q)
  {
    p=p->next->next; //Fast pointer
    q=q->next; //Slow pointer
  }
  
  if(p==q)
  {
   printf("loop detected\n");
   printf("No of nodes in loop :%d \n",countnode(&q));
   break;
  }
 }
}

int main()
{
  loop *head=NULL,*latest=NULL;
  int i;
  for(i=0;i<5;i++)
  {
    insertnode(&head,&latest);
  }

  detectloop(&head);
  printf("print all data\n");
  traverse(&head);
  return 0;
}