package ParkingLot.services;

import ParkingLot.interfaces.PaymentService;
import ParkingLot.strategy.paymentStrategy.CashPayment;
import ParkingLot.strategy.paymentStrategy.CreditCardPaymentStrategy;

public class PaymentServiceImpl implements PaymentService {
    private CashPayment cashMethod;
    private CreditCardPaymentStrategy creditCardPaymentStrategy; 
    public PaymentServiceImpl(){
        cashMethod = new CashPayment();
        creditCardPaymentStrategy = new CreditCardPaymentStrategy();
    }

    @Override
    public void acceptCash(int amount) {
        cashMethod.makePayment(amount);
    }

    @Override
    public void acceptCreditCard(int creditCardNumber, int cvv, int amount) {
        creditCardPaymentStrategy.setCreditCardNumber(creditCardNumber);
        creditCardPaymentStrategy.setCvv(cvv);
        creditCardPaymentStrategy.makePayment(amount);
    }

}
