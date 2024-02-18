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
    public class run()
    {
        int i=0;
        whiile(true)
            obj.put(++x);
    }
}
public class P1
{
    public static void main(String[] args)
    {
            
    }
}