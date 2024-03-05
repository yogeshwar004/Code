public class ConstructorOverloading
{
    double l,b,h;
    ConstructorOverloading()
    {
        System.out.println("Volume="+(l*b*h));//no arguments
    }
    ConstructorOverloading(double a)
    {
        l=b=h=a;
    }
    ConstructorOverloading(double x,double y,double z)
    {
        l=x;
        b=y;
        h=z;
    }
    void volume()
    {
        System.out.println("Volume="+(l*b*h));
    }
    public static void main(String[] args)
    {
        ConstructorOverloading obj;
        obj=new ConstructorOverloading(10);
        obj.volume();
        obj=new ConstructorOverloading(10,20,30);
        obj.volume();
    }
}
