import java.util.Scanner;
public class Variable
{
    int x;
    private int y;
    public int z;
    protected int p;
    public void read()
    {
        Scanner s=new Scanner(System.in);
        x=s.nextInt();
        y=s.nextInt();
        z=s.nextInt();
        p=s.nextInt();
    }
    public void display()
    {
        System.out.println("x="+x+"\ty="+y+"\yz="+z+"\tp="+p);
    }
}