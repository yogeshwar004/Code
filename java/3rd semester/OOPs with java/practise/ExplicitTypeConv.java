import java.util.Scanner;

public class ExplicitTypeConv
{
    public static void main(String[] args)
    {
        /*int a=10;
        double b=(double)a;
        System.out.println(b);
        char c='a';
        int i=c;
        System.out.println(i);
        float f=c;
        System.out.println(f);*/
        Scanner s=new Scanner(System.in);
        System.out.println("Enter size of array:");
        int n=s.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
            a[i]=s.nextInt();
        System.out.println(a);
    }
}