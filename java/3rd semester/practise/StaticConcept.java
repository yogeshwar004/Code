public class StaticConcept
{
    static int y=10;
    public static void main(String[] args)
    {
        System.out.println("Static variable i="+Abc.i);
        //System.out.println("Same Class Static variable y="+y);
        //Abc.show();
        
    }
}
class Abc
{
    static int i=5;
    public static void show()
    {
        System.out.println("Hi");
        System.out.println("Outside Class Static variable i="+i);
    }
}