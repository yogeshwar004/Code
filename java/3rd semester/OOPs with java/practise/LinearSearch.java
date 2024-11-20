import java.util.Scanner;
public class LinearSearch
{
    int search(int a[],int n,int key)
    {
        int i=0;
        while (i<n && a[i]!=key)
        {
            i++;
        }
        if(i<n)
            return i+1;
        else
            return -1;
    }
    public static void main(String[] args)
    {
        Scanner s =new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n=s.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the array elements:");
        for (int i = 0; i < a.length; i++)
        {
            a[i]=s.nextInt();
        }
        System.out.println("Enter the key elements:");
        int key=s.nextInt();
        LinearSearch l=new LinearSearch();
        int res=l.search(a,n,key);
        if(res!=-1)
        {
            System.out.println("Key found at "+res);
        }
    }
}