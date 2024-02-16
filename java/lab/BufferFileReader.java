import java.io.*;
public class BufferFileReader
{
    static void read()throws FileNotFoundException,IOException
    {
        FileReader f=new FileReader("C:\\Users\\Yogeshwar N\\Documents\\YOGESHWAR\\OOPS\\Demo.txt");
        try
        {
            BufferedReader r=new BufferedReader(f);
            System.out.println(r.readLine());
            throw new IOException("Unexcepted Halt");
        }
        finally
        {
            System.out.println("File Closed");
            f.close();
        }
    }
    public static void main(String[] args)
    {
        try
        {
            read();
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
}
