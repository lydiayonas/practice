public class DisplayNumbers {
    public static void main(String[] args) {
        int check = 0;
        for (int i = 100; i <= 200; i++)
        {
            if ((i % 5 == 0 || i % 6 == 0) && i % 30 != 0) {
                System.out.print(i + " ");
                check++;
                if (check == 10) {
                    check = 0;
                    System.out.println("");
                }
            }
        }
    }    
}
