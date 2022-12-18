#include "predict.h"
#include "mnist-12-bin.h"
#include <ncnn/mat.h>
#include <ncnn/net.h>

void predict(void *image, int *label_pred) {
    // receive input
    ncnn::Mat in(28, 28, 1, image);
    // receive output
    ncnn::Mat out;

    // load model
    ncnn::Net net;
    net.load_param(mnist_12_opt_param_bin);
    net.load_model(mnist_12_opt_bin);
    
    // extractor
    ncnn::Extractor extractor = net.create_extractor();
    extractor.input(0, in);
    extractor.extract(8, out);
    extractor.clear();
    net.clear();

    // get label
    int guessed = -1;
    float guess_exp = -10000000;

    for (int i = 0; i < 10; i++) {
        if (out[i] > guess_exp) {
            guessed = i;
            guess_exp = out[i];
        }
    }
    *label_pred = guessed;
}
