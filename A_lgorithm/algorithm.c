#include <stdio.h>

    void swap(int *a,int *b)
	{
		int temp;
		temp=*a;
		*a=*b;
 		*b=temp;
    }
    
   void three_swap(int arr[][3][3],int count)
   {
   	   for(int i=0;i<count;i++)
       {
       	swap(&arr[i][0][0],&arr[i][0][2]);
	    swap(&arr[i][1][0],&arr[i][1][2]);
	    swap(&arr[i][2][0],&arr[i][2][2]);
       }
   }	
    
   void arr_swap(int arr[][3])
	{
		swap(&arr[0][0],&arr[0][2]);
		swap(&arr[1][0],&arr[1][2]);
		swap(&arr[2][0],&arr[2][2]);
	}

    void zero_2d(int arr[][3][3],int cnt)
   	{
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				arr[i][j][k]=0;
			}
		}
	}
	}
	
	void one_2d(int arr[][3][3],int cnt)
   	{
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				arr[i][j][k]=1;
			}
		}
	}
	}
	
	void print_array(int arr[][3][3],int cnt)
	{
		for(int i=0;i<cnt;i++)
		{
			printf("%d is\n",i+1);
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					printf("%d ",arr[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
int main()
{
	
	char choice;
	
	printf("NOTE:\n");
	printf("1)Enter The Number Of Pdf Pages You Want To Arrange.\n");
	printf("2)In The Sequence 0 Represent Blank Page.\n");
	do
	{
	int count=0;
	int size;
	int cnt=0;
	
	printf("\nEnter Your Number Of Pages:");
	scanf("%d",&size);
	
	for(int i=1;i<size;i++)
	{
		if(i%18==0)
		{
			cnt++;
		}
	}
	count =cnt+1;
	
	int even[count][3][3];
	int odd[count][3][3];
	
	zero_2d(even,count);
	zero_2d(odd,count);
	
	int k=2;
	int a=1;
	
	
	for(int o=0;o<count;o++)
	{
		for(int i=0;i<3;i++)
	    {
		    for(int j=0;a<=size;j++)
		    {
			odd[o][i][j]=a;
			a+=2;
	     	}
	     	for(int j=0;k<=size;j++)
		    {
			even[o][i][j]=k;
			k+=2;
	     	}
	    }
    }
    
    three_swap(even,count);

    printf("\nArray In Diagram:");
    for(int i=0;i<count;i++)
	{
		printf("\n");
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					printf("%d ",odd[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					printf("%d ",even[i][j][k]);
				}
				printf("\n");
			}
		}
	
	}
    
    
    
	
	printf("\nPages Sequence Is:");
	for(int i=0;i<count;i++)
	{
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					printf("%d,",odd[i][j][k]);
				}
			}
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					printf("%d,",even[i][j][k]);
				}
			}
			
		}
	
	}
    printf("\n\nNumber Of Pages Need For Printing :%d",count);
    printf("\nThe Count Of a Is:%d",a);
	do
	{
	printf("\nPress y/n For More Arranging:");
	scanf(" %c",&choice);
	if(choice !='y'&&choice !='n')
	{
		printf("Invalid Input");
	}
    }while(choice !='y'&&choice !='n');
	
	
    }while(choice=='y'||choice != 'n');
	

	
}