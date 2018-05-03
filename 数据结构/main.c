#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef char stackdata;
typedef struct{
stackdata *base;
stackdata *top;
int stacksize;
}SqStack;
void initstack(SqStack *s)
{
    s->base=(void *)malloc(100*sizeof(stackdata));
    s->top=s->base;
    s->stacksize=100;
}
void push(SqStack *s,int e,int i)
{
    *s->top++=e;
}
stackdata pop(SqStack *s)
{
    --s->top;
    return *s->top;
}
void print(SqStack *s)
{
    while(s->base<s->top)
        printf("%d",*--s->top);
}
main()
{
    static int i=1;
    int n;
    SqStack *s=(SqStack*)malloc(sizeof(SqStack));
    initstack(s);
    for(i=1;i<=5;i++)
    {
        printf("输入");
    scanf("%d",&n);
    push(s,n,i);
    }
    print(s);
    pop(s);
    print(s);

}
