#include "Layer.h"
#include <iostream>
#include <cmath>
using namespace std;

double sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

Layer::Layer(int inputSize, int neuronCount)
{
    this->inputSize = inputSize;
    this->neuronCount = neuronCount;
    weights.resize(neuronCount, vector<double>(inputSize, 0));
    biases.resize(neuronCount, 0);
    outputs.resize(neuronCount, 0);
}

void Layer::setWeights()
{
    for (int i = 0; i < neuronCount; ++i)
    {
        cout << "Enter bias for neuron " << i + 1 << ": ";
        cin >> biases[i];
        cout << "Enter " << inputSize << " weights for neuron " << i + 1 << ": ";
        for (int j = 0; j < inputSize; ++j)
        {
            cin >> weights[i][j];
        }
    }
}

vector<double> Layer::feedForward(const vector<double>& inputs)
{
    for (int i = 0; i < neuronCount; ++i)
    {
        double sum = biases[i];
        for (int j = 0; j < inputSize; ++j)
        {
            sum += weights[i][j] * inputs[j];
        }
        outputs[i] = sigmoid(sum);
    }
    return outputs;
}
