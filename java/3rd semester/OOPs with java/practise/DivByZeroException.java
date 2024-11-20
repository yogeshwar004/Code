import java.util.Scanner;
class PException extends Exception
{
    PException(String e)
    {
        super(e);
    }
}
public class DivByZeroException
{
    static void divide(double a,double b)throws PException
    {
        if(b==0)
            throw new PException("Division by zero is not poosible");
        double c=(a/b);
        System.out.println("c="+c);
    }
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the value of x and y:");
        double x=s.nextInt();
        double y=s.nextInt();
        try
        {
            divide(x,y);
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
        finally
        {
            System.out.println("This is finally block");
        }
    }
}
