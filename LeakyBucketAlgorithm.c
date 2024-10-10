/*---------------------------
LeakyBucketAlgorithm.c
----------------------------*/

# include <stdio.h>
# include <stdlib.h>

main()
{
	int bucket_capacity=4;
	int rate=3;
	int remain=0;
	int count,packets[20],i,sent;
	
	printf("Enter the count of packets:");
	scanf("%d",&count);
	
	printf("Enter the size of packets:");
	for( i=1;i<=count;i++){
		scanf("%d",&packets[i]);
	}
	
	printf("%s\t%s\t%s\t%s\n","packet size","accept","sent","remaining");
	
	for( i=1;i<=count;i++)
	{
	    if(packets[i]<=bucket_capacity)  //comparing the packet size with the bucket capacity
		{
	        if(packets[i]+remain<=rate){  //comparing the packet size with the rate of outflow of data(drops as in leaky bucket diagram)
			    sent=packets[i]+remain;
			    remain=packets[i]-sent;
			}else{
			    sent=rate;
			    remain=(packets[i]+remain)-sent;
			}
			if(remain<1){    //Sometimes the packet size is less than the data sent(when including remaining data),so to prevent remain to have negative values
			remain=0;
			}
			printf("%d\t\t%d\t%d\t%d\n",packets[i],packets[i],sent,remain);
		}else{
			printf("%d\t\t%s\t%d\t%d\n",packets[i],"dropped",0,remain);
		}
	}
	
}
