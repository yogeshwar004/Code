public class GFG
{
    static int a=40;
    int b=50;
    void simpledisplay()
    {
        System.out.println(a);
        System.out.println(b);
        //staticDisplay();
    }
    static void staticDisplay()
    {
        System.out.println(a);
    }    
    public static void main(String[] args) {
        GFG o=new GFG();
        o.simpledisplay();
        staticDisplay();
    }
}