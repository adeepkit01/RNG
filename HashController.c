#include<stdio.h>

/*Program to generate hash from different parts of audio and image byte array generated*/

int main()
{
	int i,n;
        char name[100];
	FILE *fp;
        for(i=0;i<10;i++)
        {
                /*Choose which audio byte file to hash based on the status of CPU*/
		fp = fopen("/proc/stat","r");
    		fscanf(fp,"%*s %d",&n);
        	fclose(fp);
        	if(n%2==0)
                {
                        /*Execute CRC hash algorithm*/
                	system("cc CRCHash.c -o CRC");
                	sprintf(name,"./CRC <aud%d.txt",i);
                	system(name);
                        system("rm CRC");
                }
                else
                {
                        /*Execute PJW hash algorithm*/
			system("cc PJWHash.c -o PJW");
                	sprintf(name,"./PJW <aud%d.txt",i);
                	system(name);
                        system("rm PJW");
                }
        }
        for(i=0;i<10;i++)
        {
                /*Choose which image byte file to hash based on the status of CPU*/
		fp = fopen("/proc/stat","r");
    		fscanf(fp,"%*s %d",&n);
        	fclose(fp);
        	if(n%2==0)
                {
                        /*Execute CRC hash algorithm*/
                	system("cc CRCHash.c -o CRC");
                	sprintf(name,"./CRC <img%d.txt",i);
                	system(name);
                        system("rm CRC");
                }
                else
                {
                        /*Execute PJW hash algorithm*/
			system("cc PJWHash.c -o PJW");
                	sprintf(name,"./PJW <img%d.txt",i);
                	system(name);
                        system("rm PJW");
                }
       }
}
