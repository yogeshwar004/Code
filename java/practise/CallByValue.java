//import java.util.Scanner;

public class CallByValue
{
    int x,y;
    
    void change(int a,int b)
    {
        a=10;
        b=20;
    }
    public static void main(String[] args)
    {
        CallByValue e=new CallByValue();
        //Scanner s=new Scanner(System.in);
        //int a=s.nextInt();
        //int b=s.nextInt();
        e.change(50,100);
    }
}
