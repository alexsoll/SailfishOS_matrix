#ifndef MATRIX_H
#define MATRIX_H

#include <QObject>
//using namespace std;

class Matrix : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float** mas READ getMas NOTIFY matrixChanged)
    Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)

private:
    int size;
    float **mas;

public:
    Q_INVOKABLE Matrix();
    Q_INVOKABLE Matrix(int size);
    Q_INVOKABLE void degree(int d);
    Matrix(const Matrix& m);
    Q_INVOKABLE void setSize(int s);
    Q_INVOKABLE int getSize();
    Q_INVOKABLE float getElement(int i, int j);
    Q_INVOKABLE void setElement(QString element, int i, int j);
    Matrix operator * (Matrix c);
    Matrix operator = (Matrix c);
    Matrix operator + (Matrix c);
    float** getMas();
private slots:
    void print();
signals:
    void matrixChanged();
    void sizeChanged();
};

#endif // MATRIX_H
