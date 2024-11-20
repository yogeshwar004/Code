import java.util.Random;
import java.util.Scanner;

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
        System.out.println("Cube of "+x+" = "+(x*x*x));
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
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter n:");
        int m=sc.nextInt();
        for(int i=0;i<m;i++)
        {
            n=r.nextInt(100);
            System.out.println("Generated no="+n);
            try
            {
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
            catch(Exception e)
            {
                System.out.println(e);
            }
        sc.close();
        }
    }
    public static void main(String[] args)
    {
        try
        {
            Generator g;
            g=new Generator();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
/*
Output:-
Enter n:
3
Generated no=25
Cube of 25 = 15625
Square of 25 = 625
Generated no=45
Cube of 45 = 91125
Square of 45 = 2025
Generated no=9
Cube of 9 = 729
Square of 9 = 81
*/