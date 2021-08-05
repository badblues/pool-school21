double max(double *data, int n) {
    double max = -10000000;
    for (int i = 0; i < n; i++)
        if (data[i] > max)
            max = data[i];
    return max;
}

double min(double *data, int n) {
    double min = 10000000;
    for (int i = 0; i < n; i++)
        if (data[i] < min)
            min = data[i];
    return min;
}

double mean(double *data, int n) {
    double mean = 0;
    double probability = 1 / (double)n;
    for (int i = 0; i < n; i++)
        mean += data[i] * probability;
    return mean;
}
double variance(double *data, int n) {
    double mean = 0, square_mean = 0, variance = 0;
    double probability = 1 / (double)n;
    for (int i = 0; i < n; i++) {
        mean += data[i] * probability;
        square_mean += data[i] * data[i] * probability;
    }
    variance = square_mean - mean * mean;
    return variance;
}

