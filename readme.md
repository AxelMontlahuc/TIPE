# Pilot Model
This is the pilot model for the project. Every new model we create during this project will be compared to this model to benchmark its performance. 

---
## How it works
### Packages used
- ``iostream``: Used to read/print data (used for debug purposes among other things). 
- ``fstream``: Used for file operations (especially reading the datasets). 
- ``vector``: Used to store the data from the datasets. 
- ``cmath``: Used for mathematical operations.
- ``cstdlib``: Used for random number generation.
- ``cstdint``: Used for integer types.

---
## Structures
### Structure 1: ``Layer``
This structure represents a layer in the neural network. 
It stores the ``weights``, ``biases`` and ``outputs`` of the layer. 
- ``weights`` are stored in a matrix of size ``ouput_size x input_size``. 
- ``biases`` are stored in a vector of size ``output_size``.

The values are randomly initialized in the constructor in the range $[-0.5, 0.5]$.

---
#### Structure 2: ``NeuralNetwork``
This structure defines the neural network architecture.
It contains three layers : 
- The **input layer**: $784$ neurons ($28 \times 28$ pixels).
- One **hidden layer**: $16$ neurons (it is low for testing purposes).
- The **output layer**: $10$ neurons (one for each digit).

The ``predict`` function works in four steps : 
- Normalizes the input image by dividing it by $255$ (so we get a $[0, 1]$ range).
- Runs the ``forward`` function through the hidden layer.
- Runs the ``forward`` function through the output layer.
- Returns the output vector. 

---
## Functions
### Utility Functions
#### Function 1: ``load_mnist_images``
This function reads the MNIST images from the file and stores them in a vector.

The function first open the file in ``binary`` mode as the format of the data (``ubyte``) is not supported by the normal file reading functions. 
Then it reads the fields ``magic``, ``num``, ``rows`` and ``cols`` from the header of file (the first $16$ bytes). 

Then it reads the images from the file using the ``reinterpret_cast`` function to convert the data to the required format. 

Then the function ``__builtin_bswap32`` is used to convert the data from big-endian to little-endian (it basically inverts the direction of the data so it is the same direction that processors are used to).

Finally, it closes the file and returns the vector of images.

---
#### Function 2: ``load_mnist_labels``
This function reads the MNIST labels from the file and stores them in a vector.

It works the same way as the ``load_mnist_images`` function.

---
### Math Functions
#### Function 1: ``sigmoid``
This function calculates the sigmoid of a given value as it is here used as the activation function. As a reminder here is the formula for the sigmoid function:
$$\sigma(x) = \frac{1}{1+e^{-x}}$$

---
#### Function 2: ``cross_entropy_loss``
This is the implementation of the log-loss function which is the loss function used for this model. The formula for the log-loss function is:
$$L = -\frac{1}{m} \sum_{i=1}^{m} y_i \log(\hat{y}_{i})$$
Where :
- $m$ is the number of samples.
- $y_i$ is the true label of the $i^{th}$ sample.
- $\hat{y}_{i}$ is the predicted label of the $i^{th}$ sample.

Nota Bene: There is a small value $\epsilon = 10^{-8}$ added inside the $\log$ to avoid computing $\log 0$. 

---
### Neural Network Functions
#### Function 1: ``forward``
The ``forward`` function performs the forward propagation through a layer of the network : it computes and returns the output vector of the layer given the input vector using the basic formula of a neural network layer:
$$y_i = \sigma\left(\sum_{j} w_{ij}x_j + b_i\right)$$
Where : 
- $y_i$ is the output of the layer. 
- $w_{ij}$ is the weight of the connection from the input neuron $j$ to the output neuron $i$. 
- $b_i$ is the bias of the neuron $i$.
- $\sigma$ is the activation function (here the sigmoid function).

---
#### Function 2: ``backward``
The ``backward`` function performs the backward propagation through a layer of the network : it computes the gradients of the ``weights`` and ``biases`` of the layer using the gradient chain rule : 
$$\frac{\partial L}{\partial w_{ij}} = \frac{\partial L}{\partial y_i} \frac{\partial y_i}{\partial w_{ij}}$$
The function then performs the gradient descent to update the weights and biases of the layer using the formula : 
$$w_{ij} = w_{ij} - \alpha \frac{\partial L}{\partial w_{ij}}$$