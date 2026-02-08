package multithreading.Basic;


class Counter {
    int count = 0;
    /**
     * putting synchronize 
     * will make mutual exclusion over this function call
     * but slower under heavy contention (multiple request try to access same variable)
     * 
     * 
     * so it is better to use AtomicInteger
     * ✔️ Lock-free
     * ✔️ High performance
     * ✔️ Production-grade
     * AtomicInteger uses CAS (Compare-And-Swap) internally.
     * 
     * ✅ Use AtomicInteger when:
     *      Simple counters
     *      Independent updates
     *      High throughput systems (metrics, rate limiting)
     * ✅ Use synchronized when:
     *      Multiple variables must be updated together
     *      Complex invariants
     *      Critical sections
     */
    void increment() {
        count++;
    }
}

public class BrokenCounter {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();

        Thread th1 = new Thread(()->{
            for(int i=0;i<100000;i++){
                counter.increment();
            }
        });

        Thread th2 = new Thread(()->{
            for(int i=0;i<100000;i++){
                counter.increment();
            }
        });

        th1.start();
        th2.start();

        th1.join(); // main thread will wait for th1 to completely execute
        th2.join(); // main thread wait here for th2 thread completely execute

        System.out.println("Final Count: "+ counter.count); 
        // after waiting for both thread to get execute sequentially we print counter.count
    }
}


/**
 * Solution of race condiiton
 * 
 * use atomic integer
 * 
 * mututal exclusion -- only 1 thread will go inside critical section
 * use synchronize only 1 thread will work on this
 * 
 * 
 * either by locks/mutex 
 * 
 * or by semaphore
 */