import java.util.Scanner;
class Employee
{
    String eid,ename;
    double salary;
    void read()
    {
        try (Scanner s = new Scanner(System.in)) {
            System.out.println("Enter ID,name,salary");
            eid=s.nextLine();
            ename=s.nextLine();
            salary=s.nextDouble();
        }
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
public class Example1
{
    /**
     * @param args
     */
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of employee:");
        int n;
        n=s.nextInt();
        Employee e[]=new Employee[n];
        for(int i=0;i<n;i++)
        {
            e[i]=new Employee();
            e[i].read();
        }
        System.out.println("EmployeeID\tEmployee Name\tEmployee Salary");
        for(int i=0;i<n;i++)
        {
            e[i].display();
        }
        System.out.println("Enter percentage to increase:");
        double percentage;
        percentage=s.nextDouble();
        for(int i=0;i<n;i++)
        {
            e[i].raisesalary(percentage);
            e[i].display();
        }
        s.close();
    }
}