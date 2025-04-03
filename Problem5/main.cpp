#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class StatisticalCalculation {
private:
    T* data;
    int size;

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }

public:
    StatisticalCalculation() : data(nullptr), size(0) {}

    ~StatisticalCalculation() {
        delete[] data;
    }

    void inputData(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            exit(1);
        }

        file >> size; // Read size from file
        data = new T[size]; // Allocate memory

        for (int i = 0; i < size; i++) {
            file >> data[i];
        }
        file.close();
    }

    T findMin() {
        T min = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < min) min = data[i];
        }
        return min;
    }

    T findMax() {
        T max = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > max) max = data[i];
        }
        return max;
    }

    double findMean() {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum / size;
    }

    T findSummation() {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum;
    }

    double findMedian() {
        sort();
        if (size % 2 == 0)
            return (data[size / 2 - 1] + data[size / 2]) / 2.0;
        else
            return static_cast<double>(data[size / 2]);
    }

    void displayArray() {
        sort();
        cout << "Sorted Array: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void statisticsMenu() {
        int choice;
        char cont;
        do {
            cout << "\nSelect a statistical calculation:\n";
            cout << "1. Find Median\n";
            cout << "2. Find Minimum\n";
            cout << "3. Find Maximum\n";
            cout << "4. Find Mean\n";
            cout << "5. Find Summation\n";
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            switch (choice) {
                case 1: cout << "Median: " << findMedian() << endl; break;
                case 2: cout << "Minimum: " << findMin() << endl; break;
                case 3: cout << "Maximum: " << findMax() << endl; break;
                case 4: cout << "Mean: " << findMean() << endl; break;
                case 5: cout << "Summation: " << findSummation() << endl; break;
                default: cout << "Invalid choice!\n";
            }

            cout << "Do you want another calculation? (y/n): ";
            cin >> cont;
        } while (cont == 'y' || cont == 'Y');
    }
};

int main() {
    int typeChoice;
    string filename;

    cout << "Select data type:\n";
    cout << "1. Integer\n";
    cout << "2. Float\n";
    cout << "3. Double\n";
    cout << "Enter your choice (1-3): ";
    cin >> typeChoice;

    if (typeChoice < 1 || typeChoice > 3) {
        cout << "Invalid selection! Exiting...\n";
        return 0;
    }

    cout << "Enter the filename containing input data: ";
    cin >> filename;

    if (typeChoice == 1) {
        StatisticalCalculation<int> calc;
        calc.inputData(filename);
        calc.statisticsMenu();
    } else if (typeChoice == 2) {
        StatisticalCalculation<float> calc;
        calc.inputData(filename);
        calc.statisticsMenu();
    } else if (typeChoice == 3) {
        StatisticalCalculation<double> calc;
        calc.inputData(filename);
        calc.statisticsMenu();
    }

    return 0;
}
