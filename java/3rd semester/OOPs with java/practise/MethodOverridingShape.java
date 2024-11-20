public class MethodOverridingShape
{
    void area(float r)
    {
        float area=(float) (Math.PI*(Math.pow(r,2)));
        System.out.println("Area="+area);
    }
    void area(int r)
    {
        double area=Math.pow(r,2);
        System.out.println("Area="+area);
    }
    void area(int l,int b)
    {
        System.out.println("Area of Rectangle="+(l*b));
    }
    void area(double b,double h)
    {
        System.out.println("Area of Triangle="+(0.5*b*h));
    }
    public static void main(String[] args)
    {
        MethodOverridingShape obj=new MethodOverridingShape();
        obj.area(4);
    }
}