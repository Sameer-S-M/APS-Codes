#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct stack
{
    int data[MAX];
    int top;
}stack;
void push(stack *s)
{
    s->top++;
    printf("Enter the element to be inserted\n");
    scanf("%d",&s->data[s->top]);
}
int pop(stack *s)
{
    int temp;
    temp=s->data[s->top];
    s->top--;
    return temp;
}
int peek(stack *s)
{
    return(s->data[s->top]);
}
int main()
{
    stack s;
    int ch,n;
    s.top=-1;
    printf("Enter number of blocks \n");
    scanf("%d",&n);
    for(;;)
    {
        printf("\nEnter operation of stack            1-->Push     2-->Pop      3->Peek\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(s.top<n-1)
                {
                    push(&s);
                }
                else
                {
                    printf("Stack overflow\n");
                }
                    break;
            case 2:
                if(s.top==-1)
                {
                    printf("Underflow\n");
                }
                else
                {
                    printf("Poped element is %d\n",pop(&s));
                }
                    break;
            case 3:
                if(s.top==-1)
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("Peek element is %d\n",peek(&s));
                }
                    break;
        }
    }
}