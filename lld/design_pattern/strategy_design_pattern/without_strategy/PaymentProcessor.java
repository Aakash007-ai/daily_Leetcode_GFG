public class PaymentProcessor {
    public void processPayment(String paymentType){
        if(paymentType.equals("Credit")){
            System.out.println("Processing credit Card Payment");
        }else if(paymentType.equals("paypal")){
            System.out.println("Processing Paypal Payment");
        }else {
            System.out.println("Unknown Paymnet type");
        }
    }
}


// here it violate open/closed principle