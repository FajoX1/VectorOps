#include <iostream>
#include <vector>
#include <algorithm>

void insertionSort(std::vector<double>& array, bool ascending = true) {
    for (int i = 1; i < array.size(); ++i) {
        double key = array[i];
        int j = i - 1;
        while ((ascending && j >= 0 && array[j] > key) || (!ascending && j >= 0 && array[j] < key)) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

double sum(const std::vector<double>& array) {
    double total = 0.0;
    for (double num : array) {
        total += num;
    }
    return total;
}

double average(const std::vector<double>& array) {
    if (array.empty())
        return 0.0;

    return sum(array) / array.size();
}

double max(const std::vector<double>& array) {
    if (array.empty())
        return 0.0;

    return *std::max_element(array.begin(), array.end());
}

double min(const std::vector<double>& array) {
    if (array.empty())
        return 0.0;

    return *std::min_element(array.begin(), array.end());
}

void printArray(const std::vector<double>& array) {
    for (double num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<double> array;

    double input_nums;

    std::cout << "Enter numbers to fill the vector, to finish enter '0':" << std::endl;
    while (true) {
        std::cin >> input_nums;
        if (input_nums == 0) {
            break;
        }
        array.push_back(input_nums);
    }

    while (true) {

        std::cout << R"(Choose an operation:
1. Insertion sort in ascending order
2. Insertion sort in descending order
3. Calculate the sum of elements
4. Calculate the average value
5. Find the maximum element
6. Find the minimum element
7. Add an element to the end of the array
8. Modify an element by index
9. View the array

To exit, type '0'

> )";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 0:
            return 0;
        case 1:
            insertionSort(array);
            std::cout << "Sorted array in ascending order:\n";
            printArray(array);
            break;
        case 2:
            insertionSort(array, false);
            std::cout << "Sorted array in descending order:\n";
            printArray(array);
            break;
        case 3:
            std::cout << "Sum of elements: " << sum(array) << std::endl;
            break;
        case 4:
            std::cout << "Average value: " << average(array) << std::endl;
            break;
        case 5:
            std::cout << "Maximum element: " << max(array) << std::endl;
            break;
        case 6:
            std::cout << "Minimum element: " << min(array) << std::endl;
            break;
        case 7:
            std::cout << "Enter an element to add to the end of the array: ";
            std::cin >> input_nums;
            array.push_back(input_nums);
            std::cout << "Element successfully added to the end of the array." << std::endl;
            break;
        case 8:
            int index;
            std::cout << "Enter the index of the element to modify: ";
            std::cin >> index;
            if (index >= 0 && index < array.size()) {
                std::cout << "Enter the new value of the element: ";
                std::cin >> input_nums;
                array[index] = input_nums;
                std::cout << "Element successfully modified." << std::endl;
            }
            else {
                std::cout << "Invalid index." << std::endl;
            }
            break;
        case 9:
            std::cout << "Array elements:\n";
            printArray(array);
            break;
        default:
            std::cout << "Invalid choice.\n";
            return 1;
        }
    }

    return 0;
}
