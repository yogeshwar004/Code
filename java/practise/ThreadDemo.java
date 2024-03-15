public class ThreadDemo
{
    public static void main(String[] args)
    {
        Thread t=Thread.currentThread();
        System.out.println("Current Thread is "+t);
        t.setName("My thread");
        System.out.println("After changing "+t);
        System.out.println("New thread name is "+t.getName());
        for(int i=5;i>=0;i--)
        {
            System.out.println(i);
            try
            {
                Thread.sleep(1000);
            }
            catch (Exception e)
            {
                System.out.println("Main Thread Interrupted");
            }
        }
    }    
}
