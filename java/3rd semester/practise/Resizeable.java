import java.util.Scanner;

interface InnerResizeable
{
    void resizeWidth(int width);
    void resizeHeight(int height);
}
public class Resizeable implements InnerResizeable
{
    int width,height;
    Resizeable(int width,int height)
    {
        this.width=width;
        this.height=height;
    }
    public void resizeWidth(int width)
    {
        this.width=width;
    }
    public void resizeHeight(int height)
    {
        this.height=height;
    }
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        Resizeable robj=new Resizeable(10,20);
        System.out.println("Enter width and height:");
        int width=s.nextInt();
        int height=s.nextInt();
        System.out.println("Before Resize\nWidth="+robj.width+"\tHeight="+robj.height);
        robj.resizeWidth(width);
        robj.resizeHeight(height);
        System.out.println("After Resize\nWidth="+robj.width+"\tHeight="+robj.height);
    }
}