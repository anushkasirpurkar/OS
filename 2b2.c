 #include<stdio.h>
int main(int argc, char* argv[])
{

	int a[15],i,m,c=0,l,u,mid;
    	printf("\nEnter the number to be searched  :  ");
    	scanf("%d",&m);
	for(i=0;i<argc;i++)
	{
		a[i]=atoi(argv[i]);
	}
       	l=0,u=i-1;
    	while(l<=u)
	{
        	mid=(l+u)/2;
        	if(m==a[mid])
		{
             		c=1;
             		break;
         	}
         	else if(m<a[mid])
	 	{
         		u=mid-1;
         	}
         	else
	 	{
             		l=mid+1;
	 	}
    	}
    	if(c==0)
        	printf("\nThe number %d is not found.\n",m);
    	else
         	printf("\nThe number %d is found at postion %d.\n",m,mid+1);

	return 0;
}
