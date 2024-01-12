import java.util.Scanner;
//java program to find sum of array elements,maximum element of an array
public class Maximumelement
{
    public static void main(String[] args)
    {
        int i,sum=0;
        try (Scanner s = new Scanner(System.in)) {
            System.out.println("Enter number of Elements:");
            int n=s.nextInt();
            int a[]=new int[n];
            System.out.println("Enter the Array Elements:");
            for(i=0;i<n;i++)
                a[i]=s.nextInt();
            System.out.println("Array Elements are");
            for(i=0;i<n;i++)
            {
                System.out.println(a[i]+"\t");
                sum=sum+a[i];
            }
            System.out.println("SUM="+sum);
            for(i=1;i<n;i++)
                if(a[0]<a[i])
                    a[0]=a[i];
            System.out.println("Maximum Element="+a[0]);
            s.close();
        }
    }
}
