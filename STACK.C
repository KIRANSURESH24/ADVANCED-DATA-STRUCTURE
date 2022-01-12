#include<stdio.h>
#include<conio.h>
#define MAX 20
int stack[MAX],top=-1;
void push(int item);
int pop();
int peek();
void display();
int isFull();
int isEmpty();
 void main()
 {
  int choice,item;
  while(1)
  {
   printf("\n 1.Push\n");
   printf("\n2.Pop\n");
   printf("\n3.Display the top element\n");
   printf("\n4.Display the stack element\n");
   printf("\n5.Quit");
   printf("\nEnter your choice:\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:printf("\n Enter the item to be pushed:");
	   scanf("%d",&item);
	   push(item);
	   break;
    case 2:item=pop();
	   printf("\n Popped item is:%d \n",item);
	   break;
    case 3:printf("\n Top element is :%d\n",peek());
	   break;
    case 4:display();
	   break;
    case 5:exit(1);
    default:printf("Wrong choice\n");
   }
  }
 getch();
}
void push(int item)
{
 if(isFull())
 {
  return;
 }
 top=top+1;
 stack[top]=item;
}
int pop()
{
 int item;
 if(isEmpty())
 {
  printf("\n Error:Trying to pop from empty\n");
  exit(1);
 }
 item=stack[top];
 top=top-1;
 return item;
}
int peek()
{
 if(isEmpty())
 {
  printf("\n Stack underflow\n");
  exit(1);
 }
 return stack[top];
}
int isEmpty()
{
 if(top==-1)
  return 1;
 else
  return 0;
}
int isFull()
{
 if(top==MAX-1)
  return 1;
 else
  return 0;
}
void display()
{
 int i;
 if(isEmpty())
 {
  printf("\n Stack is empty\n");
  return;
 }
 printf("\n stack elemnts:\n\n");
 for(i=top;i>=0;i--)
  printf("%d\n",stack[i]);
 printf("\n");
}