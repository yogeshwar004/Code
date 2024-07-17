import java.util.Scanner;

class Example
{
    Scanner s=new Scanner(System.in);
    int x;
    public int y;
    protected int z;
    private int p;
}
class Demo extends Example
{
    public void setdata()
    {
        x=s.nextInt();
        y=s.nextInt();
        z=s.nextInt();
        //p=s.nextInt();
    }
    public void display()
    {
        System.out.println("x="+x+"\ny="+y+"\nz="+z+"\np="/*+p*/);
    }
}
public class Inheritance
{
    public static void main(String[] args)
    {
        Demo e=new Demo();
        e.setdata();
        e.display();        
    }
}
