import java.util.Scanner;

public class Factorial
{
    int fact(int n)
    {
        if(n==0)
            return 1;
        else
            return n*(fact(n-1));
    }
    public static void main(String[] args)
    {
        Factorial f=new Factorial();
        Scanner s=new Scanner(System.in);
        System.out.println("Enter n:");
        int n=s.nextInt();
        int ans=f.fact(n);
        System.out.println(n+"! is:"+ans);
        s.close();
    }  
}