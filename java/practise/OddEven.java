import java.util.Scanner;
public class OddEven
{
    public static void main(String[] args)
    {
        try (Scanner s = new Scanner(System.in))
        {
            System.out.println("Enter n:");
            int a=s.nextInt();
            if(a%2==0)
                System.out.println("Even");
            else
                System.out.println("Odd");
        }
    }
}
