#ifndef PREDICT_HEADER_
#define PREDICT_HEADER_

extern "C" {
    void predict(const float **image, int *label_pred);
}

#endif