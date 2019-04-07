#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int queue[100],y[100],head,seek=0,n,i,j,temp=0;
	printf("    ****** SHORTEST SEEK TIME FIRST Disk Scheduling Algorithm ******\n");
	printf("Enter the size of Queue of cylinders:\t");
	scanf("%d",&n);
	printf("Enter the positions of cylinders: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&queue[i]);
	}
	
	printf("Enter the initial head position: ");
	scanf("%d",&head);
	for(i=1;i<n;i++)
	{
		y[i]=abs(head-queue[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(y[i]>y[j])
			{
				temp=y[i];
				y[i]=y[j];
				y[j]=temp;
				temp=queue[i];
				queue[i]=queue[j];
				queue[j]=temp;
			}
		}
	}
	for(i=1;i<n-1;i++)
	{
		seek=seek+abs(head-queue[i]);
		head=queue[i];
	}
	printf("\nTotal Seek Time is :- %d ",seek);
	getch();
}
