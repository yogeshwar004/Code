import java.util.Scanner;
class PException extends Exception
{
    PException(String msg)
    {
        super(msg);
    }
}
public class ExceptionHandling
{
    static void divide(double a,double b)throws PException
    {
        if(b==0)
            throw new PException("Division by zero is not possible");
        double c=a/b;
        System.out.println("c="+c);
    }
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the value of x and y:");
        double x=s.nextDouble();
        double y=s.nextDouble();
        try
        {
            divide(x,y);
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        finally
        {
            System.out.println("This is finally block");
        }
    }
}