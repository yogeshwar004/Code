
public class MethodOverridingAdd
{
    void add(int a,int b)
    {
        int sum=a+b;
        System.out.println("Sum="+sum);
    }
    void add(int a,int b,int c)
    {
        int sum=a+b+c;
        System.out.println("Sum="+sum);
    }
    void add(double a,double b)
    {
        double sum=a+b;
        System.out.println("Sum="+sum);
    }
    public static void main(String[] args)
    {
        MethodOverridingAdd obj=new MethodOverridingAdd();
        obj.add(56.7, 78.5);
        obj.add(10, 20);
        obj.add(5, 6, 7);    
    }
}
/*
Output:-
Sum=135.2
Sum=30
Sum=18
*/