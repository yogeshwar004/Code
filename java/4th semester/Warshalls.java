import java.util.Scanner;
public class Warshalls
{
    void warshalls(int a[][],int n)
    {
        for(int k=0;k<n;k++)
        {
            System.out.print("\nR("+(k+1)+")=");
            for(int i=0;i<n;i++)
            {
                System.out.println();
                for(int j=0;j<n;j++)
                {
                    a[i][j]=(a[i][j]!=0||(a[i][k]!=0&&a[k][j]!=0))?1:0;
                    System.out.print(a[i][j]+"\t");
                }
            }
        }
    }
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        Warshalls w=new Warshalls();
        System.out.println("Enter the number of nodes:");
        int n=s.nextInt();
        int a[][]=new int[n][n];
        System.out.println("Enter the Transitive Closure:");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=s.nextInt();
            }
        }
        w.warshalls(a,n);
        s.close();
    }
}
