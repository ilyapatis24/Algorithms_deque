#include <iostream>
using namespace std;


void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    cout << "Динамический массив:";
    for (int i = 0; i < logical_size; ++i) {
        cout << " " << arr[i];
    }
    for (int i = logical_size; i < actual_size; ++i) {
        cout << " " << "_";
    }
    cout << endl;
}

void ignoreLine()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void fill_array(int* arr, int logical_size) {
    for (int i = 0; i < logical_size; ++i) {
        cout << "Введите arr[" << i << "]: ";
        cin >> arr[i];
    }
}
int main(int argc, char** argv) {
    system("chcp 1251");
    int logical_size = 0, actual_size = 0;
    bool userError = false;
    do {
        cout << "Введите фактичеcкий размер массива: ";
        cin >> actual_size;

        while (!cin.good() || actual_size <= 0) {
            ignoreLine();
            cout << "Вы ввели неверные даннные.Размер массива положительное целое число.\n";
        }
        userError = true;
    } while (!userError);

    do {
        cout << "Введите логический размер массива: ";
        cin >> logical_size;

        while (!cin.good() || logical_size <= 0) {
            ignoreLine();
            cout << "Вы ввели неверные даннные.Размер массива положительное целое число.\n";
            userError = false;
        }
   
        if (logical_size > actual_size)
        {
            cout << "Ошибка! Логический размер массива не может превышать фактический!" << endl;
            userError = false;
        }
        else
        {
            userError = true;
        }

    } while (!userError);
    int* arr = new int[actual_size] {};
    fill_array(arr, logical_size);
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
    arr = nullptr;
    return 0;
}