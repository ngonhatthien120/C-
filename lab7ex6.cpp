#include<iostream>
using namespace std;

template <class T> 
class Array2D {
    int r;
    int c;
    T** arr;
public:
    // TODO
    Array2D(T _dimen[2], T init) {
        this->r = _dimen[0];
        this->c = _dimen[1];
        this->arr = new T* [r];
        for (int i = 0; i < r; i++) {
            arr[i] = new T[c];
        }
        arr[r][c] = { init }; //lat coi lai
    }
    Array2D* operator*(Array2D& other) {
        Array2D* res ;
        r = this->r; c = other.c;
        res.arr = new T* [res.r];
        for (int i = 0; i < res.r; i++) {
            res.arr[i] = new T[res.c];
        }
        res.arr[res.r][res.c] = {};

        for (int i = 0; i < res.r; i++) {
            for (int j = 0; j < res.c; j++) {
                for (int k = 0; k < this->c; k++) {
                    res.arr[i][j] += arr[i][k] + other[k][j];
                }
            }
        }
        return *res;
    }
    /*T* Array2D <T>::operator [](int x, int y) {
        return this->arr[x][y];
    }*/
    Array2D* operator [] (int x) {
        return this->arr[x];
    }
    int getR() { return this->r; }
    int getC() { return this->c; }

    void disp() {
        for (int i = 0; i < this->r; i++) {
            for (int j = 0; j < this->c; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    Array2D* operator = ( int hi) {
        **ar = hi;
        return *this;
    }
    friend Array2D* operator [][](int x, int y);
    Array2D* operator [][](int x, int y) {
        return this->arr[x][y];
    }
    
};

int main() {
    int a1, b1, c1;
    int a2, b2, c2;
    int check1, check2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    cin >> check1 >> check2;
    Array2D<int>* p1 = new Array2D<int>(new int[2]{ a1,b1 }, c1);
    Array2D<int>* p2 = new Array2D<int>(new int[2]{ a2,b2 }, c2);

    if (a1 <= 0 || b1 <= 0 || a2 <= 0 || b2 <= 0) return -1;

    (*p1)[1][0] = check1;
    (*p2)[1][2] = check2;
    p1->disp();
    p2->disp();

    Array2D<int>* p3 = (*p1) * (*p2);
    if (p3 != NULL) p3->disp();
    return 0;
}
