import java.util.Scanner;

class Box
{
    double l,b,h;
    double volume()
    {
        return l*b*h;
    }
    void area()
    {
        double area=2*(l*b+b*h+h*l);
        System.out.println("Area="+area);
    }
}
public class Areaboxusingmethod
{
    public static  void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        Box obj=new Box();
        System.out.println("Enter l b h:");
        obj.l=s.nextDouble();
        obj.b=s.nextDouble();
        obj.h=s.nextDouble();
        System.out.println("Volume="+obj.volume());
        obj.area();
        s.close();
    }
}
