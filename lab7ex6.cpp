#include<iostream>
#include<cstdlib>
using namespace std;

template <class T> class Array2D {
    int r;
    int c;
    T** arr;
public:
    Array2D(T dimen[], T init) {
        r = dimen[0];
        c = dimen[1];
        if (r <= 0 || c <= 0) {
            cout << "error\n";
            exit(-1);
        }
        arr = new T * [r];
        for (int i = 0; i < r; i++) {
            arr[i] = new T[c]{};
            fill_n(arr[i], c, init);
        }
    }
    Array2D* operator*(Array2D<T>& otherArray) {
        if (c != otherArray.r) {
            cout << "error\n";
            return NULL;
        }
        Array2D<T>* result = new Array2D<T>(new int[2]{ r,otherArray.c }, 0);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < otherArray.c; j++)
                for (int k = 0; k < c; k++)
                    result->arr[i][j] += arr[i][k] * otherArray.arr[k][j];
        return result;
    }
    T*& operator[](int index) {
        if (r <= index || index < 0) {
            cout << "error\n";
            exit(-1);
        }
        return arr[index];
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
