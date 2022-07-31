#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int insert(int p,char q,char r,int s);
int delete(int p,int q);
int split(int p);
int PrintChain(int p);
int PrintAllChains();
int length(int p);

struct node
{
	char data_1,data_2,data_3,data_4;
	struct node *link_1;
	struct node *link_2;
	struct node *link_3;
	struct node *link_4;
};

struct node *a[100000] = {NULL};

int main()
{
	struct node *temp_1;
	struct node *temp_2;
	char C,G,T,A;
	int l;
	printf("enter the length of chain :");
	scanf("%d",&l);
	printf("enter the elements\n");
	for(int i=0;i<l;i++)
	{
		temp_1 = (struct node*)malloc(sizeof(struct node));
		temp_2 = (struct node*)malloc(sizeof(struct node));
		scanf(" %c",&temp_1->data_1);
		switch(temp_1->data_1)
		{
			case 'C': temp_2->data_2='G';
					  break;
			case 'G': temp_2->data_2='C';
					  break;
			case 'A': temp_2->data_2='T';
					  break;
			case 'T': temp_2->data_2='A';
					  break;
		}
		
		if(a[0] == NULL)
		{
			a[0]=temp_1;
			a[1]=temp_2;
			printf("%c-%c\n",temp_1->data_1,temp_2->data_2);
		}
		else
		{
			struct node *p,*q;
			p=a[0];
			q=a[1];
			while(p->link_1!= NULL)
			{
				p=p->link_1;
				q=q->link_2;
			}
			p->link_1=temp_1;
			q->link_2=temp_2;
			printf("%c-%c\n",temp_1->data_1,temp_2->data_2);
		}
	}
	int mode;
	int molid,position;
	char nuc,chainid;
	while(1)
	{
		printf("enter the operation you want to perform:\n1.insert\n2.delete\n3.split chain\n4.Print Chain\n5.Print All Chains\n6.quit\n");
		scanf("%d",&mode);
		switch(mode)
		{
			case 1 : printf("enter the MOLECULE ID,chain ID, nucleotide to be inserted,position:\n");
					 scanf(" %d %c %c %d",&molid,&chainid,&nuc,&position);
					 insert(molid,chainid,nuc,position);
					 break;

			case 2 : printf("enter the molecule ID to be deleted,position\n");
					  scanf("%d%d",&molid,&position);
					  delete(molid,position);
			          break;

			case 3 : printf("enter the molecular ID:");
					 scanf(" %d",&molid);
					 split(molid);
					 break;

			case 4 : printf("enter the molecular ID:");
					 scanf("%d",&molid);
					 PrintChain(molid);
	 				 break;

	 		case 5 : printf("Printing All Chains:\n");
	 				 PrintAllChains();
	 				 break;

	 		case 6 : exit(0);
	 				 break;

			default: printf("enter a valid operation\n");
					 break;
		}
	}
}

int insert(int p,char q,char r,int s)
{
	struct node *temp_1,*temp_2,*x,*y;
	int len = length(p);
	temp_1=(struct node*)malloc(sizeof(struct node));
	temp_2=(struct node*)malloc(sizeof(struct node));
	if(q == 'a')
	{
		x = a[2*p-2];
		y = a[2*p-1];
		temp_1->data_1=r;
		switch(temp_1->data_1)
		{
			case 'C': temp_2->data_2='G';
					  break;
			case 'G': temp_2->data_2='C';
					  break;
			case 'A': temp_2->data_2='T';
					  break;
			case 'T': temp_2->data_2='A';
					  break;
		}
		if(s>len+1)
		{
			printf("enter a valid location to insert\n");
		}
		else
		{
			if(s == 1)
			{
				temp_1->link_1 = x;
				x = temp_1;
				a[2*p-2] = x;
				temp_2->link_2 = y;
				y = temp_2;
				a[2*p-1] = y;
				printf("%c-%c\n",temp_1->data_1,temp_2->data_2);
				printf("\n");
			}
			else
			{
				for(int i=0;i<s-2;i++)
				{
					x=x->link_1;
					y=y->link_2;
				}
				temp_1->link_1 = x->link_1;
				temp_2->link_2 = y->link_2;
				x->link_1=temp_1;
				y->link_2=temp_2;
				printf("%c-%c\n",temp_1->data_1,temp_2->data_2);
				printf("\n");
			}
		}
	}
	else if(q == 'b')
	{
		y = a[2*p-2];
		x = a[2*p-1];
		temp_2->data_2=r;
		switch(temp_2->data_2)
		{
			case 'C': temp_1->data_1='G';
					  break;
			case 'G': temp_1->data_1='C';
					  break;
			case 'A': temp_1->data_1='T';
					  break;
			case 'T': temp_1->data_1='A';
					  break;
		}
		if(s>len+1)
		{
			printf("enter a valid location to insert\n");
		}
		else
		{
			if(s == 1)
			{
				temp_2->link_2 = x;
				x = temp_2;
				a[2*p-1] = x;
				temp_1->link_1 = y;
				y = temp_1;
				a[2*p-2] = y;
				printf("%c-%c\n",temp_1->data_1,temp_2->data_2);
				printf("\n");
			}
			else
			{
				for(int i=0;i<s-2;i++)
				{
					x=x->link_2;
					y=y->link_1;
				}
				temp_2->link_2 = x->link_2;
				temp_1->link_1 = y->link_1;
				x->link_2=temp_2;
				y->link_1=temp_1;
				printf("%c-%c\n",temp_1->data_1,temp_2->data_2);
				printf("\n");
			}
		}
	}
	PrintChain(p);
}

