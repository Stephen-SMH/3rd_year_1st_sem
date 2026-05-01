public class MatrixMultiplicationMultiThread {
    public static void main(String[] args) {
        int[][] array1 = {{5, 6, 7}, {4, 8, 9}};
        int[][] array2 = {{6, 4}, {5, 7}, {1, 1}};
        int rowResult = array1.length;
        int colResult = array2[0].length;
        int [][] result = new int[rowResult][colResult];       
        Multiplier [][] children = new Multiplier [rowResult][colResult];
        for(int i =0; i < rowResult; i++) {
           for(int j =0; j < colResult; j++) {
               children[i][j] = new Multiplier(array1, array2,i,j);
               children[i][j].start();
           }
        }
        for(int i =0; i < rowResult; i++) {
           for(int j =0; j < colResult; j++) {
               try {
                   children[i][j].join(); // wait for all children
               } catch (InterruptedException ex) {
                  
               }
           }
        }
        for(int i =0; i < rowResult; i++) {
           for(int j =0; j < colResult; j++) {
               result[i][j] = children[i][j].getResult();
           }
           
        }
        //print result
       System.out.println("First Matrix");
       displayMatrix(array1);
       System.out.println("Second Matrix");
       displayMatrix(array2);
       System.out.println("Result Matrix");
       displayMatrix(result);
   }
    public static void displayMatrix(int [][] matrix) {
     for(int i = 0; i < matrix.length; i++) {
      for(int j = 0; j < matrix[0].length; j++) {
         System.out.print(matrix[i][j] + " ");
      }
      System.out.println();
     } 
   }

}