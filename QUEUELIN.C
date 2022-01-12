#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct qnode
{
int data;
struct qnode*link;
};
typedef struct qnode qnode;
qnode *getnode();
void main()
{
qnode *front,*rear,*temp;
int item,ch;
clrscr();
front=NULL;
rear=NULL;
do
{
printf("\n1.Insert: \n");
printf("2.Delete: \n");
printf("3.Display: \n");
printf("4.Exit: \n");
printf("Select your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the element to be inserted: ");
scanf("%d",&item);
temp=getnode();
temp->data=item;
temp->link=NULL;
if(front==NULL){
front=temp;
rear=temp;
}
else{
rear->link=temp;
rear=temp;
}
break;
case 2:
if(front==NULL)
printf("Queue is empty");
else {
printf("deleted item %d",front->data);
front=front->link;
free(temp);
}
break;
case 3:
if(front==NULL)
printf("Queue is empty\n");
else
{
printf("Queue is ->");
temp=front;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->link;
}
}
break;
case 4:
exit(0);
default:printf("invalid input");
}
}while(ch!=5);
getch();
}
qnode*getnode(){
qnode*p;
p=(qnode*)malloc(sizeof(qnode));
return p;
}