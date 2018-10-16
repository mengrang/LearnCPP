
double kernel_rbf(double* v1, double* v2, double gamma, int dim);

double dot(double* x, double* y, int dim);

double SVR( double* support_vectors,  double* coef, double* x, int m, int dim, double b, double gamma);
