package program10.mypack;

import java.util.Scanner;

public class Example
{
    int x;
    private int y;
    public int z;
    protected int p;
    public void read()
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter x,y,z,p respectively:");
        x=s.nextInt();
        y=s.nextInt();
        z=s.nextInt();
        p=s.nextInt();
        s.close();
    }
    public void display()
    {
        System.out.println("\nDefault x="+x+"\nPrivate y="+y+"\nPublic z="+z+"\nProtected p="+p);
    }
}