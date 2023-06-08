// Trent Fetzer(TJF20BJ) for
// COP4530 as Assignment 0
#include <iostream>
#include "list.hpp"

template <class T>
List<T> *sparseTranspose(List<T> *matrix, int arrSize, int &numRows)
{
    int largestRow= 0;
    int column;
    T curVal;
    Node<T> *currNode;
    List<T> *transposedList;

    for (int i = 0; i < arrSize; i++)
    {
        currNode = matrix[i].getHead();
        while (currNode != NULL)
        {

            column = currNode->getColNum();
            if (column > largestRow)
                largestRow = column;
            currNode = currNode->getNext();
        }
    }
    numRows = largestRow;
    transposedList = new List<T>[largestRow + 1];

    for (int i = 0; i < arrSize; ++i)
    {
        currNode = matrix[i].getHead();
        while (currNode != NULL)
        {
            column = currNode->getColNum();
            curVal = currNode->getVal();

            transposedList[column].addElement(curVal, i);

            currNode = currNode->getNext();
        }
    }
    return transposedList;
}

int main()
{
    int rowAmt = 0;
    int rowAmtTwo = 0;
    int sumAmt = 0;

    cout << "Integer Sparse Matrix:" << endl;
    cout << "Enter the number of rows: ";
    cin >> rowAmt;
    List<int> *intMatrix = new List<int>[rowAmt];
    cout << "Enter the values 1 row at a time. The first value will be the 0-value:" << endl;
    for (int i = 0; i < rowAmt; i++)
    {
        cin >> intMatrix[i];
    }
    cout << "The Sparse Matrix is:" << endl;
    for (int i = 0; i < rowAmt; i++)
    {
        cout << "Row " << i << ": ";
        intMatrix[i].print();
    }

    cout << "Enter the number of rows: ";
    cin >> rowAmtTwo;
    cout << "Enter the values 1 row at a time. The first value will be the 0-value:" << endl;
    List<int> *intMatrixTwo = new List<int>[rowAmtTwo];
    for (int i = 0; i < rowAmtTwo; i++)
    {
        cin >> intMatrixTwo[i];
    }
    cout << "The Sparse Matrix is:" << endl;
    for (int i = 0; i < rowAmtTwo; i++)
    {
        cout << "Row " << i << ": ";
        intMatrixTwo[i].print();
    }

    if (rowAmt > rowAmtTwo || rowAmt == rowAmtTwo)
    {
        sumAmt = rowAmt;
    }
    else if (rowAmtTwo > rowAmt)
    {
        sumAmt = rowAmtTwo;
    }

    List<int> *intMatrixSum = new List<int>[sumAmt];
    cout << "The sum is:" << endl;
    for (int i = 0; i < sumAmt; i++)
    {
        cout << "Row " << i << ": ";
        intMatrixSum[i] = intMatrix[i] + intMatrixTwo[i];
        intMatrixSum[i].print();
    }

    cout << "The transpose of the first int matrix is" << endl;

    int transposedListSize;
    List<int> *transposedList = sparseTranspose(intMatrix, rowAmt, transposedListSize);

    for (int i = 0; i <= transposedListSize; ++i)
    {
        cout << "Row " << i << ": ";
        transposedList[i].print();
    }
    cout << "The transpose of the second matrix is" << endl;
    int transposedListSizeTwo;
    List<int> *transposedListTwo = sparseTranspose(intMatrixTwo, rowAmtTwo, transposedListSizeTwo);

    for (int i = 0; i <= transposedListSizeTwo; i++)
    {
        cout << "Row " << i << ": ";
        transposedListTwo[i].print();
    }
    // // // //=================================================================
    // // // //=======================DOUBLE INPUT===============================
    // // // //=================================================================
    int doubleRowAmt = 0;
    int doubleRowAmtTwo = 0;
    int doubleRowSumAmt = 0;

    cout << "Double Sparse Matrix:" << endl;

    cout << "Enter the number of rows: ";
    cin >> doubleRowAmt;
    List<double> *doubleMatrix = new List<double>[doubleRowAmt];
    cout << "Enter the values 1 row at a time. The first value will be the 0-value:" << endl;
    for (int i = 0; i < doubleRowAmt; i++)
    {
        cin >> doubleMatrix[i];
    }
    cout << "The Sparse Matrix is:" << endl;
    for (int i = 0; i < doubleRowAmt; i++)
    {
        cout << "Row " << i << ": ";
        doubleMatrix[i].print();
    }

    cout << "Enter the number of rows: ";
    cin >> doubleRowAmtTwo;
    List<double> *doubleMatrixTwo = new List<double>[doubleRowAmtTwo];
    cout << "Enter the values 1 row at a time. The first value will be the 0-value:" << endl;

    for (int i = 0; i < doubleRowAmtTwo; i++)
    {
        cin >> doubleMatrixTwo[i];
    }
    cout << "The Sparse Matrix is:" << endl;
    for (int i = 0; i < doubleRowAmtTwo; i++)
    {
        cout << "Row " << i << ": ";
        doubleMatrixTwo[i].print();
    }

    if (doubleRowAmt > doubleRowAmtTwo || doubleRowAmt == doubleRowAmtTwo)
    {
        doubleRowSumAmt = doubleRowAmt;
    }
    else if (doubleRowAmtTwo > doubleRowAmt)
    {
        doubleRowSumAmt = doubleRowAmtTwo;
    }
    List<double> *doubleMatrixSum = new List<double>[doubleRowSumAmt];
    cout << "The sum is:" << endl;
    for (int i = 0; i < doubleRowSumAmt; i++)
    {
        doubleMatrixSum[i] = doubleMatrix[i] + doubleMatrixTwo[i];
        cout << "Row " << i << ": ";
        doubleMatrixSum[i].print();
    }

    int doubleTransSize;
    List<double> *transposedDoubleList = sparseTranspose(doubleMatrix, doubleRowAmt, doubleTransSize);

    cout << "The transpose of the first matrix is" << endl;
    for (int i = 0; i <= doubleTransSize; i++)
    {
        cout << "Row " << i << ": ";
        transposedDoubleList[i].print();
    }
    int doubleTransSizeTwo;
    List<double> *transposedDoubleListTwo = sparseTranspose(doubleMatrixTwo, doubleRowAmtTwo, doubleTransSizeTwo);

    cout << "The transpose of the second matrix is" << endl;
    for (int i = 0; i <= doubleTransSizeTwo; i++)
    {
        cout << "Row " << i << ": ";
        transposedDoubleListTwo[i].print();
    }
    //=================================================================
    //=======================STRING INPUT===============================
    //=================================================================

    int stringRowAmt = 0;
    int stringRowAmtTwo = 0;
    int stringSumAmt = 0;

    cout << "String Sparse Matrix:" << endl;

    cout << "Enter the number of rows: ";
    cin >> stringRowAmt;
    cout << "Enter the values 1 row at a time. The first value will be the 0-value:" << endl;
    List<string> *stringMatrix = new List<string>[stringRowAmt];
    for (int i = 0; i < stringRowAmt; i++)
    {
        cin >> stringMatrix[i];
    }
    cout << "The Sparse Matrix is:" << endl;
    for (int i = 0; i < stringRowAmt; i++)
    {
        cout << "Row " << i << ": ";
        stringMatrix[i].print();
    }

    cout << "Enter the number of rows: ";
    cin >> stringRowAmtTwo;
    List<string> *stringMatrixTwo = new List<string>[stringRowAmtTwo];
    cout << "Enter the values 1 row at a time. The first value will be the 0-value:" << endl;

    for (int i = 0; i < stringRowAmtTwo; i++)
    {
        cin >> stringMatrixTwo[i];
    }
    cout << "The Sparse Matrix is:" << endl;
    for (int i = 0; i < stringRowAmtTwo; i++)
    {
        cout << "Row " << i << ": ";
        stringMatrix[i].print();
    }

    if (stringRowAmt > stringRowAmtTwo || stringRowAmt == stringRowAmtTwo)
    {
        stringSumAmt = stringRowAmt;
    }
    else if (stringRowAmtTwo > stringRowAmt)
    {
        stringSumAmt = stringRowAmtTwo;
    }
    List<string> *stringMatrixSum = new List<string>[stringSumAmt];
    cout << "The sum is:" << endl;
    for (int i = 0; i < stringSumAmt; i++)
    {
        stringMatrixSum[i] = stringMatrix[i] + stringMatrixTwo[i];
        cout << "Row " << i << ": ";
        stringMatrixSum[i].print();
    }
    int stringTransSize;
    List<string> *transposedStringList = sparseTranspose(stringMatrix, stringRowAmt, stringTransSize);
    cout << "The transpose of the first matrix is" << endl;
    for (int i = 0; i <= stringTransSize; i++)
    {
        cout << "Row " << i << ": ";
        transposedStringList[i].print();
    }
    int stringTransSizeTwo;
    List<string> *transposedStringListTwo = sparseTranspose(stringMatrixTwo, stringRowAmtTwo, stringTransSizeTwo);

    cout << "The transpose of the second matrix is" << endl;
    for (int i = 0; i <= stringTransSizeTwo; i++)
    {
        cout << "Row " << i << ": ";
        transposedStringListTwo[i].print();
    }
}
