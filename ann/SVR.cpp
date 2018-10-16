// -*-coding:utf-8-*-
#include <cmath>

double SVR (double* support_vectors, 
					double* coef, 
					double* x,
					int m,  
					int dim,
					double b, 
					double gamma)
{
	//SVR�������ο���ʽ f (x) = sigma(coef_i * kernel(svi, x)) + b
	//support_vectorsΪһά���飬������Ϊ m �� dim ά֧������ ;
	//coefΪ����Ϊm��һά���飬��ʾ֧��������Ӧ��ϵ��;
	//xΪ��Ԥ��������
	//b��ʾƽ�Ʋ���;
	//gamma��ʾrbf�˺���������

	double kernel_rbf(double* v1, double* v2, double gamma,int dim);
	double dot(double* x, double* y, int dim);

	//���� kernel(svi, x) ������洢��product_vector��
	double* product_vector = new double[m];
	double* temp_vector = new double[dim];
	double* temp_coef = new double[m];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			temp_vector[j] = support_vectors[i*dim + j];
		}
		product_vector[i] = kernel_rbf(temp_vector, x, gamma, dim);

		temp_coef[i] = coef[i];		//��coef������
	}

	//������
	double result;
	result = dot(temp_coef, product_vector, m) + b;

	return result;
}


double kernel_rbf(double* v1, double* v2, double gamma, int dim)
{
	//rbf�˺���: exp(-||v1-v2||^2*gamma)
	//v1,v2Ϊ����ͬά������dimΪ��ά��, gammaΪ�˺�������

	double result = 0;
	double temp = 0;
	double dot(double* x, double* y, int dim);

	double *v_temp = new double [dim];
	for (int i = 0; i < dim; i++)
	{
		v_temp[i] = v1[i] - v2[i];
	}

	temp = dot(v_temp, v_temp, dim);		 // ||v1-v2||^2

	result = exp(-temp * gamma);
	delete[] v_temp;

	return result;
}

double dot(double* x, double* y, int dim)
{
	//�˺���Ϊ�����ڻ�������x��yΪͬά������dimΪ��ά��
	double result = 0;
	for (int i = 0; i < dim; i++)
	{
		result += x[i] * y[i];
	}
	return result;
}