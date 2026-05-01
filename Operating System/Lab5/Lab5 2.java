import java.util.Scanner;
// First.java 

class Worker1 extends Thread
{
   private int number;
   private int childSum;

   public Worker1(int number) {
      this.number = number;
   }

   public void run() {
      System.out.println("I Am a Worker Thread");
      childSum = getSum(number*2);
      System.out.println("Child: " + childSum);
   }

   public int getChildSum() {
      return childSum;
   }

   public int getSum(int n) {
      int sum = 0;
      for (int i = 1; i <= n; i++) {
         sum += i;
      }
      return sum;
   }
}

public class Lab5
{
   public static void main(String args[]) {
      Scanner scanner = new Scanner(System.in);
      System.out.print("Enter your number: ");
      int number = scanner.nextInt();
      Worker1 runner = new Worker1(number);
      runner.start();
	   System.out.println("I Am The Main Thread");

      int parentSum = getSum(number);
      System.out.println("Parent: " + parentSum);
      try {
         runner.join();
      } catch (InterruptedException e) {
         System.out.println("Worker thread interrupted.");
      }
      int child = runner.getChildSum();
      int finalresult = parentSum + child;
      System.out.println("Final: " + finalresult);
      scanner.close();
   }

   public static int getSum(int n) {
      int sum = 0;
      for (int i = 1; i <= n; i++) {
         sum += i;
      }
      return sum;
   }
}



