public class PaymentProcessor {
    private PaymentStrategy paymentStrategy;

    PaymentProcessor(PaymentStrategy strategy){
        this.paymentStrategy = strategy;
    }

    public void processPayment(){
        this.paymentStrategy.processPayment();
    }
}
