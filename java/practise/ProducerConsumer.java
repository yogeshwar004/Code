
class Buffer
{
    int i,flag=0;
    synchronized void put(int x)
    {
        try
        {
            if(flag==1)
                wait();
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
        i=x;
        System.out.println("Produced "+i);
        flag=1;
        notify();
    }
    synchronized void get()
    {
        try
        {
            if(flag==0)
                wait();
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
        System.out.println("Consumed "+i);
        flag=0;
        notify();
    }
}
class Producer implements Runnable
{
    Thread t;
    Buffer b;
    Producer(Buffer x)
    {
        b=x;
        t=new Thread(this,"Producer");
        t.start();
    }
    public void run()
    {
        int i=0;
        while (true)
        {
            b.put(i++);
        }
    }
}
class Consumer implements Runnable
{
    Thread t;
    Buffer b;
    Consumer(Buffer x)
    {
        b=x;
        t=new Thread(this,"COnsumer");
        t.start();
    }
    public void run()
    {
        while(true)
            b.get();
    }
}

public class ProducerConsumer {

    @SuppressWarnings("usused")
    public static void main(String[] args) {
        
        try
        {
            Buffer b=new Buffer();
            Producer p=new Producer(b);
            Consumer c=new Consumer(b);
            
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
    }
}