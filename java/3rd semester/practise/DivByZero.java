import java.util.Scanner;

public class DivByZero
{
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter a and b:");
        int a=s.nextInt();
        int b=s.nextInt();
        int c=a/b;
        System.out.println("c="+c);
        int arr[]=new int[a];
        arr[10]=34;
        System.out.println("End of program");
    }
}
