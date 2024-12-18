import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class sorted {
    public static void main(String[] args) {
        //Write a program that prompts the user to enter a list and displays whether the list is sorted or not.
        Scanner console = new Scanner(System.in);
        ArrayList<Integer> nums=new ArrayList<>();
        int i;
        System.out.print("Enter how many number do you want to insert:");
        i=console.nextInt();
        for(int j=0;j<i;j++){
            System.out.print("Enter number:");
            int w=console.nextInt();
            nums.add(w);
            System.out.println();
        }

        ArrayList<Integer> original = new ArrayList<>(nums);
        
        // Sort the original list
        Collections.sort(nums);
        if(nums.equals(original)){
            System.out.println("The List is Sorted");
        }
        else{
            System.out.println("The List is not Sorted");
        }
        console.close();
    }
}
