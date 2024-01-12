public class Sumusingforeach
{
    public static void main(String[] args)
    {
        int sum=0,count=0;
        int a[]={10,20,67,32,90,12,87,54,92,100};
        for(int x:a)
        {
            sum=sum+x;
            count++;
            if(count==4)
                break;
        }
        System.out.println("Sum="+sum);
    }    
}
