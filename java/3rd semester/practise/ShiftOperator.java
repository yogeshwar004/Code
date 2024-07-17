public class ShiftOperator
{
    public static void main(String[] args)
    {
        int a=8;
        int resl=a<<2;
        System.out.println("Left Shift Operator="+resl);
        int ressr=a>>3;
        System.out.println("Right Shift Operator="+ressr);
        int resur=a>>>3;
        System.out.println("Right Shift Operator="+resur);
        int res=2;
        res+=a;
        System.out.println(res);
    }
}
