class Multiplier extends Thread {
      private int[][] multiplicand;
      private int[][] multiplier;
      private int row;
      private int col;
      private int[][] result;
  
      public Multiplier(int[][] multiplicand, int[][] multiplier, int row, int col, int[][] result) {
          this.multiplicand = multiplicand;
          this.multiplier = multiplier;
          this.row = row;
          this.col = col;
          this.result = result;
      }
  
      @Override
      public void run() {
          int sum = 0;
          for (int i = 0; i < multiplicand[0].length; i++) {
              sum += multiplicand[row][i] * multiplier[i][col];
          }
          result[row][col] = sum;
      }
  }
  
  public class MatrixMultiplication {
      public static void main(String[] args) {
          int[][] multiplicand = {
              {5, 6, 7},
              {4, 8, 9}
          };
  
          int[][] multiplier = {
              {6, 4},
              {5, 7},
              {1, 1}
          };
  
          int rows = multiplicand.length;
          int cols = multiplier[0].length;
  
          int[][] result = new int[rows][cols];
          Multiplier[][] threads = new Multiplier[rows][cols];
  
          // Create and start threads
          for (int i = 0; i < rows; i++) {
              for (int j = 0; j < cols; j++) {
                  threads[i][j] = new Multiplier(multiplicand, multiplier, i, j, result);
                  threads[i][j].start();
              }
          }
  
          // Wait for all threads to finish
          for (int i = 0; i < rows; i++) {
              for (int j = 0; j < cols; j++) {
                  try {
                      threads[i][j].join();
                  } catch (InterruptedException e) {
                      e.printStackTrace();
                  }
              }
          }
  
          // Print the result matrix
          System.out.println("Result matrix:");
          for (int i = 0; i < rows; i++) {
              for (int j = 0; j < cols; j++) {
                  System.out.print(result[i][j] + " ");
              }
              System.out.println();
          }
      }
  }
  