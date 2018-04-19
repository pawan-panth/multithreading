#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int avg;
int min;
int max;
struct cal{
     int a;
     int b[10];
};
void *average_value(void *param1);
void *minimum_value(void *param2);
void *maximum_value(void *param3);

int main(int argc,char *argv[])
{
	struct cal c;
	c.a=argc-1;
	int data[argc-1];
	for(int i=0;i<argc-1;i++)
	{
		c.b[i]=atoi(argv[i+1]);
	}
	
	pthread_t t1,t2,t3;
	pthread_attr_t attr1,attr2,attr3;
	//pthread_attr_init(&attr1);
	//pthread_attr_init(&attr2);
	//pthread_attr_init(&attr3);
	pthread_create(&t1,NULL,&average_value,(void *)&c);
	pthread_join(t1,NULL);
	pthread_create(&t2,NULL,minimum_value,(void *)&c);
	pthread_join(t2,NULL);
	pthread_create(&t3,NULL,maximum_value,(void *)&c);
	pthread_join(t3,NULL);
	printf("average value:%d\n",avg);
    printf("minimum value:%d\n",min);
    printf("maximum  value:%d\n",max);
	return 0;
}
void *average_value(void *param1)
{
	int sum=0;
    struct cal *c2=param1;
	for(int i=0;i<c2->a;i++)
		sum=sum+c2->b[i];
	avg=sum/c2->a;
	pthread_exit(NULL);
}
void *minimum_value(void *param2)
{
    struct cal *c3=param2;
	min=c3->b[0];
	for(int i=1;i<c3->a;i++)
	{
		if(min>c3->b[i])
		{
			min=c3->b[i];
		}
	}
	
	pthread_exit(NULL);

}
void *maximum_value(void *param3)
{
	struct cal *c4=param3;
	//printf("%d",c4->a);
	max=c4->b[0];
	for(int i=1;i<c4->a;i++)
	{
		if(max<c4->b[i])
		{
			max=c4->b[i];
		}
	}
	
	pthread_exit(NULL);


} 
