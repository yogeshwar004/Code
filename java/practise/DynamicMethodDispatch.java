class Figure
{
    double dim1,dim2;
    Figure(double a,double b)
    {
        dim1=a;
        dim2=b;
    }
    public void area()
    {
        System.out.println("Area not defined");
    }
}
class Rectangle extends Figure
{
    Rectangle(double a,double b)
    {
        super(a,b);
    }
    public void area()
    {
        System.out.println("Area of rectangle="+(dim1*dim2));
    }
}
class Triangle extends Figure
{
    Triangle(double a,double b)
    {
        super(a,b);
    }
    public void area()
    {
        System.out.println("Area of Triangle="+(0.5*dim1*dim2));
    }
}
public class DynamicMethodDispatch
{
    public static void main(String[] args)
    {
        Figure ref;
        ref=new Rectangle(10, 20);
        ref.area();
        ref=new Triangle(10, 20);
        ref.area();
    }
}
