//ann_bp.cpp//
#include "ann_bp.h"
#include <math.h>
double ANN (float* in,
            int _SampleN,
            int numNodesInputLayer, 
            int numNodesOutputLayer, 
            int numNodesHiddenLayer)
{
// Ann_bp::Ann_bp(int _SampleN, int nNIL, int nNOL, const int nNHL, float _sR) :
// SampleCount(_SampleN), numNodesInputLayer(nNIL), numNodesOutputLayer(nNOL),
// numNodesHiddenLayer(nNHL), studyRate(_sR)
// {
	//创建权值空间,并初始化
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
    //计算各隐藏层结点的输出
	for (int i = 0; i < numNodesHiddenLayer; ++i){
		double z = 0.0;
		for (int j = 0; j < numNodesInputLayer; ++j){
			z += in[j] * weights0[j][i];
		}
		z += bias0[i];
		hidenLayerOutput[i] = sigmoid(z);
 
	}
 
	//计算输出层结点的输出值
	for (int i = 0; i < numNodesOutputLayer; ++i){
		double z = 0.0;
		for (int j = 0; j < numNodesHiddenLayer; ++j){
			z += hidenLayerOutput[j] * weights1[j][i];
		}
		z += bias1[i];
		outputLayerOutput[i] = sigmoid(z);
		std::cout << outputLayerOutput[i] << " ";
	}
}
