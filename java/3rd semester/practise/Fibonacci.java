import java.util.Scanner;

public class Fibonacci
{
    static int fibo(int x)
    {
        if(x==0)
            return 0;
        else if(x==1)
            return 1;
        else
            return(fibo(x-1)+fibo(x-2));
    }
    public static void main(String[] args)
    {
        System.out.println("Enter number of Terms:");
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int c,i=0;
        System.out.println("The Fibonacci is");
        for(c=0;c<n;c++)
        {
            System.out.println(fibo(i));
            i++;
        }
    }
}
