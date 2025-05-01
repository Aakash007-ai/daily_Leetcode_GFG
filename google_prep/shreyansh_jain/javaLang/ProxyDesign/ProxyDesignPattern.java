package javaLang.ProxyDesign;

public class ProxyDesignPattern{
    public static void main(String args[]){
        try{
            EmployeeDao empTableObj = new EmployeeDaoProxy(null);
            empTableObj.create("USER",new EmployeeDaoImpl());
            System.out.println("Operation Successfull");

        }catch(Exception error){
            System.out.println("Error: " + error.getMessage());
        }
    } 
}
