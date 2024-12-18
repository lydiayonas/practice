import java.util.Scanner;

public class slotMachine {
    public static void main(String [] args){

        Scanner console = new Scanner(System.in);

        int ContinueInput=1;
        while(ContinueInput != 0){
            int x,y,z;
            x = (int)(Math.random()*10);
            y = (int)(Math.random()*10);
            z = (int)(Math.random()*10);

            System.out.println("The numbers are "+x+", "+y+" and "+z);
            if(x==y && y==z){
                System.out.println("They are all equal!");
            } else if ((x==y && y!=z)||(x==z&& y!=x)||(z==y && z!=x)) {
                System.out.println("Two of them are equal!");
            } else {
                System.out.println("None of them are equal!");
            }
            
            System.out.print("Enter 0 to exit: ");
            ContinueInput = console.nextInt();
        }

        console.close();
    }
}
