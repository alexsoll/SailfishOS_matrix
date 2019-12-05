#include "matrix.h"
#include <QDebug>
using namespace std;


Matrix::Matrix() : QObject()
{
    size = 3;
    mas = new float*[size];
    for(int i=0; i<size; i++)
    {
        mas[i]=new float[size];
    }
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            mas[i][j]=1;
        }
    }
}

Matrix::Matrix(int size_) : QObject()
{
    size=size_;
    mas = new float*[size];
    for(int i=0; i<size; i++)
    {
        mas[i]=new float[size];
    }
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            mas[i][j]=1;
        }
    }
}

int Matrix::getSize()
{
    return this->size;
}

void Matrix::reload(int s)
{
    for (int i =0; i < this->size; i++) {
        delete[] mas[i];
    }
    delete[] mas;

    this->size = s;
    mas = new float*[size];
    for(int i=0; i<size; i++)
    {
        mas[i]=new float[size];
    }
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            mas[i][j]=1;
        }
    }
}

void Matrix::degree(int d)
{
    Matrix m2(this->size);
    m2 = (*this);
    for(int i=0; i<d-1; i++)
    {
        m2 = m2 * (*this);
    }
    *this = m2;
}

Matrix::Matrix(const Matrix& m)
{
    size=m.size;
    mas = new float*[size];
    for(int i=0; i<size; i++)
    {
        mas[i]=new float[size];
    }
    for(int i=0; i<m.size; i++)
    {
        for(int j=0; j<m.size; j++)
        {
            mas[i][j]=m.mas[i][j];
        }
    }
}

Matrix Matrix::operator = (Matrix c)
{
    size=c.size;
    for(int i=0; i<c.size; i++)
    {
        for(int j=0; j<c.size; j++)
        {
            mas[i][j]=c.mas[i][j];
        }
    }
    return *this;
}


float Matrix::getElement(int i, int j)
{
    return this->mas[i][j];
}

void Matrix::setElement(QString a, int i, int j)
{
    float a_ = a.toFloat();
    this->mas[i][j] = a_;
    emit matrixChanged();
}

void Matrix::print()
{
    int l = this->size;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            qDebug() << this->mas[i][j] << " ";
        }
        qDebug() << "\n";
    }
}

void Matrix::setSize(int s) {
    this->size = s;
    emit sizeChanged();
}

float** Matrix::getMas() {
    return this->mas;
}

Matrix Matrix::operator * (Matrix c)
{
    Matrix m2(c.size);
    size=c.size;
    float buf=0;
    int xk=0, yk=0;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            for(int k=0; k<size; k++)
            {
                buf+=this->mas[i][k]*c.mas[k][j];
            }
            m2.mas[i][j]=buf;
            buf=0;
            yk++;
        }
        yk=0;
        xk++;
    }
    return m2;
}

Matrix Matrix::operator + (Matrix c)
{
    Matrix m2(c.size);
    for(int i=0; i<c.size; i++)
    {
        for(int j=0; j<c.size; j++)
        {
            m2.mas[i][j]=this->mas[i][j]+c.mas[i][j];
        }
    }
    return m2;
}
