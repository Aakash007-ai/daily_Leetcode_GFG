package multithreading.Basic;

class NumberPrinter{
    private int number = 1;
    private int max;

    NumberPrinter(int max){
        this.max = max;
    }

    public synchronized void printOdd(){
        while(number <= max){
            if(number%2 == 0){
                try{
                    wait();
                } catch(InterruptedException e){
                    Thread.currentThread().interrupt();
                }
            }else{
                System.out.println("Odd Thread: "+number);
                number++;
                notify(); // wake up even thread
            }
        }
    }

    public synchronized void printEven() {
        while (number <= max) {
            if (number % 2 != 0) {
                try {
                    wait();
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            } else {
                System.out.println("Even Thread: " + number);
                number++;
                notify();
            }
        }
    }

}

public class OrderPrinter {
    public static void main(String[] args) {
        NumberPrinter printer = new NumberPrinter(10);

        Thread oddThread = new Thread(printer::printOdd);
        Thread evenThread = new Thread(printer::printEven);

        oddThread.start();
        evenThread.start();
    }
}
