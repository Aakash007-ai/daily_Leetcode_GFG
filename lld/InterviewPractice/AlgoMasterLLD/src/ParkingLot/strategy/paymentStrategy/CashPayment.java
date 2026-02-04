package ParkingLot.strategy.paymentStrategy;

public class CashPayment implements PaymentStrategy{

    @Override
    public void makePayment(int amount) {
        System.out.println("Cash payment of amount : "+ amount );
    }

}
