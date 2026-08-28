

// Carolina Vidósola Guzmán
// A01287373

# include <iostream>
# include <vector>

using namespace std;

template <typename T>
void swapSort(vector<T> &list){
    int n = list.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }

    return ;
}

template <typename T>
void bubbleSort(vector<T> & list){
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }

    return ;
}

int main() {

vector<double> list = {64, 34, 25, 12, 11.4, 11.6, 90};
swapSort(list);

cout << "Sorted swap: \n";
for (int i = 0; i < list.size(); i++) {
    cout << list[i] << " ";
}
cout << endl;

cout << "Sorted bubble: \n";
bubbleSort(list);
for (int i = 0; i < list.size(); i++) {
    cout << list[i] << " ";
}

    return 0;
}