#include<stdio.h>

/*Program to read a file and hash it using CRC hash*/

inline int inp()
{
    /*Fuction to improve input speed*/
    int noRead=0;
    char p=getchar_unlocked();
    for(;p<33;)
    {
     p=getchar_unlocked();
    };
    while(p>32)
    {
     noRead = (noRead << 3) + (noRead << 1) + (p - '0');
     p=getchar_unlocked();
    }
    return noRead;
};

int main()
{
    int n, a[10000], i;
    long long int h=0, highorder;
    FILE *fp;
    fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %d",&n);
    fclose(fp);
    n=n%10000;
    for (i=0;i<n;i++)
    {
        a[i]=inp();
        if(a[i]<0)
        a[i]=512+a[i];
    }
    /*CRC Hash function*/
    for(i=0;i<n;i++)
    {
        highorder = h & 0xf8000000;   
        h = h << 5;                    
        h = h ^ (highorder >> 27);     
        h = h ^ a[i];
    }
    /*Written to hash file*/
    fp = fopen("hashed.txt", "a");                    
    fprintf(fp, "%lld\n", h);
}
