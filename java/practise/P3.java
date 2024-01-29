
class P1
{
    P1()
    {
        System.out.println("Constructor p1 ");
    }
    public void display()
    {
        System.out.println("Display super");
    }
}
public class P3 extends P1
{
    P3()
    {
        super();
        System.out.println("Constructor p3 ");
    }
    public void display()
    {
        super.display();
        System.out.println("Display derived");
    }
    public static void main(String[] args)
    {
        P3 p;
        P1 p1=new P1();
        p1.display();
        p=new P3();
        p.display();
    }
}