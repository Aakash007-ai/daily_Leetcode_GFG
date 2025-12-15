package paymentMethod;

public class Cash extends PaymentMethod {

    @Override
    public boolean initiatePayment(int amount) {
        System.out.println("Cash Payment Method");
        return true;
    }

}
