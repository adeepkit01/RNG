#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <time.h>

/*Program to induce algorithmic randomness */

void selectKItems(int stream[], int k)
{
    /*Function to randomly select k elements from whole array*/
    int i,n;  
    int reservoir[10000];
    FILE* fp;
    for (i = 0; i < k; i++)
        reservoir[i] = stream[i];
    for (; i < 10000; i++)
    {
        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*[^\n]");
        fscanf(fp,"%*[^\n]");
    	fscanf(fp,"%*s %d",&n);
    	fclose(fp);
        int j = n % (i+1);
        if (j < k)
          reservoir[j] = stream[i];
    }
    for (i = 0; i < k; i++)
       stream[i]=reservoir[i];
}

void random_shuffle(int arr[], int max)
{
    /*Function to shuffle array*/
    srand(time(NULL));
    int i, j, temp,n;
    FILE* fp;
    for (i = max - 1; i > 0; i--)
    {
        fp = fopen("/proc/stat","r");
        fscanf(fp,"%*[^\n]");
    	fscanf(fp,"%*s %d",&n);
    	fclose(fp);
        j = n%(i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
 
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int rpartion(int arr[], int p, int r)
{
    /*Randomised quicksort partition*/
    time_t seconds = time (NULL);
    int pivotIndex = p + (int)seconds%(r - p + 1); //generates a random number as a pivot
    int pivot;
    int i = p - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
 
    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}
 
void rquick_sort(int arr[], int p, int q)
{
    /*Randomised quicksort*/
    int j;
    if (p < q)
    {
        j = rpartion(arr, p, q);
        rquick_sort(arr, p, j-1);
        rquick_sort(arr, j+1, q);
    }
}

int partion(int arr[], int p, int r)
{
    /*quicksort partition*/
    int pivotIndex = (p+r)/2;
    int pivot;
    int i = p - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
 
    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}
 
void quick_sort(int arr[], int p, int q)
{
    /*quicksort*/
    int j;
    if (p < q)
    {
        j = partion(arr, p, q);
        quick_sort(arr, p, j-1);
        quick_sort(arr, j+1, q);
    }
}



int main()
{
	/*Run different sort on different core for randomness*/
        if(fork())
        {
                clock_t tic = clock();
		cpu_set_t  mask;
		CPU_ZERO(&mask);
		CPU_SET(0, &mask);
		sched_setaffinity(0, sizeof(mask), &mask);
                time_t seconds = time (NULL);
                int fv = (int)seconds%5;
                char fname[100];
                sprintf(fname,"aud%d.txt",2*fv);
		FILE *fptr;
                fptr = fopen(fname,"r");
                int a[10000];
                int size=(int)seconds%10000;
                int i;
                for(i=0;i<10000;i++)
                {
                    fscanf(fptr,"%d",&a[i]);
                }
                selectKItems(a,size);
                random_shuffle(a,size); //To randomize the array
    		quick_sort(a, 0, size-1);
                tic = clock()-tic;
		fptr=fopen("hashed.txt","a");
  		fprintf(fptr,"%d\n",(int)(time (NULL)*tic));
  		fclose(fptr);
        }
        else if(fork())
        {
                clock_t tic = clock();
		cpu_set_t  mask;
		CPU_ZERO(&mask);
		CPU_SET(1, &mask);
		sched_setaffinity(0, sizeof(mask), &mask);
                time_t seconds = time (NULL);
                int fv = (int)seconds%5;
                char fname[100];
                sprintf(fname,"aud%d.txt",2*fv+1);
		FILE *fptr;
                fptr = fopen(fname,"r");
                int a[10000];
                int size=(int)seconds%10000;
                int i;
                for(i=0;i<10000;i++)
                {
                    fscanf(fptr,"%d",&a[i]);
                }
                selectKItems(a,size);
                random_shuffle(a,size); //To randomize the array
    		rquick_sort(a, 0, size-1);
                tic = clock()-tic;
		fptr=fopen("hashed.txt","a");
  		fprintf(fptr,"%d\n",(int)(time (NULL)*tic));
  		fclose(fptr);
        }
        else if(fork())
        {
                clock_t tic = clock();
		cpu_set_t  mask;
		CPU_ZERO(&mask);
		CPU_SET(2, &mask);
		sched_setaffinity(0, sizeof(mask), &mask);
                time_t seconds = time (NULL);
                int fv = (int)seconds%5;
                char fname[100];
                sprintf(fname,"img%d.txt",2*fv);
		FILE *fptr;
                fptr = fopen(fname,"r");
                int a[10000];
                int size=(int)seconds%10000;
                int i;
                for(i=0;i<10000;i++)
                {
                    fscanf(fptr,"%d",&a[i]);
                }
                selectKItems(a,size);
                random_shuffle(a,size); //To randomize the array
    		quick_sort(a, 0, size-1);
                tic = clock()-tic;
		fptr=fopen("hashed.txt","a");
  		fprintf(fptr,"%d\n",(int)(time (NULL)*tic));
  		fclose(fptr);
        }
        else
        {
                clock_t tic = clock();
		cpu_set_t  mask;
		CPU_ZERO(&mask);
		CPU_SET(3, &mask);
		sched_setaffinity(0, sizeof(mask), &mask);
                time_t seconds = time (NULL);
                int fv = (int)seconds%5;
                char fname[100];
                sprintf(fname,"img%d.txt",2*fv+1);
		FILE *fptr;
                fptr = fopen(fname,"r");
                int a[10000];
                int size=(int)seconds%10000;
                int i;
                for(i=0;i<10000;i++)
                {
                    fscanf(fptr,"%d",&a[i]);
                }
                selectKItems(a,size);
                random_shuffle(a,size); //To randomize the array
    		rquick_sort(a, 0, size-1);
                tic = clock()-tic;
		fptr=fopen("hashed.txt","a");
  		fprintf(fptr,"%d\n",(int)(time (NULL)*tic));
  		fclose(fptr);
        }
}
