#include <iostream>
#include <algorithm> // Include this for 'sort'
#include <chrono>
#include <iomanip>
#include <vector> // Include this for using std::vector

using namespace std;
using namespace std::chrono;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool comp(const Item &a, const Item &b) {
        double r1 = static_cast<double>(a.value) / a.weight;
        double r2 = static_cast<double>(b.value) / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, const vector<Item>& arr) {
        vector<Item> items = arr; // Copy to a new vector for sorting
        sort(items.begin(), items.end(), comp);
        int curWeight = 0;
        double finalValue = 0.0;

        for (const auto& item : items) {
            if (curWeight + item.weight <= W) {
                curWeight += item.weight;
                finalValue += item.value;
            } else {
                int remain = W - curWeight;
                finalValue += (item.value / static_cast<double>(item.weight)) * remain;
                break;
            }
        }
        return finalValue;
    }
};

int main() {
    int n, weight;

    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> weight;

    vector<Item> arr(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    Solution obj;

    auto start_time = high_resolution_clock::now();
    double ans = obj.fractionalKnapsack(weight, arr);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "The maximum value is " << fixed << setprecision(2) << ans << endl;
    cout << "Elapsed Time: " << duration.count() << " microseconds" << endl;

    return 0;
}
