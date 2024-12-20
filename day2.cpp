// Name: Nitu
//UID- 22BCS10707
//Section- 631/B



// Question 1: Bubble Sort 
#include <iostream>
#include <vector>
using namespace std;

class BubbleSort {
private:
    vector<int> data;

public:
    void inputData() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            data.push_back(num);
        }
    }

    void sort() {
        for (size_t i = 0; i < data.size() - 1; i++) {
            for (size_t j = 0; j < data.size() - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }

    void display() const {
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    BubbleSort sorter;
    sorter.inputData();
    sorter.sort();
    sorter.display();
    return 0;
}


// Question 2: Pascal's Triangle
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascal(int numRows) {
    vector<vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; ++i) {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}

int main() {
    int numRows = 5;
    vector<vector<int>> triangle = generatePascal(numRows);
    for (auto& row : triangle) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }
    return 0;
}

// Question 3: Insertion sort 
#include <iostream>
#include <vector>
using namespace std;

class InsertionSort {
private:
    vector<int> data;

public:
    
    void inputData() {
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        cout << "Enter the elements:" << endl;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            data.push_back(num);
        }
    }

    void sort() {
        for (size_t i = 1; i < data.size(); i++) {
            int key = data[i];
            int j = i - 1;

            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }

    
    void display() const {
        cout << "Sorted list: ";
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main() {
    InsertionSort sorter;

    sorter.inputData(); 
    sorter.sort();      
    sorter.display();   

    return 0;
}

// Question 4: Maximum Number of Happy Groups
#include <iostream>
#include <vector>
using namespace std;

int maxHappyGroups(int batchSize, vector<int>& groups) {
    vector<int> count(batchSize, 0);
    int happy = 0;
    for (int g : groups) {
        int remainder = g % batchSize;
        if (remainder == 0) ++happy;
        else if (count[batchSize - remainder] > 0) {
            ++happy;
            --count[batchSize - remainder];
        } else ++count[remainder];
    }
    return happy + count[0];
}

int main() {
    vector<int> groups = {1, 2, 3, 4, 5, 6};
    int batchSize = 3;
    cout << "Maximum Happy Groups: " << maxHappyGroups(batchSize, groups) << endl;
    return 0;
}

// Question 5: Minimum Time to Finish All Jobs
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool canAssign(vector<int>& jobs, vector<int>& workers, int idx, int maxTime) {
    if (idx == jobs.size()) return true;
    for (int i = 0; i < workers.size(); ++i) {
        if (workers[i] + jobs[idx] > maxTime) continue;
        workers[i] += jobs[idx];
        if (canAssign(jobs, workers, idx + 1, maxTime)) return true;
        workers[i] -= jobs[idx];
        if (workers[i] == 0) break;
    }
    return false;
}

int minimumTime(vector<int>& jobs, int k) {
    sort(jobs.rbegin(), jobs.rend());
    int low = jobs[0], high = accumulate(jobs.begin(), jobs.end(), 0);
    while (low < high) {
        int mid = (low + high) / 2;
        vector<int> workers(k, 0);
        if (canAssign(jobs, workers, 0, mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> jobs = {1, 2, 4, 7, 8};
    int k = 2;
    cout << "Minimum Time: " << minimumTime(jobs, k) << endl;
    return 0;
}
