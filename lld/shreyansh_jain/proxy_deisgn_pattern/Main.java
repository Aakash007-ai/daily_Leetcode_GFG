package shreyansh_jain.proxy_deisgn_pattern;


/**
 * In this client try to access a real object,
 * but we put a layer in between them so that our request pass through proxy
 * 
 * 
 * e.g in our college we have firewall
 * where every request pass through firewall
 * 
 * pre-processing or post processing 
 * publish events (whenever we want to notify someone when something has done), centralised logging
 * 
 * in spring boot , wheever we create bean , spring boot create proxy of that bean
 * 
 * e.g. there is an employ table interface , which has create, delete, get method
 * we implement that in concrete class EmployTableImpl with following create, delete , get method
 * 
 * then we create a proxyImpl that is a relationship with EmployTable and has a  both
 * 
 * 
 * there can be multiple proxy layers treating as next object is real object
 * 
 * interviewer will ask for centralised things, pre-processing, postProcessing or logging
 */

public class Main {
    public static void main(String[] args){
        try {
        EmployeeDao employTableObj = new EmployeeDaoProxy();
        employTableObj.create("ADMIN", new EmployeeDo());
        System.out.println("Operation Successfull");
        }catch(Exception error){
            System.out.println(error.getMessage());
        }

    }
}
