package main

import "fmt"
import "math"

func errorFunc(x []float64, y []float64, length int, theta []float64) float64 {
    var sum float64 = 0.0
    for i := 0; i < length; i++ {
        sum += math.Pow((theta[0] + theta[1] * x[i] - y[i]), 2)
    }
    return sum/2*float64(length)
}

func derivativeOfErrorFunc(x []float64, y []float64, length int, theta []float64, is_theta_zero bool) float64 {
    var sum float64 = 0.0
    if (is_theta_zero) {
        for i := 0; i < length; i++ {
            sum += theta[0] + theta[1] * x[i] - y[i]
        }
    } else {
        for i := 0; i < length; i++ {
            sum += (theta[0] + theta[1] * x[i] - y[i]) * x[i]
        }
    }
    return sum/float64(length)
}

func simpleLinearRegression(x []float64, y []float64, length int, alpha float64, max_iteration int, show_log bool) (float64, float64) {
    var theta = []float64{0.0, 0.0}

    for iter := 0; iter < max_iteration; iter++ {
        theta[0] = theta[0] - alpha * derivativeOfErrorFunc(x, y, length, theta, true)
        theta[1] = theta[1] - alpha * derivativeOfErrorFunc(x, y, length, theta, false)
        if (show_log) {
            fmt.Printf("Error value: %f\n", errorFunc(x, y, length, theta))
            fmt.Printf("Theta: %f %f\n", theta[0], theta[1])
            fmt.Printf("===\n")
        }
    }

    return theta[0], theta[1]
}

func main() {
    var x = []float64{20.0, 25.0, 30.0, 40.0, 43.0, 51.0}
    var y = []float64{1.6, 1.8, 2.5, 3.2, 3.4, 4.5}
    var theta = []float64{0.0, 0.0}
    theta[0], theta[1] = simpleLinearRegression(x, y, 6, 0.001, 5, true)
}
