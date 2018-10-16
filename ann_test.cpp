//ann_bp.cpp//
#include "ann_bp.h"
#include <math.h>
Ann_bp::Ann_bp(int _SampleN, int nNIL, int nNOL, const int nNHL, float _sR) :
SampleCount(_SampleN), numNodesInputLayer(nNIL), numNodesOutputLayer(nNOL),
numNodesHiddenLayer(nNHL), studyRate(_sR)
{
 
	//创建权值空间,并初始化
	srand(time(NULL));
    double weights0[numNodesInputLayer][numNodesHiddenLayer];
    for (int i = 0; i < numNodesInputLayer; ++i){
        for (int j = 0; j <numNodesHiddenLayer; ++j){
            weights0[i][j] =(rand() % (2000) / 1000.0 -1)
    }
    double weights1[numNodesHiddenLayer][numNodesOutputLayer];
    for (int i = 0; i < numNodesHiddenLayer; ++i){
        for (int j = 0; j < numNodesOutputLayer; ++j){
			weights1[i][j] = (rand() % (2000) / 1000.0 - 1); //-1到1之间
		}
    }
 
	//创建偏置空间，并初始化
    double bias0[numNodesHiddenLayer];
    for (int i = 0; i < numNodesHiddenLayer; ++i){
		bias0[i] = (rand() % (2000) / 1000.0 - 1); //-1到1之间
	}
    double bias1[numNodesOutputLayer];
    for (int i = 0; i < numNodesOutputLayer; ++i){
		bias1[i] = (rand() % (2000) / 1000.0 - 1); //-1到1之间
	}
	
	//创建隐藏层各结点的输出值空间
	hidenLayerOutput = new double[numNodesHiddenLayer];
	//创建输出层各结点的输出值空间
	outputLayerOutput = new double[numNodesOutputLayer];
 
}
 
Ann_bp::~Ann_bp()
{
	// //释放权值空间
	// for (int i = 0; i < numNodesInputLayer; ++i)
	// 	delete[] weights[0][i];
	// for (int i = 1; i < numNodesHiddenLayer; ++i)
	// 	delete[] weights[1][i];
	// for (int i = 0; i < 2; ++i)
	// 	delete[] weights[i];
	// delete[] weights;
 
	// //释放偏置空间
	// for (int i = 0; i < 2; ++i)
	// 	delete[] bias[i];
	// delete[] bias;
 
	//释放存储所有样本的输出层输出空间
	for (int k = 0; k < SampleCount; ++k)
		delete[] outputMat[k];
	delete[] outputMat;
 
}
 
void Ann_bp::predict(float* in, float* proba)
{
	//计算各隐藏层结点的输出
	for (int i = 0; i < numNodesHiddenLayer; ++i){
		double z = 0.0;
		for (int j = 0; j < numNodesInputLayer; ++j){
			z += in[j] * weights0[j][i];
		}
		z += bias[0][i];
		hidenLayerOutput[i] = sigmoid(z);
 
	}
 
	//计算输出层结点的输出值
	for (int i = 0; i < numNodesOutputLayer; ++i){
		double z = 0.0;
		for (int j = 0; j < numNodesHiddenLayer; ++j){
			z += hidenLayerOutput[j] * weights[1][j][i];
		}
		z += bias[1][i];
		outputLayerOutput[i] = sigmoid(z);
		std::cout << outputLayerOutput[i] << " ";
	}
	
}
