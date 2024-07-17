abstract class Shape
{
    abstract void calculateArea();
    abstract void calculatePerimeter();
}
class Circle extends Shape
{
    double r;
    Circle(double r)
    {
        this.r=r;
    }
    void calculateArea()
    {
        System.out.println("Area of Circle="+(Math.PI*r*r));
    }
    void calculatePerimeter()
    {
        System.out.println("Perimeter of Circle="+(2*Math.PI*r));
    }
}
class Triangle extends Shape
{
    double a,b,c,s;
    Triangle(double a,double b,double c)
    {
        this.a=a;
        this.b=b;
        this.c=c;
    }
    
    void calculateArea()
    {
        s=(a+b+c)/2;
        System.out.println("Area of Triangle="+(Math.sqrt(s*(s-a)*(s-b)*(s-c))));
    }
    void calculatePerimeter()
    {
        System.out.println("Perimeter of Triangle="+(s*2));
    }
}
public class AreaPerimeter
{
    public static void main(String[] args)
    {
        Circle c=new Circle(5);
        c.calculateArea();
        c.calculatePerimeter();
        Triangle t=new Triangle(10,20,15);
        t.calculateArea();
        t.calculatePerimeter();
    }
}
