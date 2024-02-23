/**
 * ExceptionTest2
 */
/*public class ExceptionTest2 {

    public static void main(String[] args) {
        try{
            int ary[]={10,20,30};
            int temp=ary[4];
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println(e.getMessage());
        }
        catch(Exception e2)
        {
            System.out.println("Some exception");
        }
    }
}*/
/**
 * ExceptionTest2
 */
public class ExceptionTest2 {

    static void show()
    {
        try{
            System.out.println("inside try");
            return;
        }
        finally{
            System.out.println("inside FINALLy");
        }
    }
    public static void main(String[] args) {
        show();
    }
}