fn error_func(x:[f64; 6], y:[f64; 6], theta:[f64; 2]) -> f64
{
    let mut sum:f64 = 0.0;
    for i in 0..x.len()
    {
        sum += (theta[0] + theta[1] * x[i] - y[i]).powf(2.0);
    }

    return sum/((2 * x.len()) as f64);
}


fn derivative_of_error_func(x:[f64; 6], y:[f64; 6], theta:[f64; 2], is_theta_zero: bool) -> f64
{
    let mut sum:f64 = 0.0;
    if is_theta_zero
    {
        for i in 0..x.len()
        {
            sum += theta[0] + theta[1] * x[i] - y[i];
        }
    }
    else
    {
        for i in 0..x.len()
        {
            sum += (theta[0] + theta[1] * x[i] - y[i]) * x[i];
        }
    }

    return sum/(x.len() as f64);
}


fn simple_linear_regression(x:[f64; 6], y:[f64; 6], alpha:f64, max_iteration:i64, show_log:bool)
{
    let mut theta:[f64; 2] = [0.0, 0.0];
    for _iter in 0..max_iteration
    {
        theta[0] = theta[0] - alpha * derivative_of_error_func(x, y, theta, true);
        theta[1] = theta[1] - alpha * derivative_of_error_func(x, y, theta, false);
        if show_log
        {
            println!("Error value: {}", error_func(x, y, theta));
            println!("Theta: {:?}", theta);
            println!("===");
        }
    }
}

fn main()
{
    let x:[f64; 6] = [20.0, 25.0 , 30.0, 40.0, 43.0, 51.0];
    let y:[f64; 6] = [1.6, 1.8, 2.5, 3.2, 3.4, 4.5];
    simple_linear_regression(x, y, 0.001, 5, true);
}
