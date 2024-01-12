import java.util.Scanner;

class Staff
{
    Scanner s=new Scanner(System.in);
    String sid,name,phno,salary;
    void read()
    {
        System.out.println("Enter Id,name,phno,salary:");
        sid=s.nextLine();
        name=s.nextLine();
        phno=s.nextLine();
        salary=s.nextLine();
    }
    void display()
    {
        System.out.print(sid+"\t"+name+"\t"+phno+"\t"+salary+"\t");
    }
}
class Teaching extends Staff
{
    String domain,publication;
    void read()
    {
        super.read();
        System.out.println("Enter domain and publication:");
        domain=s.nextLine();
        publication=s.nextLine();
    }
    void display()
    {
        super.display();
        System.out.println(domain+"\t"+publication+"\t");
    }
}
class Technical extends Staff
{
    String skills;
    void read()
    {
        super.read();
        System.out.println("Enter skills:");
        skills=s.nextLine();
    }
    void display()
    {
        super.display();
        System.out.println(skills+"\t");
    }
}
class Contract extends Staff
{
    String period;
    void read()
    {
        super.read();
        System.out.println("period:");
        period=s.nextLine();
    }
    void display()
    {
        super.display();
        System.out.println(period+"\t");
    }
}
public class HierarchicalInheritance
{
    public static void main(String[] args)
    {
        Staff s1;
        s1=new Teaching();
        s1.read();
        System.out.println("sid\tname\tphno\tsalary\tdomain\tpublication");
        s1.display();
        s1=new Technical();
        s1.read();
        System.out.println("sid\tname\tphno\tsalary\tskills\t");
        s1.display();
        s1=new Contract();
        s1.read();
        System.out.println("sid\tname\tphno\tsalary\tperiod\t");
        s1.display();

    }
}
