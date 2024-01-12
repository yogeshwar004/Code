import java.util.Scanner;

public class Initializationofarray
{
    public static void main(String args[])
    {
        int i;
        try (Scanner s = new Scanner(System.in)) {
            System.out.println("Enter the Number of elements:");
            int n=s.nextInt();
            int a[]=new int[n];
            System.out.println("Enter the Array Elements:");
            for (i=0;i<n;i++)
                a[i]=s.nextInt();
            System.out.println("Array Elements are:");
            for(i=0;i<n;i++)
                System.out.println(a[i]);
            s.close();
        }
    }
}