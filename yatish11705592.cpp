#include<stdio.h>
#include<process.h>
int main()
{  
	int p[20],at[20],bt[20],tat[20],tbt=0,n,total=0,pos,temp=0;
	float priority[20],avg_wt,avg_tat;
	
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
    
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the arrival time for p%d:",i);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time for p%d:",i);
		scanf("%d",&bt[i]);
		tbt+=bt[i];
		p[i]=i;   //having process numbers
	}
	printf("total burst time%d\n",tbt);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		if(at[j]>at[j+1] && j<(n-1)){
		temp=at[j];
		at[j]=at[j+1];
		at[j+1]=temp;
		temp=p[j];
		p[j]=p[j+1];
		p[j+1]=temp;   // burst time sorting
		 temp = bt[j];
		 bt[j]=bt[j+1];
		 bt[j+1]=temp;
	   }
	}
}
system("cls");
system("color 5b");
printf("processes\t\tArival time\t\tBurst time\n");
for(int i=0;i<n;i++)
{
	printf("p[%d]\t\t\t%d\t\t%d\n",p[i],at[i],bt[i]);
}
int wt[n];
wt[0]=0;
for(int i=1;i<n;i++)
{
wt[i]=at[i-1]+bt[i-1]+wt[i-1]-at[i];
if(wt[i]<0)
{
wt[i]=0;
}
}

for(int i=0;i<n;i++){
	printf("waiting times for p(%d)\t\t %d\n",p[i],wt[i]);
}
int x[n];
int count=1,z=0;
for(int i=0;i<n;i++)
{
	if(at[i]==at[i+1] &&i<n-1)
	{
		count++;
	}
	else
	{
	x[z]=count;
	printf("common values %d and position strart from %d to %d\n",x[z],(i-x[z]+1),i);
	count=1;
	z++;
    }
}
	
}

