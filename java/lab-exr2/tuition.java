public class tuition {
   
        public static void main(String [] args){
            double baseTuition = 10000;
            double tuitionTen = baseTuition;
            double totalTuition = 0;
            for(int i = 0; i < 14; i++){
                baseTuition += baseTuition * 0.05;
                if (i < 9) {
                    tuitionTen = baseTuition;
                }
                if (i > 9) {
                    totalTuition += baseTuition;
                }
            }
            System.out.println(tuitionTen);
            System.out.println(totalTuition);
        }
    }

