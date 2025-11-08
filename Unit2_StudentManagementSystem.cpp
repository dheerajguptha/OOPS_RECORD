#include <iostream>
using namespace std;
class Student {
    string name;
    int roll;
    int marks[5];
    static int count; 

public:
    Student(string n, int r, int m[]) {
        name = n;
        roll = r;
        for(int i=0;i<5;i++) marks[i] = m[i];
        count++;
    }

    ~Student() {
        cout << "Student " << name << " removed." << endl;
    }

    inline int totalMarks() {
        int total=0;
        for(int i=0;i<5;i++) total += marks[i];
        return total;
    }

    string getName() { return name; }

    static void showCount() {
        cout << "Total students: " << count << endl;
    }
};

void printGrade(Student s) {
    int total = s.totalMarks();
    cout << s.getName() << "'s Grade: ";
    if(total >= 450) cout << "A+" << endl;
    else if(total >= 400) cout << "A" << endl;
    else if(total >= 350) cout << "B" << endl;
    else cout << "C" << endl;
}

Student topper(Student s[], int n) {
    int maxTotal = s[0].totalMarks();
    int index = 0;
    for(int i=1;i<n;i++) {
        if(s[i].totalMarks() > maxTotal) {
            maxTotal = s[i].totalMarks();
            index = i;
        }
    }
    return s[index];
}

int Student::count = 0;

int main() {
    int m1[5] = {90,85,88,92,80};
    int m2[5] = {78,80,82,79,85};
    int m3[5] = {95,90,93,88,92};

    Student s[3] = {
        Student("Ravi", 101, m1),
        Student("Sita", 102, m2),
        Student("Anu", 103, m3)
    };

    for(int i=0;i<3;i++) printGrade(s[i]);

    Student t = topper(s, 3);
    cout << "Topper: " << t.getName() << endl;

    Student::showCount();
    return 0;
}
