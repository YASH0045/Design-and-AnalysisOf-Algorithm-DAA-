#include <iostream>
#include <algorithm>  // Needed for the sort function
using namespace std;

// Structure to describe the items in the knapsack
struct Item {
    int profit;
    int weight;
};

// Comparison function to sort items according to value/weight ratio
bool compare(Item &a, Item &b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort items based on the ratio value/weight
    sort(arr, arr + n, compare);

    double totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            // If the item can fit completely in the knapsack, take it
            currentWeight += arr[i].weight;
            totalProfit += arr[i].profit;
            cout << "Taking full item " << i + 1 << " (profit: " << arr[i].profit << ", weight: " << arr[i].weight << ")" << endl;
        } else {
            // If the item can't fit completely, take the fractional part
            int remainingWeight = W - currentWeight;
            totalProfit += arr[i].profit * ((double)remainingWeight / arr[i].weight);
            cout << "Taking " << ((double)remainingWeight / arr[i].weight) * 100 << "% of item " << i + 1
                 << " (value: " << arr[i].profit << ", weight: " << arr[i].weight << ")" << endl;
            break;  // Knapsack is full
        }
    }

    return totalProfit;
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the profit and weight for item " << i + 1 << ": ";
        cin >> arr[i].profit >> arr[i].weight;
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    // Calculate maximum value
    double maxProfit = fractionalKnapsack(W, arr, n);

    cout << "Maximum profit in the knapsack = " << maxProfit << endl;

    return 0;
}

