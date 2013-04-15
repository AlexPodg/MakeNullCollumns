#include <my_Matrix.h>

std::ostream & operator << (std::ostream &output, const Matrix &obj)
{
    for (int i = 0; i<obj.rows(); i++)
    {
        for (int j = 0; j<obj.cols(); j++) {
            output << obj[i][j] << " ";
        }
        output << "\n";
    }
    return output;
}

Matrix Matrix::operator+(const Matrix & rhs)
{
    if (this->cols()!=rhs.cols() || this->rows()!=rhs.rows())
    {
        throw ("Wrong size of matrix");
    }
    else
    {
        Matrix CSum(this->cols(),this->rows());
        for (int i = 0; i<CSum.rows(); i++)
        {
            for (int j = 0; j<CSum.cols(); j++) {
                CSum[i][j] = m_matr[i][j]+rhs[i][j];
            }

        }
        return CSum;
    }
}

Matrix Matrix::operator-(const Matrix & rhs)
{
    if (this->cols()!=rhs.cols() || this->rows()!=rhs.rows())
    {
        throw ("Wrong size of matrix");
    }
    else
    {
        Matrix CSum(this->cols(),this->rows());
        for (int i = 0; i<CSum.rows(); i++)
        {
            for (int j = 0; j<CSum.cols(); j++) {
                CSum[i][j] = m_matr[i][j]-rhs[i][j];
            }

        }
        return CSum;
    }
}

Matrix Matrix::operator+=(const Matrix & rhs)
{
    if (this->cols()!=rhs.cols() || this->rows()!=rhs.rows())
    {
        throw ("Wrong size of matrix");
    }
    else
    {
        for (int i = 0; i<rhs.rows(); i++)
        {
            for (int j = 0; j<rhs.cols(); j++) {
                m_matr[i][j] = m_matr[i][j]+rhs[i][j];
            }
        }
        return *this;
    }
}

Matrix Matrix::operator-=(const Matrix & rhs)
{
    if (this->cols()!=rhs.cols() || this->rows()!=rhs.rows())
    {
        throw ("Wrong size of matrix");
    }
    else
    {
        for (int i = 0; i<rhs.rows(); i++)
        {
            for (int j = 0; j<rhs.cols(); j++) {
                m_matr[i][j] = m_matr[i][j]-rhs[i][j];
            }
        }
        return *this;
    }
}
