class Buffer
{
    int x;
    synchronized void put(int i)
    {
        x=i;
        System.out.println("Producer i="+x);
    }
    synchronized void get()
    {
        System.out.println("Consumer i="+x);
    }
}
class Producer implements Runnable
{
    Buffer obj;
    Thread t;

    Producer(Buffer ob)
    {
        ob=obj;
        t=new Thread(this,"Producer");
        t.start();    
    }
    public void run()
    {
        int i=0;
        while(true)
            obj.put(++i);
    }
}
public class ProducerConsumer1
{
    public static void main(String[] args)
    {
        Buffer b=new Buffer();
        Producer p=new Producer(b);
    }
}