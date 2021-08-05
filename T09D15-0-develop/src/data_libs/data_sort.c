void sort(double* data, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (data[j] > data[j + 1]) {
                double tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
}
