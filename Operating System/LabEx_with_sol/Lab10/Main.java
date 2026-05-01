public class Main {
      public static void main(String args[]) throws InterruptedException {
            BoundedBuffer buffer = new BoundedBuffer();
            Thread producerThread = new Thread(new Producer(buffer));
            Thread consumerThread = new Thread(new Consumer(buffer));
            producerThread.start();
            consumerThread.start();
            producerThread.join();
            consumerThread.join();
      }

}
