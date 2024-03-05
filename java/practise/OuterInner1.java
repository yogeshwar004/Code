class Outer
{
    private int x=10;
    class Inner
    {
        private int y=20;
        void display()
        {
            System.out.println("Inner display\nx="+x+"\ty="+y);
        }
    }
    void display()
    {
        Inner i=new Inner();
        System.out.println("Outer display\ny="+i.y);
        //System.out.println("y="+y);
    }
}
public class OuterInner1
{
    public static void main(String[] args)
    {
        Outer o=new Outer();
        Outer.Inner obj=o.new Inner();
        o.display();
        obj.display();
    }
}
