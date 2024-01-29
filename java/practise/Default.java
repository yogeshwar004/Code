
interface Alpha
{
    default void display()
    {
        System.out.println("Alpha Display method");
    }
}
interface Beta extends Alpha
{
    default void display()
    {
        Alpha.super.display();
        System.out.println("Beta Display method");
    }
}
class Example implements Beta
{
    int x,y;
    int add()
    {
        return (x+y);
    }
}
public class Default
{
    public static void main(String[] args)
    {
        Example a=new Example();
        a.display();    
    }
}
