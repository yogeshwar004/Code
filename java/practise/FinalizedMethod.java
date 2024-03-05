import java.util.Scanner;

public class FinalizedMethod
{
    int x,y;
    Scanner s=new Scanner(System.in);
    void display()
    {
        System.out.println("x="+x+"y="+y);
    }
    protected void finalize()
    {
        s.close();
        System.out.println("This is Finalize Method ");
    }
    public static void main(String[] args)
    {
        FinalizedMethod obj=new FinalizedMethod();
        obj.display();
        System.gc();
        //Runtime.getRuntime().gc();
        //Runtime.runFinalizersOnExit(true);

    }
}
