package services;

import interfaces.PaymentService;
import paymentMethod.Cash;
import paymentMethod.CreditCard;
import paymentMethod.PaymentMethod;

public class PaymentServiceImpl implements PaymentService {

    @Override
    public void acceptCash(int amount) {
        PaymentMethod cash = new Cash();
        cash.initiatePayment(amount);
    }

    @Override
    public void acceptCreditCard(String cardNumber, int cvv, int amount) {
        // TODO Auto-generated method stub
        PaymentMethod creditCard = new CreditCard(cardNumber, cvv);
        creditCard.initiatePayment(amount);
   }

}
