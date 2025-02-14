#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cmath>
#include <cstdint>
using namespace std;

struct Layer {
    vector<vector<double>> weights;
    vector<double> biases;
    vector<double> outputs;

    Layer(int input_size, int output_size) {
        weights.resize(output_size, vector<double>(input_size));
        biases.resize(output_size);
        outputs.resize(output_size);

        for (int i = 0; i < output_size; i++) {
            biases[i] = ((double) rand() / RAND_MAX) - 0.5;
            for (int j = 0; j < input_size; j++) {
                weights[i][j] = ((double) rand() / RAND_MAX) - 0.5;
            }
        }
    }
};

struct NeuralNetwork {
    Layer hidden;
    Layer output;

    NeuralNetwork() : hidden(784, 16), output(16, 10) {}

    vector<double> predict(const vector<uint8_t>& image) {
        vector<double> input(image.begin(), image.end());
        for (double& x : input) x /= 255.0;

        vector<double> hidden_output = forward(input, hidden);
        return forward(hidden_output, output);
    }
};

vector<vector<uint8_t>> load_mnist_images(const string& filename, int& num_images) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error : Cannot open file" << filename << endl;
        exit(1);
    }

    uint32_t magic, num, rows, cols;
    file.read(reinterpret_cast<char*>(&magic), 4);
    file.read(reinterpret_cast<char*>(&num), 4);
    file.read(reinterpret_cast<char*>(&rows), 4);
    file.read(reinterpret_cast<char*>(&cols), 4);

    num_images = __builtin_bswap32(num);
    rows = __builtin_bswap32(rows);
    cols = __builtin_bswap32(cols);

    vector<vector<uint8_t>> images(num_images, vector<uint8_t>(rows * cols));

    for (int i = 0; i < num_images; i++) {
        file.read(reinterpret_cast<char*>(&images[i][0]), rows * cols);
    }

    file.close();
    return images;
}

vector<uint8_t> load_mnist_labels(const string& filename, int& num_labels) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Cannot open file: " << filename << endl;
        exit(1);
    }

    uint32_t magic, num;
    file.read(reinterpret_cast<char*>(&magic), 4);
    file.read(reinterpret_cast<char*>(&num), 4);

    num_labels = __builtin_bswap32(num);

    vector<uint8_t> labels(num_labels);
    file.read(reinterpret_cast<char*>(labels.data()), num_labels);

    file.close();
    return labels;
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

vector<double> forward(const vector<double>& input, Layer& layer) {
    vector<double> output(layer.biases.size());
    
    for (size_t i = 0; i < layer.biases.size(); i++) {
        double sum = layer.biases[i];

        for (size_t j = 0; j < input.size(); j++) {
            sum += input[j] * layer.weights[i][j];
        }

        output[i] = sigmoid(sum);
    }
    
    layer.outputs = output;
    return output;
}


int main() {
    return 0;
}