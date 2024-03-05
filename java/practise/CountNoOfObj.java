
public class CountNoOfObj
{
    static int count;
    CountNoOfObj()
    {
        count++;
    }
    public static void main(String[] args)
    {
        CountNoOfObj obj;
        obj=new CountNoOfObj();
        obj=new CountNoOfObj();
        obj=new CountNoOfObj();
        System.out.println("Number of Objects are="+count);
    }
}