class BoxIn
{
    static double l,b,h;
}
public class BoxLBH
{
    public static void main(String[] args)
    {
        int a;
        BoxIn obj;
        obj=new BoxIn();
        obj.l=10;
        obj.b=20;
        obj.h=30;
        System.out.println("l="+obj.l+"\tb="+obj.b+"\th="+obj.h);
        System.out.println(obj.l+obj.b+obj.h);
    }
}