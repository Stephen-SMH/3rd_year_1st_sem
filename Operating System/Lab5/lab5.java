import java.util.Scanner;

public class lab5 {
      public static void main(String[] args) {
            Scanner input = new Scanner(System.in);
            System.err.println("Enter a number:");
            int num = input.nextInt();
            input.close();
            int sum = 0;
            ThreadWorker runner = new ThreadWorker(num);
            runner.start();
            System.err.println("Parent's calculating...");

            for (int i = 0; i < num; i++) {
                  sum += i;
            }

            try   {
                  runner.join();
            } catch (InterruptedException e) {
                  System.err.println("Thread interrupted");
            }

            sum += runner.getSum();
            System.err.println("Result: " + sum);

      }
}
