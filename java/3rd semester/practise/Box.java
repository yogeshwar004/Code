public class Box
{
    double l,b,h;
    public static void main(String[] args)
    {
        //int a;
        Box obj;
        obj=new Box();
        obj.l=10;
        obj.b=20;
        obj.h=30;
        System.out.println("Class box Instance:\nl="+obj.l+"\nb="+obj.b+"\nh="+obj.h);
    }
}
/*
Output:
Class box Instance:
l=10.0
b=20.0
h=30.0 
*/