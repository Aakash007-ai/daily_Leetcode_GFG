package ParkingLot.strategy.paymentStrategy;

public class CreditCardPaymentStrategy implements PaymentStrategy {
    private int creditCardNumber;
    private int cvv;

    public int getCreditCardNumber() {
        return creditCardNumber;
    }

    public void setCreditCardNumber(int creditCardNumber) {
        this.creditCardNumber = creditCardNumber;
    }

    public int getCvv() {
        return cvv;
    }

    public void setCvv(int cvv) {
        this.cvv = cvv;
    }

    @Override
    public void makePayment(int amount) {
        System.out.println("Making an payment of amount : " + amount + " via Credit Card "+ creditCardNumber +" and cvv "+ cvv);
    }

    
}
