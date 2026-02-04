package ParkingLot.interfaces;

public interface PaymentService {
    public void acceptCash(int amount);
    public void acceptCreditCard(int creditCardNumber, int cvv , int amount);   
}
