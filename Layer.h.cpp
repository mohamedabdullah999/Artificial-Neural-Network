#ifndef LAYER_H
#define LAYER_H

#include <vector>
using namespace std;

class Layer
{
public:
    int inputSize;
    int neuronCount;
    vector<vector<double>> weights;
    vector<double> biases;
    vector<double> outputs;

    Layer(int inputSize, int neuronCount);

    void setWeights();

    vector<double> feedForward(const vector<double>& inputs);
};

double sigmoid(double x);

#endif
