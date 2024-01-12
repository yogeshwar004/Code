class Box
{
    double l,b,h;
}
public class Areaboxinitialized
{
    public static void main(String [] args)
    {
        Box obj;
        obj=new Box();
        obj.l=10;
        obj.b=20;
        obj.h=30;
        double volume=obj.l*obj.b*obj.h;
        System.out.println(volume);
    }
}
