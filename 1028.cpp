#include <iostream>
using namespace std;

struct MyStruct {
    int value;
    int test;

    // 🔹 建構子：建立物件時會自動被呼叫
    MyStruct(int v) {
        value = v;
        test = value+1;
        cout << "建構子被呼叫！value 設為 " << value << endl;
    }

    // 🔹 operator()：只有當你明確呼叫 obj(...) 才會執行
    void operator()() {
        cout << "operator() 被呼叫！value 是 " <<  test << endl;
    }

     void print() { cout << value << "," << test; }
};

struct Student {
    string name;
    int score;

    // 🔹 建構子：建立物件時會自動被呼叫
    Student() {
        name = "unknown";
        score = 0;
        cout << "建構子被呼叫！value 設為 " << name << ":" << score << endl;
    }

    Student(string s) : name(s) {
        score = 0;
        cout << "建構子被呼叫！value 設為 " << name << ":" << score << endl;
    }

    Student(int n) : score(n) {
        
        cout << "建構子被呼叫！value 設為 " << name << ":" << score << endl;
    }

    Student(string s, int n) : name(s), score(n) {
        
        cout << "建構子被呼叫！value 設為 " << name << ":" << score << endl;
    }

    // 🔹 operator()：只有當你明確呼叫 obj(...) 才會執行
    void operator()() {
        cout << "operator() 被呼叫！value 是 " <<  score << endl;
    }

     void print() { cout << name << "," << score; }
};

int main() {
    // 建立一個 MyStruct 物件，會自動呼叫建構子
    //MyStruct a(8);

    // 呼叫 operator()，像函數一樣使用物件
    //a();

    //a.print();

    Student a;
    Student b("darren");
    Student c("ken",5);
    Student d(10);

    a();
    b();
    c();
    d();


    return 0;
}
