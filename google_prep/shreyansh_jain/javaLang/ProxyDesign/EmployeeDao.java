package javaLang.ProxyDesign;

public interface EmployeeDao {
    public void create(String client,EmployeeDao obj) throws Exception;
    public void delete(String client, int employeeId) throws Exception;
    public void get(String client, int employeeId) throws Exception;
}
