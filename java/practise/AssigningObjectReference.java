public class AssigningObjectReference
{
    int x,y;
    public static void main(String[] args)
    {
        int a=5;
        int b=a;
        AssigningObjectReference obj=new AssigningObjectReference();
        AssigningObjectReference obj1=obj;
        obj1.x=100;
        System.out.println("obj1.x="+obj1.x);
    }
}
