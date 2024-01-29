
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
        System.out.println("x="+x+"\ny="+y);
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
        System.out.println("\tz="+z);
    }
}
public class InheritanceSetxyz 
{
    public static void main(String[] args)
    {
        Example e=new Example();
        e.setxy();
        e.displayxy();//e object data
        Demo d=new Demo();
        d.setxyz();
        d.displayxyz();//d object data
    }
}