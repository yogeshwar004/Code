import java.util.Scanner;
public class Calculator
{
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        int res=0;
        System.out.println("Enter a and b:");
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        int b=s.nextInt();
        System.out.println("Enter Operator:");
        char op=s.next().charAt(0);
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
                {
                    res=a/b;
                    break;
                }
                else
                {
                    System.out.println("Invalid Input....\nZeroDivisionError");
                }
            default:
                System.out.println("Invalid Input....");
        }
        System.out.println("Result="+res);
        s.close();
    }
}
