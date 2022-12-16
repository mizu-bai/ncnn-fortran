# ncnn-fortran

Call ncnn from Fortran via mix compiling.

## Introduction

How this demo works?

1. Image

    As Fortran is mainly used in scientific computation, there seems to be no workable OpenCV binding for Fortran or other computer vision libraries. The repo [ncnn_on_xr806
](https://github.com/nihui/ncnn_on_xr806) inspired me for the image was stored in a header file in the format of `const unsigned char` array and `ncnn::Mat::from_pixels` is ready for it. In this repo the image is stored in a ASCII-text file with 28 rows and 28 columns, it should be in `csv` or `tsv` like format. Here are some so-called images in `image/` directory.

2. Main Program

    The main program `main.f90` is written in Fortran, it parses command line arguments, loads image, call ncnn binding, and output the most possible label of input image.

3. ncnn Binding

    ncnn Binding inclueds 4 files:

    - `ncnn_mnist.f90`
    - `predict.h`
    - `predict.cpp`
    - `mnist-12-bin.h`

    `ncnn_mnist.f90` is the wrapper of function `predict`, it interacts with `predict.cpp` via `extern "C"` in `predict.h`. `mnist-12-bin.h` is the model waits ncnn to load. In `predict.cpp`, function `preduct` initializes an `ncnn::Mat` from a 2d Fortran array, loads the model, and predicts the label. Finally, the predicted label is passed to main program.

## Run

Modify the `CMakeLists.txt`, make sure all paths of ncnn is correct for you.

Then

```
$ mkdir build
$ cmake ..
$ make
$ cd ..
$ ./build/mnist image/4.dat
 Predict:            4
```

GNU and Intel compilers have been tested.

## References

- [ncnn](https://github.com/Tencent/ncnn)
- [ncnn_on_xr806](https://github.com/nihui/ncnn_on_xr806)
- [MNIST - Handwritten Digit Recognition](https://github.com/onnx/models/tree/main/vision/classification/mnist)

