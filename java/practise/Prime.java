import java.util.Scanner;

public class Prime
{
    public static void main(String[] args)
    {
        try (Scanner s = new Scanner(System.in)) {
            int num,flag=1,i;
            System.out.println("Enter Number:");
            num=s.nextInt();
            for(i=2;i<(num/2);i++)
                if(num%i==0)
                {
                    flag=0;
                    break;
                }
            if(flag==1)
                System.out.println("It is Prime Number....");
            else
                System.out.println("It is not Prime Number....");
            s.close();
        }
    }
}
