import java.util.Scanner;
public class Shopping 
{
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the total cost:");
        double cost=s.nextDouble();
        if(cost<2000)
            cost=cost-(5.00/100)*cost;
        else if(cost>2000&&cost<=5000)
            cost=cost-(25.00/100)*cost;
        else if(cost>5000&&cost<=10000)
            cost=cost-(35.00/100)*cost;
        else
            cost=cost-(50.00/100)*cost;
        System.out.println("The cost after Discount:");
        System.out.println(cost);
        s.close();
    }
}
