#include <iostream>
#include <vector>
#include "Layer.h"
using namespace std;

int main()
{
    cout << "Enter number of input neurons: ";
    int inputCount;
    cin >> inputCount;

    vector<double> inputs(inputCount);
    cout << "Enter input values:\n";
    for (int i = 0; i < inputCount; i++)
    {
        cin >> inputs[i];
    }

    cout << "Enter number of hidden layers: ";
    int hiddenLayersCount;
    cin >> hiddenLayersCount;

    vector<Layer> layers;

    int prevLayerSize = inputCount;

    for (int i = 0; i < hiddenLayersCount; i++)
    {
        cout << "Enter number of neurons in hidden layer " << i + 1 << ": ";
        int neurons;
        cin >> neurons;

        Layer layer(prevLayerSize, neurons);
        layer.setWeights();
        layers.push_back(layer);

        prevLayerSize = neurons;
    }

    cout << "Enter number of neurons in output layer: ";
    int outputNeurons;
    cin >> outputNeurons;

    Layer outputLayer(prevLayerSize, outputNeurons);
    outputLayer.setWeights();
    layers.push_back(outputLayer);

    vector<double> currentOutput = inputs;
    for (size_t i = 0; i < layers.size(); i++)
    {
        currentOutput = layers[i].feedForward(currentOutput);
        cout << "Outputs of layer " << i + 1 << ":\n";
        for (double val : currentOutput)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    cout << "Final output:\n";
    for (double val : currentOutput)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
