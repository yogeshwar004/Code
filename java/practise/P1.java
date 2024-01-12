import java.util.Scanner;

class Employee
{
    Scanner s=new Scanner(System.in);
    String eid,name;
    double salary;
    void read()
    {
        System.out.println("Enter Id,name, and salary");
        eid=s.nextLine();
        name=s.nextLine();
        salary=s.nextDouble();
    }
    void display()
    {
        System.out.println(eid+"\t"+name+"\t"+salary);
    }
    void raisesalary(double percentage)
    {
        salary=salary+(percentage/100)*salary;
    }
}
public class P1
{
    public static void main(String[] args)
    {
        try (Scanner s = new Scanner(System.in)) {
            System.out.println("Enter Number of employee:");
            int n=s.nextInt();
            Employee e[]=new Employee[n];
            int i;
            for(i=0;i<n;i++)
            {
                e[i]=new Employee();
                e[i].read();
            }
            System.out.println("EmpId\tEmpName\tEmpSalary");
            for(i=0;i<n;i++)
                e[i].display();
            System.out.println("Enter the percentage to be increase:");
            double per=s.nextDouble();
            System.out.println("The salary after raising");
            for(i=0;i<n;i++)
            {
                e[i].raisesalary(per);
                e[i].display();
            }
            s.close();
        }
    }
}
