package multithreading.Basic;


class NumberPrinter extends Thread {
    private int n;

    public NumberPrinter(int n) {
        this.n = n;
    }

    public void run(){
        for(int i=1;i<=n;i++){
            System.out.println("Thread: "+ Thread.currentThread().getName() + "->" +i);
        }
    }

}

public class Basic {
    public static void main(String[] args) {
        int n = 5;
        
        NumberPrinter t1 = new NumberPrinter(n);
        t1.start(); // create a new thread
        /**
         * .start() 
         * create a new thread
         * os create a new thread
         * 
         * t1.run() just a normal method call
         */
        t1.run(); // run in main thread

        Thread t2 = new Thread(new NumberPrinter(n));
        t2.start();
    }
}











// 3 AM.

//  Production is down.

//  CPU: 12%
//  Memory: Normal
//  No errors in logs.

//  But requests are timing out.

//  After 2 hours of chaos, we found it:

//  𝗧𝗵𝗿𝗲𝗮𝗱 𝗽𝗼𝗼𝗹 𝗲𝘅𝗵𝗮𝘂𝘀𝘁𝗶𝗼𝗻.

//  Here's what happened:

//  Our service called an external API.
//  That API started responding slowly (30s+ timeouts).
//  Each request held a thread hostage.
//  Thread pool: 200 threads.
//  Incoming RPS: 50/sec.

//  Do the math:
//  50 requests × 30 seconds = 1500 threads needed.
//  We had 200.

//  New requests queued indefinitely.
//  Timeouts everywhere.
//  Zero errors—just silence.

//  𝗧𝗵𝗲 𝗳𝗶𝘅:

//  1. Circuit breaker (Resilience4j)
//  → Fast-fail after 5 consecutive timeouts

//  2. Bulkhead pattern
//  → Isolated thread pools per downstream service

//  3. Aggressive timeouts
//  → 5s connect, 10s read (non-negotiable)

//  4. Async I/O migration
//  → WebClient over RestTemplate
//  → Threads no longer blocked on I/O

//  𝗟𝗲𝘀𝘀𝗼𝗻:

//  Your service is only as reliable as your slowest dependency.

//  And the slowest dependency is always the one you forgot to add a timeout to.