class Outer
{
    private int x;
    class Inner
    {
        private int y;
        void display()
        {
            System.out.println("x="+x+"\ty="+y);
        }
    }
    void display()
    {
        Inner i=new Inner();
        i.display();
        System.out.println("y="+i.y);
        //System.out.println("y="+y);//error
    }
}
public class NestedInner
{
    public static void main(String[] args)
    {
        Outer o=new Outer();
        Outer.Inner ob=o.new Inner();
        o.display();
        ob.display();
    }
}
