#include<stdio.h>
#include<stdlib.h>
#include <time.h>

/*Program to get the network statistics and hash the retreived data*/

int main()
{
	system("nstat > net.txt");
	FILE *ifp=fopen("net.txt","r");
	int test, i=0, a[100],  n=0;
        long long int highorder, h=0, g;
	fscanf(ifp, "%*s");
	while(fscanf(ifp, "%*s%d%*s", &test) == 1)
	{
    		a[n++]=test;
	}
        system("rm net.txt");
	time_t seconds = time (NULL);
	clock_t tic = clock();
	int num = (int)seconds/(int)tic;
        /*Choose the hash to use*/
	if(num%2==0)
	{
                /*CRC Hash*/
		for(i=0;i<n;i++)
    		{
        		highorder = h & 0xf8000000;   
        		h = h << 5;                    
        		h = h ^ (highorder >> 27);     
        		h = h ^ a[i];
    		}
	}
        else
        {
                /*PJW Hash*/
		for(i=0;i<n;i++)
    		{
         		h = (h << 4) + a[i];               
         		g = h & 0xf0000000;              
         		if (g != 0)                     
             		h = h ^ (g >> 24);            
         		h = h ^ g;         
    		}
	}
	ifp = fopen("hashed.txt", "a");                    
    	fprintf(ifp, "%lld\n", h);
}
