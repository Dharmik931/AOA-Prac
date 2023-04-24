#include<stdio.h>
void main()
{
    //Accepting input
    int n,i,j,temp,maxd;
    printf("Enter number of jobs:");
    scanf("%d",&n);
    int job[n],d[n],p[n];
    printf("Enter job id:");
    for(i=0;i<n;i++)
   	 scanf("%d",&job[i]);
    printf("Enter job deadlines:");
    for(i=0;i<n;i++)
   	 scanf("%d",&d[i]);
    printf("Enter job profits:");
    for(i=0;i<n;i++)
   	 scanf("%d",&p[i]);
    
    //Finding max deadline
    maxd=d[0];
    for(i=1;i<n;i++)
   	 if(d[i]>maxd)
   		 maxd=d[i];
    int jobq[maxd];
    for(i=0;i<n;i++)
   	 jobq[i]=0;
    
    //Sort profit in descending order
    for(i=0;i<n-1;i++)
    {	 
    	for(j=0;j<n-i-1;j++)
    	{   
        	if(p[j]<p[j+1])
        	{          	 
       		 //Sorting profit
            	temp=p[j];
            	p[j]=p[j+1];
            	p[j+1]=temp;
            	//job id
            	temp=job[j];
            	job[j]=job[j+1];
            	job[j+1]=temp;
            	//deadlines
            	temp=d[j];
            	d[j]=d[j+1];
            	d[j+1]=temp;
   		 }
  		 }
  	 }
  	 printf("Entered data:\n");
  	 for(i=0;i<n;i++)
  		 printf("%d   	 %d    	 %d\n",job[i],d[i],p[i]);
  	 //Job Queue
  	 for(i=0;i<maxd;i++)
  	 {
  		 int deadline=d[i];
  		 while(deadline>=0)
  		 {
  			 if(jobq[deadline-1]!=0)
  				 deadline-=1;
  			 else
  				 break;
  		 }
  		 if(deadline<0)
  			 continue;
  		 jobq[deadline-1]=job[i];
  	 }
  	 printf("Job queue:");
  	 for(i=0;i<maxd;i++)
  		 printf("%d ",jobq[i]);
  	 printf("\n");
  	 //Total Profit
  	 int totalP;
  	 for(i=0;i<maxd;i++)
  	 {
  		 for(j=0;j<n;j++)
  		 {
  			 if(jobq[i]==job[j])
  				 totalP+=p[j];
  		 }
  	 }
  	 printf("Total profit:%d\n",totalP);
}
