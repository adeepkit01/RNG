import java.nio.file.Files;
import java.io.*;

class testimg
{
	/* Program to generate byte structure of clicked image*/
	public static void main(String args[]) throws Exception
	{
                /*Open the image*/
		File fi = new File("image.png");
                /*write in a byte array*/
		byte[] fileContent = Files.readAllBytes(fi.toPath());
                int n, ind;
                FileWriter file[]=new FileWriter[10];
                for(int i=0;i<10;i++)
                file[i] = new FileWriter("img"+i+".txt");
                /*Write byte array to file based on conditions*/
		for(int i=1;i<fileContent.length-1;i++)
		{
                        n = fileContent[i-1]^fileContent[i+1];
                        n = n>0?n:(-1*n);
                        ind = n%10;
			file[ind].write(""+(fileContent[i])+"\n");
		}
                n = fileContent[0]^fileContent[fileContent.length-2];
                n = n>0?n:(-1*n);
                ind = n%10;
	        file[ind].write(""+(fileContent[fileContent.length-1])+"\n");
                for(int i=0;i<10;i++)
                file[i].close();
	}
}
