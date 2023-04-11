#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <list>
#include "doctest.h"

using namespace std;

struct Element  
{
    int col;
    int value;
};

class SparseMatrix 
{
private:
    int rows;
    int cols;
    list<list<Element>> matrix;   
    //a list of lists of Element objects
    //each list represents a row of the matrix

public:
    SparseMatrix(int rows, int cols)  //створення пустої матриці
    {
        this->rows = rows;
        this->cols = cols;
        for (int i = 0; i < rows; i++) 
        {
            matrix.push_back(list<Element>());
        }
    }

    void insert(int row, int col, int value) 
    {
        if (row >= rows || col >= cols) 
        {
            cerr << "Invalid position" << endl;
            return;
        }
        if (value == 0) //розріджена матриця зберігає лише ненульові елементи
        {
            return;
        }
        auto it = matrix.begin(); //створення локальної змінної it та ініціалізація її ітератором, що вказує на початок списку рядків матриці
        advance(it, row); //дозволяє пересунути ітератор it на потрібний рядок у списку
        auto& rowList = *it; 
        // *it повертає список елементів у потрібному рядку матриці. Цей список потім зберігається у змінній rowList
        for (auto it = rowList.begin(); it != rowList.end(); it++) 
        {
            if (it->col == col) //дописати
            {
                it->value = value;
                return;
            }
        }
        rowList.push_back({ col, value }); //додаємо новий елемент до списку rowList
    }

    int get(int row, int col) 
    {
        if (row >= rows || col >= cols) 
        {
            cerr << "Invalid position" << endl;
            return 0;
        }
        auto it = matrix.begin();
        advance(it, row);
        auto& rowList = *it;
        for (auto& el : rowList) 
        {
            if (el.col == col) 
            {
                return el.value;
            }
        }
        return 0;  
    }

    void print() {
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                int value = get(i, j);
                cout << value<<"  ";
            }
            cout << endl;
        }
    }
};

TEST_CASE("Insert and get values in SparseMatrix")
{
    SparseMatrix matrix(3, 3);
    matrix.insert(0, 0, 1);
    matrix.insert(1, 1, 2);
    matrix.insert(2, 2, 3);
    matrix.insert(0, 2, 4);
    matrix.insert(1, 0, 5);
    matrix.insert(2, 1, 6);
    CHECK(matrix.get(0, 0) == 1);
    CHECK(matrix.get(1, 1) == 2);
    CHECK(matrix.get(2, 2) == 3);
    CHECK(matrix.get(0, 2) == 4);
    CHECK(matrix.get(1, 0) == 5);
    CHECK(matrix.get(2, 1) == 6);
    CHECK(matrix.get(1, 2) == 0);
    CHECK(matrix.get(2, 0) == 0);
}

TEST_CASE("Insert invalid values in SparseMatrix") 
{
    SparseMatrix matrix(3, 3);
    matrix.insert(3, 0, 1);
    matrix.insert(0, 3, 2);
    matrix.insert(4, 4, 3);
    matrix.insert(1, 1, 0);
    CHECK(matrix.get(3, 0) == 0);
    CHECK(matrix.get(0, 3) == 0);
    CHECK(matrix.get(4, 4) == 0);
    CHECK(matrix.get(1, 1) == 0);
}

TEST_CASE("Update value in SparseMatrix") {
    SparseMatrix matrix(2, 2);
    matrix.insert(0, 0, 1);
    matrix.insert(0, 1, 2);
    matrix.insert(1, 0, 3);
    matrix.insert(1, 1, 4);
    matrix.insert(0, 1, 5);
    matrix.insert(1, 0, 6);
    CHECK(matrix.get(0, 0) == 1);
    CHECK(matrix.get(0, 1) == 5);
    CHECK(matrix.get(1, 0) == 6);
    CHECK(matrix.get(1, 1) == 4);
    matrix.insert(0, 0, 7);
    matrix.insert(1, 1, 8);
    CHECK(matrix.get(0, 0) == 7);
    CHECK(matrix.get(1, 1) == 8);
}

