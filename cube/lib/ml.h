#pragma once
#include <fstream>
#include <vector>
#include <memory.h>


class Matrix{
    private:


    public:
    double *data;
    int cols;
    int rows;
    Matrix();
    Matrix(const Matrix &copy);
    Matrix (int rows, int cols);
    Matrix (int rows);
    ~Matrix();
    void multiply(Matrix &b, Matrix &rezult);
    void affine(Matrix &b, Matrix &c);
    void cmultiply(Matrix &b, Matrix &rezult);
    void add(Matrix &b, Matrix &result);
    void copy(Matrix &b);
    void load_from_file(std::ifstream&);
    void reset();
    void fast_copy(Matrix &b);

    Matrix& operator=(const Matrix &other){
        this->data=new double[other.cols*other.rows];
        this->cols=other.cols;
        this->rows=other.rows;
        memcpy(this->data, other.data, cols*rows*sizeof(double));
        return *this;
    }

    void apply_tanh();
    void apply_sigmoid();
    void apply_rectify();
    void add_scalar(double scalar);
    void print();

};

class LSTM{
    private:
        //i
        Matrix p_x2i;
        Matrix p_h2i;
        Matrix p_bi;


        Matrix ct;
        int hidden_size;
        int input_size;
        Matrix tmp;
        Matrix tmp2;
        Matrix i_ait;
        Matrix i_aft;
        Matrix i_aot;
        Matrix i_agt;

    public:
        Matrix ht;
        LSTM(const LSTM&);
        LSTM(int input_size, int hidden_size);
        LSTM();
        ~LSTM();
        void reset();
        void add_input(Matrix &input);
        void load_from_file(std::ifstream &);
};