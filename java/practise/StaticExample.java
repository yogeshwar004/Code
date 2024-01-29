public class StaticExample
{
    static int num=100;
    static String str="GeeksForGeeks";
    static void display()
    {
        System.out.println("Static number is="+num);
        System.out.println("Static string is ="+str);
    }
    void nonstatic()
    {
        display();
    }
    public static void main(String[] args) {
        //StaticExample o=new StaticExample();
        //4o.nonstatic();
        display();
    }
}