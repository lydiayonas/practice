public class q5 {
    public static void main(String[] args) {
        int rows = 4;
        int cols = 4;
        int[][] matrix = new int[rows][cols];
        int[] rowSums = new int[rows];
        int[] colSums = new int[cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = (int) Math.round(Math.random());
                System.out.print(matrix[i][j]);
                rowSums[i] += matrix[i][j];
                colSums[j] += matrix[i][j];
            }
            System.out.println();
        }

        int largestRowIndex = 0;
        for (int i = 1; i < rows; i++) {
            if (rowSums[i] > rowSums[largestRowIndex]) {
                largestRowIndex = i;
            }
        }

        int largestColIndex = 0;
        for (int j = 1; j < cols; j++) {
            if (colSums[j] > colSums[largestColIndex]) {
                largestColIndex = j;
            }
        }

        System.out.println("The largest row index: " + largestRowIndex);
        System.out.println("The largest column index: " + largestColIndex);
    }
}
