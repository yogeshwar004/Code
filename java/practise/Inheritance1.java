class Example
{
    int x,y;
    void setxy()
    {
        x=10;
        y=20;
    }
    void displayxy()
    {
        System.out.println("x="+x+",y="+y);
    }
}
class Demo extends Example
{
    int z;
    void setxyz()
    {
        x=100;
        y=200;
        z=300;
    }
    void displayxyz()
    {
        displayxy();
        System.out.println("z="+z);
    }
}
public class Inheritance1
{
    public static void main(String[] args)
    {
        Example eobj=new Example();
        eobj.setxy();
        System.out.println("E Object data");
        eobj.displayxy();
        Demo dobj=new Demo();
        dobj.setxyz();
        System.out.println("D object data");
        dobj.displayxyz();
    }
}