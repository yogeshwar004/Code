public class ThreadD
{
    public static void main(String[] args)
    {
        Thread t=Thread.currentThread();
        System.out.println("Current Thread is"+t);
        t.setName("My thread");
        System.out.println("After Changing"+t);
        System.out.println("Name of the Thread:"+t.getName());
        for(int i=5;i>=0;i--)
        {
            System.out.println(i);
            try
            {
                Thread.sleep(10000);
            }
            catch(Exception e)
            {
                System.out.println("Main thread interrupted");
            }
        }
    }
}
