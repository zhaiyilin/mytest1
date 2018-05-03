#include<stdio.h>
#include<malloc.h>
#define maxsize 10
typedef struct
{
    int *base;
    int front;
    int rear;
}Queue;
void initqueue(Queue *q)  //创建循环队列
{
    q->base=(int *)malloc(maxsize * sizeof(int));
    if(!q->base)
    {
        printf("error");
        exit(0);
    }
    q->front=q->rear=0;
}
int enqueue(Queue*q,int e)  //插入一个元素
{
    if((q->rear+1)%maxsize==q->front)
    {
        printf("队列已满");
       exit(0);
    }
    q->base[q->rear]=e;
    q->rear=(q->rear+1)%maxsize;
    return 1;
}
int dequeue(Queue*q)  //删除队列的第一个元素,并返回a
{
    int a;
    if(q->rear==q->front)
    {
        printf("队列已满或为空");
        exit(0);
    }
    a=q->base[q->front];
    q->front=(q->front+1)%maxsize;
    return a;
}
void libian(Queue *q)//遍历函数
{
    int m;//队列长度
    int i;
    m=(q->rear-q->front+maxsize)%maxsize;
    for(i=0;i<m;i++)
    {
        printf("%d",q->base[q->front++]);
    }
     printf("\n");
}
main()
{
    Queue *q;
    int i,d,e,a;
    initqueue(q);//创建队列
    printf("输入队列元素个数");
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        printf("输入第%d个元素",i+1);
        scanf("%d",&e);
        enqueue(q,e);//插入每一个元素
    }
        a=dequeue(q);
    printf("队列中除去的数%d\n",a);
    printf("写出除去首元素的队列\n");
    libian(q);
}
