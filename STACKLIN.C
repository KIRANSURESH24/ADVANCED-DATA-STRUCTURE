#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
int data;
struct node*link;
};
typedef struct node node;
node *getnode();
void main()
{
node *top,*temp,*current;
int ch,item,i,n;
clrscr();
top=NULL;
do
{
printf("\n1.push\n");
printf("2.pop\n");
printf("3.display\n");
printf("4.exit\n");
printf("\nenter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter the element to be inserted:");
scanf("%d",&item);
temp=getnode();
if(temp==NULL)
{
printf("enable to create");
}
else
{
temp->data=item;
temp->link=top;
top=temp;
}
break;
case 2:
if(top==NULL)
printf("the list is empty\n");
else
{
printf("deleted node %d",top->data);
top=top->link;
free(current);
}
break;
case 3:
if(top==NULL)
printf("stack underflow\n");
else
{
current=top;
while(current!=NULL)
{
printf("%d\t",current->data);
current=current->link;
}
}
break;
case 4:
exit(0);
default:printf("\n invalid input");
}
}while(ch!=4);
}
node *getnode()
{
node *p;
p=(node*)malloc(sizeof(node));
return(p);
}