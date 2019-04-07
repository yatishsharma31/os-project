#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int queue[100],y[100],head,seek=0,n,i,j,temp=0;
    float avg;
    printf("     ********** SHORTEST SEEK TIME FIRST Disk Scheduling Algorithm **********\n\n");
    printf("Enter the size of Queue of cylinders:\t");
    scanf("%d",&n);
    printf("Enter the position of cylinders in the queue:");
    for(i=0;i<n;i++)
    {
	scanf("%d",&queue[i]);	
	}
    printf("Enter the initial head position\t");
    scanf("%d",&head);
    for(i=0;i<n;i++)
    y[i]=abs(head-queue[i]);
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
    {
	    if(y[j]>y[j+1] && j<n-1)
        {
        temp=y[j];
        y[j]=y[j+1];
        y[j+1]=temp;
        temp=queue[j];
        queue[j]=queue[j+1];
        queue[j+1]=temp;
        }
    }
    } 
    for(i=0;i<n;i++)
    { 
    seek=seek+abs(head-queue[i]);
	head=queue[i];
	}
	printf("\nTotal Seek Time is%d\t",seek);
    avg=seek/(float)n;
    printf("\nAverage Seek Time is %f\t",avg);
    getch();
}


