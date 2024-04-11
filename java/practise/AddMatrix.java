import java.util.Scanner;

public class AddMatrix
{
    public static void main(String[] args)
    {
        
        if(args.length==0)
        {
            System.out.println("Invalid Input");
            System.exit(0);
        }
        int i,j,n=Integer.parseInt(args[0]);
        int a[][]=new int[n][n];
        int b[][]=new int[n][n];
        int c[][]=new int[n][n];
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the value of Matrix A:");
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j]=s.nextInt();
        System.out.println("Enter the value of Matrix B:");
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                b[i][j]=s.nextInt();
        System.out.println("Enter the value of Matrix A:");
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                c[i][j]=a[i][j]+b[i][j];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                System.out.print(c[i][j]+" ");
            System.out.println();
        }
        System.err.println("the");
    }
}
