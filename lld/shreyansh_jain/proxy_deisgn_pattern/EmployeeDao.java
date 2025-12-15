package shreyansh_jain.proxy_deisgn_pattern;

public interface EmployeeDao {
    public void create(String client, EmployeeDo employ) throws Exception;
    public void delete(String client, EmployeeDo employ) throws Exception;
    public EmployeeDo get(String client, int empId) throws Exception;
}
