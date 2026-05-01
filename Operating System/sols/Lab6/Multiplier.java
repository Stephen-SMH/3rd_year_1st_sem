public class Multiplier extends Thread {
    private int[][]a;
    private int[][]b;
    private int row, col;
    private int result;
    public Multiplier(int[][] a, int[][]b, int row, int col) {
        this.result = 0;
        this.a= a;
        this.b = b;
        this.row = row;
        this.col = col;
    }
    @Override
    public void run() {
        for (int i = 0; i < b.length; i++) {
          result += a[row][i] * b[i][col];
        }
    }
    public int getResult() {
        return result;
    }
}