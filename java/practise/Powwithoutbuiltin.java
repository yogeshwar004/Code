import java.util.Scanner;

public class Powwithoutbuiltin
{
    
    double pow(double x,double n)
    {
        if(n==0)
            return 1;
        else if(n>0)
            return x*pow(x,n-1);
        else
        {
            return (1/pow(x,(n/-1)));
        }
    }
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        Powwithoutbuiltin p=new Powwithoutbuiltin();
        System.out.println("Enter the variable and Power:");
        double x=s.nextDouble();
        double n=s.nextDouble();
        double a=p.pow(x,n);
        System.out.println("Ans="+a);
        s.close();
    }    
}