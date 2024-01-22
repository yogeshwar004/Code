interface Resizeable
{
    void resizeWidth(int width);
    void resizeHeight(int Height);    
}
public class Rectangle implements Resizeable
{
    int width,height;
    Rectangle(int width,int height)
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
        Rectangle robj=new Rectangle(10, 20);
        System.out.println("Before Resize:\nWidth="+robj.width+"\tHeight="+robj.height);
        robj.resizeWidth(100);
        robj.resizeHeight(200);
        System.out.println("After Resize:\nWidth="+robj.width+"\tHeight="+robj.height);
    }
}