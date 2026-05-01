import java.util.*;

public class Producer implements Runnable {
      private int number;
      private BoundedBuffer buffer;

      public Producer(BoundedBuffer b) {
            buffer = b;
            number = 0;
      }

      public void run() {
            for (int i = 1; i <= 20; i++) {
                  // while (true) {
                  Random rand = new Random();
                  try {
                        Thread.sleep(rand.nextInt(3000));
                  } catch (InterruptedException e) {
                  }
                  // produce an item & enter it into the buffer

                  // System.out.println("Producer produced " + number);
                  buffer.insert(number++);
            }
      }

}