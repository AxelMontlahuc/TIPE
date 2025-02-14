#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
using namespace std;

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


int main() {
    return 0;
}