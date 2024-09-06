import java.util.Random;
import java.util.Scanner;
public class QuickSortAlgorithm
{
    static int count=0;
    void Quicksort(int a[],int l,int r)
    {
        if(l<r)
        {
            int s=HoarsePartition(a,l,r);
            Quicksort(a,l,s-1);
            Quicksort(a,s+1,r);
        }
    }
    int HoarsePartition(int a[],int l,int r)
    {
        int pivot=a[l],i=l,j=r+1,temp=0;
        do
        {
            do
            {
                i++;
                count++;
            }while(i<r&&a[i]<pivot);
            do
            {
                j--;
                count++;
            }while(j>l&&a[j]>pivot);
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }while(i<j);
        temp=a[j];
        a[j]=a[l];
        a[l]=temp;
        return j;
    }
    public static void main(String[] args)
    {
        int i=0;
        Scanner s=new Scanner(System.in);
        Random r=new Random();
        System.out.println("Enter the size of array:");
        int n=s.nextInt();
        int a[]=new int[n];
        System.out.println("Before Sorting:\n");
        for(i=0;i<n;i++)
        {
            a[i]=r.nextInt(1000);
            System.out.print(a[i]+"\t");
        }
        QuickSortAlgorithm q=new QuickSortAlgorithm();
        q.Quicksort(a,0,n-1);
        System.out.println("\nAfter Sorting:");
        for(i=0;i<n;i++)
        {
            System.out.print(a[i]+"\t");
        }
        //s.close();
    }
}