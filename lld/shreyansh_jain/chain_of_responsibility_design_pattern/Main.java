package shreyansh_jain.chain_of_responsibility_design_pattern;

import shreyansh_jain.chain_of_responsibility_design_pattern.logger.InfoLogger;
import shreyansh_jain.chain_of_responsibility_design_pattern.logger.LogProcessor;
import shreyansh_jain.chain_of_responsibility_design_pattern.logger.DebugLogger;

/**
 * Very important ask in interview by examples
 * 
 * application
 * design ATM, vending machine , design logger (ask in amazon)
 * indirectly they are asking chain of responsibility
 * 
 * this pattern says whenever a sender sends request and does not bother who will fulfills requrest out of many receiver linked in chain
 * 
 * sender here means client check if it fulfill condition, if no it move to next condition, untill it check for all condition
 * 
 * e.g. we went to an ATM system, ask to withdraw money
 * we have differnt notes 100, 200, 500 in ATM, we have to withdraw some money, it first move to 500 section check how many it can fulfill, 
 * if 500 handler not able to handle sufficient it move to next 
 * 
 * 
 * for simplicity we take logger example
 * 
 * we usually do 
 * obj = new Logger()
 * 
 * then obj.info("Print info log") or obj.warn("Print warning logs")
 *  
 * firs we create an abstract class log processor, define all log level,
 * take nextPRocessor via constuctor injection
 * 
 * and then a log method which takes conditional information is calling log of nextProcessor
 * 
 * 
 * so finally a logLevelProcessor , creates all the next state  when construvctor of intitial  state get initialized
 * 
 * 
 * same for vending machine ,
 * e.g. water , bevrage , coke 
 * out o fone machine will give this based on user input
 *  
 */

public class Main {
    public static void main(String[] args){
        LogProcessor logObject = new InfoLogger(new DebugLogger(new ErrorLogger(null)));

        logObject.log(LogProcessor.INFO,"just for info");
        logObject.log(LogProcessor.ERROR,"exception happens");
        logObject.log(LogProcessor.WARN,"need to debug");
    }
}
