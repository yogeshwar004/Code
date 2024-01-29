final class A
{
    final int x;
    A()
    {
        x=10;
    } 
    final void display()
    {
        //x=100;//error-final variablr cannot be modified
        System.out.println("x="+x);
    }
}
/*class B extends A//error
{
    int y;
    void display()//error
    {
        System.out.println("Y has Garbage Value");
    }
}*/
public class FinalKeyword
{
    public static void main(String[] args)
    {
        A o;
        o=new A();
        o.display();
    }
}