int delete(int p,int q)
{
	struct node *temp_1,*temp_2,*x,*y;
	temp_1 = a[2*p-2];
	temp_2 = a[2*p-1];
	if(q == 1)
	{
		a[2*p-2] = temp_1->link_1;
		a[2*p-1] = temp_2->link_2;
		free(temp_1);
		free(temp_2);
	}
	else
	{
		for(int i=0;i<q-2;i++)
		{
			temp_1 = temp_1->link_1;
			temp_2 = temp_2->link_2;
		}
		x = temp_1->link_1;
		temp_1->link_1 = x->link_1;
		free(x);
		y = temp_2->link_2;
		temp_2->link_2 = y->link_2;
		free(y);
	}
	PrintChain(p);
}

int split(int p)
{
    int j = 0;
    while(a[j]!=NULL)
    {
        j++;
    }
    struct node *temp,*temp_1,*temp_2,*temp_3,*temp_4,*k,*l,*m,*n,*x,*y;
    k = a[2*p-2];
    l = a[2*p-1];
    m = a[j];
    n = a[j+1];
    for(int i=0;i<length(p);i++)
    {
        temp_3 = (struct node*)malloc(sizeof(struct node));
        temp_4 = (struct node*)malloc(sizeof(struct node));
        temp_3->link_3 = NULL;
        temp_4->link_4 = NULL;
        temp_1 = k;
        temp_2 = l;
        temp_3->data_3 = temp_1->data_1;
        temp_4->data_4 = temp_2->data_2;        
        m=temp_3;
        n=temp_4;
        printf("%c-%c\n",temp_3->data_3,temp_4->data_4);
        if(m == NULL)
        {
            x = m;
            y = n;
            a[j] = x;
			a[j+1] = y;
        }
        m = m->link_3;
        n = n->link_4;
        k = k->link_1;
        l = l->link_2;
    }
    /*temp = a[j+1];
    a[j+1] = a[2*p-1];
    a[2*p-2] = temp;*/
}

int PrintChain(int p)
{
	struct node *temp_1;
	struct node *temp_2;
	temp_1 = a[2*p-2];
	temp_2 = a[2*p-1];
	while(temp_1 != NULL)
	{
		printf("%c-%c\n",temp_1->data_1,temp_2->data_2);
		temp_1 = temp_1->link_1;
		temp_2 = temp_2->link_2;
	}
}

int PrintAllChains()
{
	struct node *temp_1;
	struct node *temp_2;
	int i=0;
	while(a[i]!=NULL)
	{
		temp_1 = a[i];
		temp_2 = a[i+1];
		printf("Chain %d:\n",(i+2)/2);
		while(temp_1 != NULL)
		{
			printf("%c-%c\n",temp_1->data_1,temp_2->data_2);
			temp_1 = temp_1->link_1;
			temp_2 = temp_2->link_2;
		}
		i = i+2;
	}	
}

int length(int p)
{
	struct node *temp_1;
	temp_1 = a[2*p-2];
	int count=1;
	while(temp_1->link_1!=NULL)
	{
		temp_1=temp_1->link_1;
		count++;
	}
	return count;
}
