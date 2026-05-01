public class Main {
      public static void main(String[] args) {
          int[][] array1 = {{5, 6, 7}, {4, 8, 9}};
          int[][] array2 = {{6, 4}, {5, 7}, {1, 1}};
          int rowResult = array1.length;
          int colResult = array2[0].length;
          int[][] result = new int[rowResult][colResult];
  
          // 1. Define a 2D array of Multiplier where each element will be used to find the summation 
          // of each specified row multiplied by each specified column.
          Multiplier[][] multipliers = new Multiplier[rowResult][colResult];
  
          // 2. Create an object of each Multiplier element and start the thread of each element.
          for(int i = 0; i < rowResult; i++) {
              for(int j = 0; j < colResult; j++) {
                  multipliers[i][j] = new Multiplier(array1, array2, i, j);
                  multipliers[i][j].start();
              }
          }
  
          // 3. The Main program waits for all threads to complete their task.
          for(int i = 0; i < rowResult; i++) {
              for(int j = 0; j < colResult; j++) {
                  try {
                      multipliers[i][j].join();
                  } catch (InterruptedException e) {
                      e.printStackTrace();
                  }
              }
          }
  
          // 4. Store the result of each thread into the result array.
          for(int i = 0; i < rowResult; i++) {
              for(int j = 0; j < colResult; j++) {
                  result[i][j] = multipliers[i][j].getResult();
              }
          }
  
          // Print result
          System.out.println("First Matrix");
          displayMatrix(array1);
          System.out.println("Second Matrix");
          displayMatrix(array2);
          System.out.println("Result Matrix");
          displayMatrix(result);
      }
  
      public static void displayMatrix(int[][] matrix) {
          for(int i = 0; i < matrix.length; i++) {
              for(int j = 0; j < matrix[0].length; j++) {
                  System.out.print(matrix[i][j] + " ");
              }
              System.out.println();
          } 
      }
  }
  
 