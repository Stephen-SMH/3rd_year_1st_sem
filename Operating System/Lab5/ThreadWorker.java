
public class ThreadWorker extends Thread {
      int number;
      int sum;
      
      public ThreadWorker(int number) {
            this.number = number * 2;
            sum = 0;
      }
      
      public void run() {
            System.err.println("Child's calculating...");
            for (int i = 1; i < number; i++) {
                  sum += i;
            }
      }

      public int getSum() {
            return sum;
      }
}