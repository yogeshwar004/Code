import java.util.Scanner;

public class VolumeRecConstructor
{
    double l,b,h;
    VolumeRecConstructor(double l,double b,double h)
    {
        this.l=l;
        this.b=b;
        this.h=h;
    }
    double volume()
    {
        return l*b*h;
    }
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        double l=s.nextDouble();
        double b=s.nextDouble();
        double h=s.nextDouble();
        VolumeRecConstructor obj=new VolumeRecConstructor(l,b,h);
        System.out.println("Volume="+obj.volume());
    }
}
