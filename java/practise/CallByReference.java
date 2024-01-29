public class CallByReference
{
    int x,y;
    void change(CallByReference e)
    {
        //int temp=e.x
        //e.x=e.y;
        //e.y=temp;
        this.x=e.x;
        this.y=e.y;
    }
    public static void main(String[] args)
    {
        CallByReference e=new CallByReference();
        e.x=10;
        e.y=20;
        e.change(e);
    }
}
