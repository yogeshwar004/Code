import java.util.Scanner;
class Example
{
    public static void main(String args[])
    {
        int i;
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the number of Elements:");
        int n=s.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the array elements:");
        for(i=0;i<n;i++)
            a[i]=s.nextInt();
        System.out.println("Array Elements are:");
        for(i=0;i<n;i++)
            System.out.println(a[i]);
    }
}