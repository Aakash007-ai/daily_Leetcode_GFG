package shreyansh_jain.proxy_deisgn_pattern;

public class EmployeeDaoProxy implements EmployeeDao {
    private EmployeeDao employeeDaoObj;

    public void create(String client, EmployeeDo employObj) throws Exception {
        if(client.equals("USER")){
            System.out.println("User has no permission to create employee");
        }else {
            employeeDaoObj.create(client, employObj);
            return ;
        }
        throw new Exception("Access Denied");
    }

    public void delete(String client, EmployeeDo employ) throws Exception {
        if(client.equals("ADMIN")){
            employeeDaoObj.delete(client, employ);
            return;
        }

        throw new Exception("Access Denied");
    }

    public EmployeeDo get(String client, int empId) throws Exception {
        if(client.equals("ADMIN") || client.equals("USER")){
            return employeeDaoObj.get(client, empId);
        }

        throw new Exception("Access Denied");
    }
}
