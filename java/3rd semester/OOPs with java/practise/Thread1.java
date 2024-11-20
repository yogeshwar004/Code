public class Thread1 implements Runnable
{
    Thread t;
    Thread1()
    {
        t=new Thread(this,"Child Thread");
        System.out.println("Child thread is "+t);
        t.start();
    }
    public void run()
    {
        try
        {
            for(int i=5;i>=0;i--)
            {
                System.out.println("Child Thread i="+i);
                Thread.sleep(1000);
            }
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }

        System.out.println("Main Thread Exiting....");
    }
    public static void main(String[] args)
    {
        Thread1 t1=new Thread1();
        try
        {
            for(int i=5;i>=0;i--)
            {
                System.out.println("Main Thread i="+i);
                Thread.sleep(1000);
            }
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }

        System.out.println("Main Thread Exiting....");
    }    
}
