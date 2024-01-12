import java.util.Scanner;
public class Greater
{
    public static void main(String[] args)
    {
        int a,b,c;
        Scanner s=new Scanner(System.in);
        System.out.println("Enter a,b,c:");
        a=s.nextInt();
        b=s.nextInt();
        c=s.nextInt();
        int ans=(a>b)?a:(b>c)?b:c;
        System.out.println("Answer="+ans);
        s.close();
    }    
}
