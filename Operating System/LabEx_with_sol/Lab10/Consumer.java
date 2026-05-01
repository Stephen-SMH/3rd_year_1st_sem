import java.util.*;

public class Consumer implements Runnable {
      private BoundedBuffer buffer;

      public Consumer(BoundedBuffer b) {
            buffer = b;
      }

      public void run() {
            int number = 0;
            for (int i = 1; i <= 20; i++) {
                  // while (true) {
                  Random rand = new Random();
                  try {
                        Thread.sleep(rand.nextInt(3000));
                  } catch (InterruptedException e) {
                  }
                  // consume an item from the buffer
                  // System.out.println("Consumer wants to consume.");
                  number = (Integer) buffer.remove();
                  // System.out.println("Consumer consumes " + number);
            }
      }

}
