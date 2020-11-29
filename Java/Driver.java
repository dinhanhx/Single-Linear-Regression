import java.util.Arrays;
public class Driver {
    public static void main(String[] args) {
        double[] x = {20.0, 25.0 , 30.0, 40.0, 43.0, 51.0};
        double[] y = {1.6, 1.8, 2.5, 3.2, 3.4, 4.5};
        SimpleLinearRegression lr = new SimpleLinearRegression(x, y, 0.001, 5);
        lr.learn(true);
//        System.out.println(Arrays.toString(lr.getTheta()));
    }
}
