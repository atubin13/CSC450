public class Main {

    // Inner class for counting up
    static class CounterUp implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i <= 20; i++) {
                System.out.println("Counting up: " + i);
            }
        }
    }

    // Inner class for counting down
    static class CounterDown implements Runnable {
        @Override
        public void run() {
            for (int i = 20; i >= 0; i--) {
                System.out.println("Counting down: " + i);
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        // Create and start the counting-up thread
        Thread counterUpThread = new Thread(new CounterUp());
        counterUpThread.start();
        
        // Wait for counterUpThread to finish before starting counterDownThread
        counterUpThread.join();
        
        // Create and start the counting-down thread
        Thread counterDownThread = new Thread(new CounterDown());
        counterDownThread.start();
    }
}
