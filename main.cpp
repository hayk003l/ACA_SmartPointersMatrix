#include <iostream>
#include <memory>

template <typename T>
class Matrix {
private:
    std::unique_ptr<T[]> _matrixPtr;
    int _row;
    int _column;
public:
    Matrix(const int& row, const int& column) : _row(row), _column(column), _matrixPtr(std::make_unique<int[]>(_row * _column)) {}
    
    Matrix(const Matrix& obj) = delete;
    Matrix& operator=(const Matrix& obj) = delete;

    Matrix(Matrix&& obj) : _row(obj._row), _column(obj._column), _matrixPtr(std::move(obj._matrixPtr)) {
        obj._column = 0;
        obj._row = 0;
    }

    Matrix& operator=(Matrix&& obj) {
        if (this != &obj) {
            _row = obj._row;
            _column = obj._column;
            _matrixPtr = std::move(obj._matrixPtr);
            obj._row = 0;
            obj._column = 0;
        }
    }

    ~Matrix() = default;

    int getRow() {
        return _row;
    }

    int getColumn() {
        return _column;
    }

    T& operator()(const int& row, const int& column) {
        return _matrixPtr[row * _column + column];
    }

    void print() {
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _column; ++j) {
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    void initilize() {
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _column; ++j) {
                (*this)(i, j) = 1;
            }
        }
    }

};    
    
int main() {

    Matrix<int> matrix(3, 3);

    matrix.initilize();
    matrix.print();

    return 0;

}