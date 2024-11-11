#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

// Recursive function to calculate the nth Fibonacci number
int recursiveFibo(int n) {
    if (n <= 1)
        return n;
    return recursiveFibo(n - 1) + recursiveFibo(n - 2);
}

// Non-recursive function to print Fibonacci sequence up to n elements
void nonRecursiveFibo(int n) {
    int n1 = 0, n2 = 1, n3;
    if (n >= 1) cout << n1 << " ";
    if (n >= 2) cout << n2 << " ";
    for (int i = 2; i < n; ++i) {
        n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "\nNon-Recursive Fibonacci Series: ";
    auto start_time = high_resolution_clock::now();
    nonRecursiveFibo(n);
    auto end_time = high_resolution_clock::now();
    auto non_recursive_duration = duration_cast<microseconds>(end_time - start_time);
    cout << "\nElapsed Time (Non-Recursive): " << non_recursive_duration.count() << " microseconds" << endl;

    cout << "\nRecursive Fibonacci Series (first " << n << " elements): ";
    start_time = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        cout << recursiveFibo(i) << " ";
    }
    end_time = high_resolution_clock::now();
    auto recursive_duration = duration_cast<microseconds>(end_time - start_time);
    cout << "\nElapsed Time (Recursive): " << recursive_duration.count() << " microseconds" << endl;

    cout << "Estimated Space used: " << sizeof(int) * 3 << " bytes" << endl;

    return 0;
}
