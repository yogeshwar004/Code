import java.util.Random;
import java.util.Scanner;

class Square implements Runnable
{
    Thread t;
    int x;
    Square(int x)
    {
        this.x=x;
        t=new Thread(this,"Square");
        t.start();
    }
    public void run()
    {
        System.out.println("Sqaure of "+x+" = "+(x*x));
    }
}
class Cube implements Runnable
{
    Thread t;
    int x;
    Cube(int x)
    {
        this.x=x;
        t=new Thread(this,"Cube");
        t.start();
    }
    public void run()
    {
        System.out.println("Cube of "+x+" = "+(x*x*x));
    }
}
public class Generator implements Runnable
{
    Thread t;
    Generator()
    {
        t=new Thread(this,"Generator");
        t.start();
    }
    public void run()
    {
        int n,i;
        Random r=new Random();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of values to be generated for sqaure/cube operation:");
        int no=sc.nextInt();
        for(i=0;i<no;i++)
        {
            n=r.nextInt(100);
            System.out.println("Generated no="+n);
            Square s=new Square(n);
            Cube c=new Cube(n);
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException e)
            {
                System.out.println(e.getMessage());
            }
        }
    }
    public static void main(String[] args)
    {
        Generator g=new Generator();
    }
}
