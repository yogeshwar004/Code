import java.util.Scanner;

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
        System.out.println("Area Of Circle="+(Math.PI*r*r));
    }
    void calculatePerimeter()
    {
        System.out.println("Perimeter Of Circle="+(2*Math.PI*r));
    }
}
class Triangle extends Shape
{
    double s,a,b,c;
    Triangle(double a,double b,double c)
    {
        this.a=a;
        this.b=b;
        this.c=c;
    }
    void calculateArea()
    {
        s=(a+b+c)/2;
        System.out.println("Area Of Triangle="+(Math.sqrt(s*(s-a)*(s-b)*(s-c))));
    }
    void calculatePerimeter()
    {
        System.out.println("Area of Triangle="+(s*2));
    }
}
public class AreaPerimeterOfCircleTriangle6
{
    static Scanner s=new Scanner(System.in);
    public static void main(String[] args)
    {
        int w;
        while (true)
        {
            System.out.println("Enter your choice\n1. Circle\n2. Triangle\n3. Exit");
            w=s.nextInt();
            switch(w)
            {
                case 1:
                    System.out.println("Enter radius");
                    int r=s.nextInt();
                    Circle ci=new Circle(r);
                    ci.calculateArea();
                    ci.calculatePerimeter();
                    break;
                case 2:
                    System.out.println("Enter a,b,c:");
                    int a=s.nextInt();
                    int b=s.nextInt();
                    int c=s.nextInt();
                    Triangle t=new Triangle(a,b,c);
                    t.calculateArea();
                    t.calculatePerimeter();
                    break;
                case 3:System.exit(0);
                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }    
    }
}
