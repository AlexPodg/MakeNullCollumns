#include <QCoreApplication>
#include <iostream>
#include <my_Matrix.h>

int zeroColl (Matrix &fCMatrix, const int noColumn);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Matrix CMatrix (5, 5);
    //Read matrix from file
    std::ifstream file;
    file.open("matrix.txt");
    if (!file.is_open())
    {
        std::cerr << "Can't open file";
        return 0;
    }

    for (int r = 0; r<CMatrix.rows(); r++)
        for (int c = 0; c<CMatrix.cols(); c++)
            file >> CMatrix [r][c];

    file.close();
    Matrix CMatrix2 = CMatrix;
    CMatrix2 += CMatrix2;
    std::cout << "Before" << std::endl;
    std::cout << CMatrix2 << std::endl;

    zeroColl (CMatrix, 1);
    zeroColl (CMatrix, 3);
    zeroColl (CMatrix, 5);

    std::cout << "After" << std::endl;
    std::cout << CMatrix << std::endl;

    return a.exec();
}

//Zero selected collumn
int zeroColl (Matrix &fCMatrix, const int noColumn)
{
    if (noColumn>(fCMatrix.cols()-1))
    {
        std::cerr << "zeroColl: noColumn= " << noColumn << "is greater than number of columns in matrix";
        return 0;
    }
    for (int r = 0; r<fCMatrix.rows(); r++)
        for (int c = 0; c<fCMatrix.cols(); c++)
            if (c == noColumn)
                fCMatrix[r][c] = 0;
    return 1;
}
