import java.util.Scanner;
class Employee
{
    String eid,ename;
    double salary;
    void read()
    {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter ID,name, salary");
        eid=s.nextLine();
        ename=s.nextLine();
        salary=s.nextDouble();
        s.close();
    }
    void display()
    {
        System.out.println(eid+"\t"+ename+"\t"+salary);
    }
    void raisesalary(double percentage)
    {
        salary=salary+(percentage/100)*salary;
    }
}
public class Salary
{
    public static void main(String args[])
    {
        try (Scanner s = new Scanner(System.in)) {
            System.out.println("Enter the number of employee:");
            int n=s.nextInt();
            Employee e[]=new Employee[n];
            int i;
            for(i=0;i<n;i++)
            {
                e[i]=new Employee();
                e[i].read();
            }
            System.out.println("EmpID\tEmpName\tEmpSalary");
            for(i=0;i<n;i++)
            {
                e[i].display();
            }
            System.out.println("Enter Percentage to increase:");
            double per=s.nextDouble();
            for(i=0;i<n;i++)
            {
                e[i].raisesalary(per);
            }
            s.close();
        }
    }
}