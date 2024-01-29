import java.util.Scanner;

public class RecursionGCD
{
    static int gcd(int m,int n)
    {
        if(n==0)
            return m;
        return gcd(n, m%n);
    }
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter m and n:");
        int m=s.nextInt();
        int n=s.nextInt();
        System.out.println("The GCD of "+m+" and "+n+" is="+(gcd(m,n)));
    }
}
