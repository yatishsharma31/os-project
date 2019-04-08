#include<stdio.h>
#include<stdlib.h>
int main()
{
	int p[20],at[20],bt[20],tat[20],tbt=0,n,total=0,pos,temp=0;
	float avg_wt=0,avg_tat,z,k,l;
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nFor Process[%d]\n\n",i+1);
		printf("Arrival Time:");
		while(1){
		scanf("%d",&at[i]);
		if(at[i]>=0){
		    break;}
		else
		{   
			printf("plz enter valid Arrival time\t");
		}
	}
		printf("Burst time:");
		while(1){
		scanf("%d",&bt[i]);
		if(bt[i]>0){
		    break;}
		else
		{
			printf("plz enter valid burst time\t");
		}
	}
		tbt+=bt[i];
		p[i]=i+1;   //having process numbers
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
  int max=-1,count=0,wt[n],wf[n],pf[n];
  int nat[n],nbt[n];
  wf[0]=0;
  pf[0]=p[0];
  avg_tat=tbt;
  tbt=tbt-bt[0];
  system("cls");
  system("color 4b");
 while(tbt>0)
 { temp=0;
 count++;
 wt[0]=0;
 for(int i =count;i<n;i++)
 { wt[i]=at[count-1]+bt[count-1]+wf[count-1]-at[i];
	if(wt[i]<0)
	{
	wt[i]=0;
		}
    k=wt[i];
    l=bt[i];
    z=k/l;
	if(z>max)	
    {   wf[count]=wt[i];
    	max=z;
    	pos=i;
	}
 }
 max=-1;
 pf[count]=p[pos];
 temp=p[count];
 p[count]=p[pos];
 p[pos]=temp;
 temp=at[count];
 at[count]=at[pos];
 at[pos]=temp;
 temp=bt[count];
 bt[count]=bt[pos];
 bt[pos]=temp;
 tbt=tbt-bt[count];
 avg_wt=avg_wt+wf[count];
  }
  avg_tat=avg_tat+avg_wt;
  for(int i=0;i<n;i++)
  {
  	printf("process(%d) \n\twaiting time %d \n\t Turn Around time is %d\n",pf[i],wf[i],wf[i]+bt[i]);
  }
  printf("Average  Waiting time %0.3f and Turn Around time %0.3f\n",avg_wt/n,avg_tat/n);
}
