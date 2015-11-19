import java.nio.file.Files;
import java.io.*;

class testaud
{
        /* Program to generate byte structure of recorded sound*/
	public static void main(String args[]) throws Exception
	{
                /*Open the music*/
		ByteArrayOutputStream out = new ByteArrayOutputStream();
		BufferedInputStream in = new BufferedInputStream(new FileInputStream("aud.wav"));

		int read, n, ind;
		byte[] buff = new byte[1024];
		while ((read = in.read(buff)) > 0)
		{
    			out.write(buff, 0, read);
		}
		out.flush();
                /*write in a byte array*/
		byte[] fileContent = out.toByteArray();
		FileWriter file[]=new FileWriter[10];
                for(int i=0;i<10;i++)
                file[i] = new FileWriter("aud"+i+".txt");
                /*Write byte array to file based on conditions*/
		for(int i=16;i<fileContent.length-1;i++)
		{
                        if(fileContent[i]!=0)
                        {
                        	n = fileContent[i-1]^fileContent[i+1];
                        	n = n>0?n:(-1*n);
                        	ind = n%10;
				file[ind].write(""+(fileContent[i])+"\n");
                        }
                        else if (fileContent[i+1]!=0)
                        {
                        	n = fileContent[i-1]^fileContent[i+1];
                        	n = n>0?n:(-1*n);
                        	ind = n%10;
				file[ind].write(""+(fileContent[i])+"\n");
                        }
		}
                n = fileContent[0]^fileContent[fileContent.length-2];
                n = n>0?n:(-1*n);
                ind = n%10;
	        file[ind].write(""+(fileContent[fileContent.length-1])+"\n");
                for(int i=0;i<10;i++)
                file[i].close();
	}
}
