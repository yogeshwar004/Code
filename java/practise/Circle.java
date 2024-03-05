//Passing Object As A Parameter
/*public class Circle
{
    double r;
    Circle(double r)
    {
        this.r=r;
    }
    Circle compare(Circle c2)
    {
        if(this.r>c2.r)
            return this;
        return c2;
    }
    public static void main(String[] args)
    {
        Circle obj=new Circle(10);
        Circle obj1=new Circle(20);
        Circle obj2=obj.compare(obj1);
        System.out.println("Largest Circle of radius="+obj2.r);
    }
}
*/

import javax.crypto.Cipher;

/**
 * Circle
 */
public class Circle
{
    double l,b,h;
    public Circle(double l,double b,double h)
    {
        this.l=l;
        this.b=b;
        this.h=h;
    }
    Circle(Circle obj)
    {
        l=obj.l;//deep copy
        b=obj.b;//deep copy
        h=obj.h;//deep copy

    }
    public static void main(String[] args)
    {
        Circle c1=new Circle(10,20,30);
        Circle c2=new Circle(c1);
        String s1="hello";
        String s2="hello";
        System.out.println(s1.equals(s2));
    }
}