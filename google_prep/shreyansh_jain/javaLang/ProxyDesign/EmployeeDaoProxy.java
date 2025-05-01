package javaLang.ProxyDesign;

public class EmployeeDaoProxy implements EmployeeDao {
    public EmployeeDao employeeDao;

    public EmployeeDaoProxy(EmployeeDao employesDao) {
        this.employeeDao = employesDao;
    }

    @Override
    public void create(String client, EmployeeDao obj) throws Exception {
        if(client.equals("admin")) {
            employeeDao.create(client, obj);
        } else {
            throw new Exception("Not authorized to create employee");
        }
    }

    @Override
    public void delete(String client, int employeeId) throws Exception {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'delete'");
    }

    @Override
    public void get(String client, int employeeId) throws Exception {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'get'");
    }
    
}
