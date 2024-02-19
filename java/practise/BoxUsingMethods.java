import java.util.Scanner;

public class BoxUsingMethods
{
    double l,b,h;
    double volume()
    {
        double v=l*b*h;
        return v;
    }
    void area()
    {
        double a=2*(l*b+b*h+h*l);
        System.out.println("Area="+a);
    }
    public static void main(String[] args)
    {
        try
        {
            Scanner s=new Scanner(System.in);
            BoxUsingMethods obj=new BoxUsingMethods();
            System.out.println("Enter l,b,h:");
            obj.l=s.nextDouble();
            obj.b=s.nextDouble();
            obj.h=s.nextDouble();
            double v=obj.volume();
            System.out.println("Volume="+v);
            obj.area();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }   
}
/*
Output:-
Enter l,b,h:
10
20
30
Volume=6000.0
Area=2200.0
 */