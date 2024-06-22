package package10.mypack;
import java.util.Scanner;
public class Example
{
	Scanner s=new Scanner(System.in);
	int x;
	private int y;
	public int z;
	protected int p;
	public void read()
	{
		x=s.nextInt();
		y=s.nextInt();
		z=s.nextInt();
		p=s.nextInt();
	}
	public void display()
	{
		System.out.println("x="+x+"y="+y+"z="+z+"p="+p);
	}
}