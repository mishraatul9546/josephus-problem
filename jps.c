#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
struct node *getnode()
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	return n;
}
void ins(int x)
{
	int count=1;
	struct node *n,*t;
	while(count<=x)
	{
		n=getnode();
		n->data=count;
		n->link=NULL;
		if(head==NULL) head=n;
		else
		{
			t=head;
			while(t->link!=NULL) t=t->link;
			t->link=n;
		}
		count=count+1;
	}
	t=head;
	while(t->link!=NULL) t=t->link;
	t->link=head;
}
void dis()
{
	struct node *t;
	t=head;
	while(t->link!=head) 
	{
		printf("%d\n",t->data);
		t=t->link;
	}
	printf("%d\n",t->data);
}
void jsps()
{
	struct node *t;
	t=head;
	while(t->link!=t->link->link)
	{
		t->link=t->link->link;
		t=t->link;
	}
	printf("%d\n",t->data);
}	
int main()
{
	int x;
	printf("enter the number:");
	scanf("%d",&x);
	ins(x);
	jsps();
	return 0;
}


