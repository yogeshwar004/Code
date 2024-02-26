class Outer
{
    private int x=10;
    class Inner
    {
        private int y=20;
        void display()
        {
            
            System.out.println("Inner Class\nx="+x+"\ty="+y);
        }
    }
    void display()
    {
        Inner i=new Inner();
        System.out.println("Outer display");
        i.display();
        System.out.println("y="+i.y);
    }
}
public class OuterInner
{
    public static void main(String[] args)
    {
        Outer o=new Outer();
        Outer.Inner i=o.new Inner();
        o.display();
        i.display();
    }
}
