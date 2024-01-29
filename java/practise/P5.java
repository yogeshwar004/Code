class Box
{
    double l,b,h;
    double volume()
    {
        return (l*b*h);
    }
}
public class P5 extends Box
{
    String color;
    public static void main(String[] args)
    {
        Box o;
        o=new P5();
        o.l=10;
        o.b=20;
        o.h=30;
        o=new P5();
        o.color="kdnnd";
    }
}
