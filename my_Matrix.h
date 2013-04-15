#ifndef MY_MATRIX_H
#define MY_MATRIX_H
#include <iostream>
#include <fstream>
#include <vector>

/*! Matrix class
 * Author: Alexandr Podgornyy
 * Description: Class for standart matrixes. Contains overloaded operators [], <<, +, -, +=, -=
 */
class Matrix
{
    typedef std::vector<int> row;
    typedef std::vector<row> matrix;
private:
    matrix m_matr;
public:
    Matrix (): m_matr(0, row(0)) {}
    Matrix (int cols, int rows): m_matr (cols, row(rows)) {}

    friend std::ostream & operator << (std::ostream &output, const Matrix &obj);

    const row & operator[](int position) const
    { return m_matr[position]; }
    row & operator[](int position)
    { return m_matr[position]; }
    Matrix operator+(const Matrix & rhs);
    Matrix operator-(const Matrix & rhs);
    Matrix operator+=(const Matrix & rhs);
    Matrix operator-=(const Matrix & rhs);
    int rows() const { return m_matr[0].size(); }
    int cols() const { return m_matr.size(); }

};

#endif // MY_MATRIX_H
