import java.util.Random;

class Square implements Runnable
{
    Thread t;
    int x;
    Square(int n)
    {
        x=n;
        t=new Thread(this,"Square");
        t.start();
    }
    public void run()
    {
        System.out.println("Square of "+x+" = "+x*x);
    }
}
class Cube implements Runnable
{
    Thread t;
    int x;
    Cube(int n)
    {
        x=n;
        t=new Thread(this, "Cube");
        t.start();
    }
    public void run()
    {
        System.out.println("Cube of "+x+" is"+(x*x*x));
    }
}
public class Generator implements Runnable
{
    Thread t;
    Generator()
    {
        t=new Thread(this,"Generate");
        t.start();
    }
    public void run()
    {
        int n;
        Random r=new Random();
        for(int i=0;i<5;i++)
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
                System.out.println(e);
            }
        }
    }
    public static void main(String[] args)
    {
        Generator g=new Generator();    
    }
}
