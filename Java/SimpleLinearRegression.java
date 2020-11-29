import java.lang.Math;
import java.util.Arrays;

public class SimpleLinearRegression
{
    private double[] theta = {0.0, 0.0};
    private double[] x;
    private double[] y;
    private double alpha;
    private int maxIteration;

    SimpleLinearRegression(double[] x, double[] y, double alpha, int maxIteration)
    {
        this.x = x;
        this.y = y;
        this.alpha = alpha;
        this.maxIteration = maxIteration;
    }

    public void learn(boolean showLog)
    {
        for (int iter = 0; iter < maxIteration; iter++)
        {
            theta[0] = theta[0] - alpha * derivativeOfErrorFunc(true);
            theta[1] = theta[1] - alpha * derivativeOfErrorFunc(false);
            if (showLog)
            {
                System.out.println("Error value: " + errorFunc());
                System.out.println("Updated theta: " + Arrays.toString(theta));
                System.out.println("===");
            }
        }
    }

    public double[] getTheta() {
        return theta;
    }

    private double derivativeOfErrorFunc(boolean isThetaZero)
    {
        double sum = 0.0;
        if (isThetaZero)
        {
            for (int i = 0; i < x.length; i++)
            {
                sum += theta[0] + theta[1] * x[i] - y[i];
            }
        }
        else
        {
            for (int i = 0; i < x.length; i++)
            {
                sum += (theta[0] + theta[1] * x[i] - y[i]) * x[i];
            }
        }
        return sum/(double)x.length;
    }

    private double errorFunc()
    {
        double sum = 0.0;
        for (int i = 0; i < x.length; i++)
        {
            sum += Math.pow((theta[0] + theta[1] * x[i] - y[i]), 2);
        }
        return sum/(2 * (double)x.length);
    }
}
