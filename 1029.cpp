#include <iostream>
#include <vector>
#include <algorithm>  // for sort
using namespace std;

// 🔹 Step 1：定義 Student 結構
struct Student {
    string name;
    int score;

    // Step 2：建構子
    Student(string s, int n) : name(s), score(n) {}
};

// 🔹 Step 3：定義比較器（用 operator()）
struct CompareScore {
    bool operator()(const Student& a, const Student& b) {
        return a.score > b.score;  // 分數高的排前面（由大到小）
    }
};

// 🔹 Step 4：主程式
int main() {
    vector<Student> students = {
        {"Amy", 85},// same as Student("Amy",85)
        {"Bob", 92},
        {"Cathy", 78},
        {"David", 91}
    };

    students.push_back(Student("Ken",100));

    Student darren("darren",0);

    students.push_back(darren);

    // 用 sort + 比較器排序
    sort(students.begin(), students.end(), CompareScore());

    // 🔹 Step 5：印出結果
    cout << "排序後的學生名單：" << endl;
    for (const auto& s : students) {
        cout << s.name << " - " << s.score << endl;
    }

    return 0;
}
