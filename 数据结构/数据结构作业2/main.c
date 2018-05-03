#include<stdio.h>
#include<malloc.h>
#define maxsize 10
typedef struct
{
    int *base;
    int front;
    int rear;
}Queue;
void initqueue(Queue *q)  //����ѭ������
{
    q->base=(int *)malloc(maxsize * sizeof(int));
    if(!q->base)
    {
        printf("error");
        exit(0);
    }
    q->front=q->rear=0;
}
int enqueue(Queue*q,int e)  //����һ��Ԫ��
{
    if((q->rear+1)%maxsize==q->front)
    {
        printf("��������");
       exit(0);
    }
    q->base[q->rear]=e;
    q->rear=(q->rear+1)%maxsize;
    return 1;
}
int dequeue(Queue*q)  //ɾ�����еĵ�һ��Ԫ��,������a
{
    int a;
    if(q->rear==q->front)
    {
        printf("����������Ϊ��");
        exit(0);
    }
    a=q->base[q->front];
    q->front=(q->front+1)%maxsize;
    return a;
}
void libian(Queue *q)//��������
{
    int m;//���г���
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
    initqueue(q);//��������
    printf("�������Ԫ�ظ���");
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        printf("�����%d��Ԫ��",i+1);
        scanf("%d",&e);
        enqueue(q,e);//����ÿһ��Ԫ��
    }
        a=dequeue(q);
    printf("�����г�ȥ����%d\n",a);
    printf("д����ȥ��Ԫ�صĶ���\n");
    libian(q);
}
