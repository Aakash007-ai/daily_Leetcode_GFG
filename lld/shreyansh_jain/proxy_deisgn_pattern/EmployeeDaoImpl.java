package shreyansh_jain.proxy_deisgn_pattern;

public class EmployeeDaoImpl implements EmployeeDao {

    public void create(String client, EmployeeDo employObj){
        System.out.println("Creating new user");
    }

    public void delete(String client, EmployeeDo employObj){
        System.out.println("Deleteinn employ");
    }

    public EmployeeDo get(String client, int empId ){
        System.out.println("Deleting employee with id : "+ client);
        return new EmployeeDo();       
    }
}
