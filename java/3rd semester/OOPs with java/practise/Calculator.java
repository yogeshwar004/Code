import java.util.Scanner;

public class Calculator
{
    public static void main(String[] args)
    {
        double a,b,res=0;
        char op;
        System.out.println("Enter a and b:");
        Scanner s=new Scanner(System.in);
        a=s.nextDouble();
        b=s.nextDouble();
        System.out.println("Enter the operator to be choose:");
        op=s.next().charAt(0);
        switch(op)
        {
            case '+':
                res=a+b;
                break;
            case '-':
                res=a-b;
                break;
            case '*':
                res=a*b;
                break;
            case '/':
                if(b!=0)
                    res=a/b;
                else
                {
                    System.err.println("ZeroDivisionError: Invalid Denominator");
                    System.exit(0);
                }
                break;
            default:
                System.err.println("Invalid Input");
                break;
        }
        System.out.println("Result\n"+a+op+b+"="+res);
    }    
}