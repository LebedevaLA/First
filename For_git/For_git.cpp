// For_git.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
using namespace std;

template <class T>

class Sorting
{

public:
    void Bubble_sort_up(vector<T>& a) {
        if (a.size() == 1)return;
        for (int i = 0;i < a.size();i++) {
            for (int j = i + 1;j < a.size();j++) {
                if (a[i] > a[j]) {
                    T tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
    }
    void Bubble_sort_down(vector<T>& a) {
        if (a.size() == 1)return;
        for (int i = 0;i < a.size();i++) {
            for (int j = i + 1;j < a.size();j++) {
                if (a[i] < a[j]) {
                    T tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
    }
    
    void Merge_up(vector<T>& a,int right,int left,int middle) {
        vector<T> tmp(right-left+1);
        int l_id = left;
        int r_id = middle + 1;;
        int i = 0;
        while (l_id <= middle && r_id <= right) {
            if (a[l_id] <= a[r_id]) {
                tmp[i] = a[l_id];
                l_id++;
            }
            else {
                tmp[i] = a[r_id];
                r_id++;
            }
            i++;
        }
        while (r_id <= right) {
            tmp[i] = a[r_id];
            i++;
            r_id++;
        }
        while (l_id <= middle) {
            tmp[i] = a[l_id];
            i++;
            l_id++;
        }
        for (int j = 0;j < tmp.size();j++) {
            a[left + j] = tmp[j];
        }
    }
    void Merge_sort_up(vector<T>& a,int left,int right) {
        if (a.size() == 1)return;
        if (left<right){
        int middle = (right + left) / 2;
        Merge_sort_up(a, left, middle);
        Merge_sort_up(a, middle + 1,right);
        Merge_up(a,right,left,middle);
        }
    }

    void Merge_down(vector<T>& a, int right, int left, int middle) {
        vector<T> tmp(right - left + 1);
        int l_id = left;
        int r_id = middle + 1;;
        int i = 0;
        while (l_id <= middle && r_id <= right) {
            if (a[l_id] >= a[r_id]) {
                tmp[i] = a[l_id];
                l_id++;
            }
            else {
                tmp[i] = a[r_id];
                r_id++;
            }
            i++;
        }
        while (r_id <= right) {
            tmp[i] = a[r_id];
            i++;
            r_id++;
        }
        while (l_id <= middle) {
            tmp[i] = a[l_id];
            i++;
            l_id++;
        }
        for (int j = 0;j < tmp.size();j++) {
            a[left + j] = tmp[j];
        }
    }
    void Merge_sort_down(vector<T>& a, int left, int right) {
        if (a.size() == 1)return;
        if (left < right) {
            int middle = (right + left) / 2;
            Merge_sort_down(a, left, middle);
            Merge_sort_down(a, middle + 1, right);
            Merge_down(a, right, left, middle);
        }
    }
    void Bogo_sort_up(vector<T>& a) {
        srand(time(NULL));
        while (Is_sorted_up(a) == false) {
            int random = rand() % (a.size() - 1);
            for (int i = 0;i < a.size();i++) {
                T tmp;
                tmp = a[i];
                a[i] = a[random];
                a[random] = tmp;
            }
        }
    }
    bool Is_sorted_up(vector<T>& a) {
        for (int i = 1;i < a.size();i++) {
            if (a[i] < a[i - 1])return(false);
        }
        return(true);
    }
    void Print(vector<T> a) {
        for (int i = 0;i < a.size();i++) {
            cout << a[i] <<" ";
        }
        cout << endl;
    }
};

int main()
{
    Sorting<int> a;
    vector<int>z{ 5,4,3,6,2,1,6 };
    a.Bogo_sort_up(z);
    a.Print(z);
    vector<int>b{ 5,5,5,5,1,4,7,8 };
    a.Merge_sort_up(b,0,b.size()-1);
    a.Print(b);
    a.Merge_sort_down(b,0,b.size()-1);
    a.Print(b);
    vector<int>c{ 23,4,7,8,0,6 };
    a.Bubble_sort_up(c);
    a.Print(c);
    a.Bubble_sort_down(c);
    a.Print(c);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
