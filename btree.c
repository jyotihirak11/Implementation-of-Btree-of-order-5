#include<stdio.h>
#include<malloc.h>

#define key 4
#define order (key+1)


struct BN{
	int data[key +1];
	struct BN *child[order+1];
	int count;
};

typedef struct BN node;

int insertn_sort(node*);
int split(node **, node *);

int insert(node** r, int n)
{
	node *temp, *cur;
	int count=0, i;

	cur=*r;

	if((*r)==NULL)
	{
		temp=(node*)malloc(sizeof(node));
	
		temp->data[0]=n;
		temp->count=1;
		temp->child[0]=NULL;
		*r=temp;
		return (1);

	}	

	else if((*r)->child[0]!=NULL)
	{
	//	cur=*r;

		for(i=0; i<cur->count; i++)
		{

			if( n < cur->data[i])
			{
				cur=cur->child[i];
				count=cur->count;

				cur->data[count]=n;

				cur->child[count]=NULL;
				cur->count=cur->count+1;
				count=cur->count;
				printf("%d", count);

				insertn_sort(cur);
				if(count==key+1)
				{
					printf("\n Overflow occured");
					split(r, cur);

				}
				return (1);

			}


	       	}
		
		cur=cur->child[i];
		count=cur->count;

		cur->data[count]=n;

		cur->child[count]=NULL;
		cur->count=cur->count+1;
		count=cur->count;
		printf("%d", count);
		
		insertn_sort(cur);
		if(count==key+1)
		{
			printf("reach herea");
			printf("\n Overflow occured");
			split(r, cur);
		}
		return (1);
	


	}
	
	
	else if((*r)->count!=key+1)
	{
	//	cur=*r;
		count=(*r)->count;

		temp->data[count]=n;

		temp->child[count]=NULL;
		temp->count=temp->count+1;
		count=(*r)->count;
		printf("%d", count);
		
		insertn_sort(temp);
		if(count==key+1)
		{
			printf("\n Overflow occured");
			split(r, cur);


		}
		return (1);
	}
	return (0);				
}


int split(node **r, node * cur)
{
//	node *cur=*r;
	node *temp, *parent, *another;
	int count, mid, pushed, i, j;
//	count=(*r)->count;

	if(cur==*r)
	{
		parent=NULL;
		mid=key/2;
		pushed=cur->data[mid];
		temp=(node*)malloc(sizeof(node));
		for(i=0; i<mid; i++)
		{
			temp->data[i]=cur->data[mid+i+1];

			temp->child[i]=NULL;
		}
		temp->count=i;

		cur->count=mid;
		if(parent==NULL)
		{
			another=(node*)malloc(sizeof(node));
			another->data[0]=pushed;
			another->child[0]=cur;
			another->child[1]=temp;
			another->count=1;
			*r=another;
			return(1);
		}
	}

	parent=*r;

	for (i=0; i< parent->count; i++)
	{
		if(parent->child[i]->count==key+1)
		{
		
			cur=parent->child[i];
			//			count1=cur->count;
			mid=key/2;
			pushed=cur->data[mid];
			parent->data[parent->count]=pushed;
			cur->count=mid;
			parent->count=parent->count+1;
			insertn_sort(parent);
		
			for(i=0; i<parent->count; i++)
			{
				if(pushed==parent->data[i])
				{
					another=(node*)malloc(sizeof(node));
					j=i;
					while(j<parent->count)
					{
						if(parent->child[j+1]!=NULL)
						{
							parent->child[j+2]=parent->child[j+1];	
							j++;
						}

					}
					parent->child[i+1]=another;
					break;
				}
			}
			for(i=0; i<mid; i++)
			{
				another->data[i]=cur->data[mid+i+1];

				another->child[i]=NULL;
			}
			another->count=i;


			return (1);
		}


	}
	if(parent->child[i]->count==key+1)
	{
		printf("come");
		cur=parent->child[i];
		//			count1=cur->count;
		mid=key/2;
		pushed=cur->data[mid];
		parent->data[parent->count]=pushed;
		cur->count=mid;
		parent->count=parent->count+1;
		another=(node*)malloc(sizeof(node));
		parent->child[i+1]=another;

		for(i=0; i<mid; i++)
		{
			another->data[i]=cur->data[mid+i+1];

			another->child[i]=NULL;
		}
		another->count=i;



		return (1);
	}

	}


	int insertn_sort(node *temp)
	{
		int i, j, given;
		for(i=1; i<temp->count; i++)
		{
			given=temp->data[i];
			for(j=i-1; j>=0; j--)
			{
				if(temp->data[j] > given)
				{
					temp->data[j+1]=temp->data[j];
				}
				else
					break;
			}
			temp->data[j+1]=given;
		}
		return (0);

	}


	int inorder(node *temp)
	{
		if(temp!=NULL)
		{

			int count, i;
			count=temp->count;
			for(i=0; i<count; i++)
			{
				inorder(temp->child[i]);
				
				if(i==0)
				{
					printf("	");
				}
				else
					printf(", ");

				printf("%d", temp->data[i]);
			}
			inorder(temp->child[i]);
		}
		return (0);
	}

	int main()
	{
		node* root=NULL;
		int i=1, ret_val, n;
		char choice;
		while(i==1)
		{
			printf("\n Enter the choice you want to select: \n1. Insert \n2.inorder traverse \n3. Exit");
			scanf("%s", &choice);
			switch(choice)
			{
				case '1':
					printf("\nEnter the element you want to insert in a tree:");
					scanf("%d", &n);
					ret_val=insert(&root,n);
					if(ret_val==1)
					{
						printf("\n Successfully inserted");
					}
					else
						printf("\n Cannot insert");
					break;
				case '2':
					inorder(root);
					break;
				case '3':
					return (0);
					break;
				default:
					printf("\n You have entered an incorrect option");
			}
		}
		return (0);
	}

















