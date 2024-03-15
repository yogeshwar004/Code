import java.util.Scanner;

enum Car
{
    Rolls_Royce,BMW,Audi,Ferrari;
}

public class Enumeration
{
    public static void main(String[] args)
    {
        String s;
        Scanner sc=new Scanner(System.in);
        Car a[]=Car.values();
        System.out.println("Cars are");
        for (Car x:a)
        {
            System.out.println(x);    
        }
        System.out.println("Enter Car Name:");
        s=sc.nextLine();
        try
        {
            Car ap=Car.valueOf(s);
            System.out.println("Car Found "+ap);
        }
        catch(Exception e)
        {
            System.out.println(s+" Value not found");
        }
        sc.close();
    }
}