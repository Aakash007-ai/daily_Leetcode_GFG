public class Main {
    public static void main(String[] args){
        PaymentProcessor creditCardProcessor = new PaymentProcessor(new CreditCardPayment());
        creditCardProcessor.processPayment();

        PaymentProcessor paypalProcessor = new PaymentProcessor(new PayPalPayment());
        paypalProcessor.processPayment();
    }
}
