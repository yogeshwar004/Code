import java.util.Scanner;
public class RecursionFibo
{
    static int fibo(int x)
    {
        if(x==0)
            return 0;
        else if(x==1)
            return 1;
        else
            return (fibo(x-1)+fibo(x-2));
    }
    public static void main(String[] args)
    {
        //Scanner s=new Scanner(System.in);
        //System.out.println("Enter number of terms:");
        //int n=s.nextInt();
        int i=0,c,n=5;
        System.out.println("Fibonacci series is:");
        for(c=1;c<=n;c++)
        {
            System.out.println(fibo(i));
            i++;
        }
    }
}
