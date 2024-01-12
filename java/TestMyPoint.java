class MyPoint
{
    int x,y;
    MyPoint()
    {
        x=0;
        y=0;
    }
    MyPoint(int x,int y)
    {
        this.x=x;
        this.y=y;
    }
    void setxy(int x,int y)
    {
        this.x=x;
        this.y=y;
    }
    int[] getxy()
    {
        int a[]=new int[2];
        a[0]=x;
        a[1]=y;
        return a;
    }
    public String toString()
    {
        return "("+x+","+y+")";
    }
    double distance(int x,int y)
    {
        return Math.sqrt(Math.pow(this.x-x,2)+Math.pow(this.y-y, 2));
    }
    double distance()
    {
        return Math.sqrt(Math.pow(x,2)+Math.pow(y, 2));
    }
    double distance(MyPoint p2)
    {
        return Math.sqrt(Math.pow(x-p2.x,2)+Math.pow(y-p2.y, 2));
    }
}
public class TestMyPoint
{
    public static void main(String[] args)
    {
        MyPoint p1=new MyPoint();
        MyPoint p2=new MyPoint();
        int a[]=p1.getxy();
        System.out.println("p1 X="+a[0]+"\t,"+"\tp2 Y="+a[1]);
        p1.setxy(5, 6);
        System.out.println("Point p1="+p1);
        //System.out.println(p1);
        System.out.println("Point p2="+p2);
        //System.out.println(p2);
        System.out.println("Distance Between Point p1 and (2,3)is="+p1.distance(2, 3));
        System.out.println("Distance Between Point p1 to origin is="+p1.distance());
        System.out.println("Distance Between p1 and p2="+p1.distance(p2));
    }
}
