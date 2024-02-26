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
        System.out.println("Sqaure of "+x+" == "+(x*x));
    }
}
class Cube implements Runnable
{
    Thread t;
    int x;
    Cube(int n)
    {
        x=n;
        t=new Thread(this,"Cube");
        t.start();
    }
    public void run()
    {
        System.out.println("Cube of "+x+" == "+(x*x*x));
    }
}
public class SquareCube implements Runnable
{
    Thread t;
    SquareCube()
    {
        t=new Thread(this,"Generate");
        t.start();
    }
    public void run()
    {
        int n,i;
        Random r=new Random();
        for(i=0;i<5;i++)
        {
            n=r.nextInt(100);
            System.out.println("Generared no="+n);
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
        SquareCube s=new SquareCube();
    }
}