class Shape
{
    void draw()
    {
        System.out.println("Drawn Shape");
    }
    void erase()
    {
        System.out.println("Erase Shape");
    }
}
class Circle extends Shape
{
    void draw()
    {
        System.out.println("Drawn Circle");
    }
    void erase()
    {
        System.out.println("Erase Circle");
    }
}
class Triangle extends Shape
{
    void draw()
    {
        System.out.println("Drawn Triangle");
    }
    void erase()
    {
        System.out.println("Erase Triangle");
    }
}
class Square extends Shape
{
    void draw()
    {
        System.out.println("Drawn Square");
    }
    void erase()
    {
        System.out.println("Erase Square");
    }
}
public class ThreeD
{
    public static void main(String[] args)
    {
        Shape obj;
        obj=new Circle();
        obj.draw();
        obj.erase();
        obj=new Triangle();
        obj.draw();
        obj.erase();
        obj=new Square();
        obj.draw();
        obj.erase();
    }
}
