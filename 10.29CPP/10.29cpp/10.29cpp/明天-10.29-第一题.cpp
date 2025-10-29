#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	int ID;
	double score;
	Student(int i = 0, double s = 0.0):ID(i),score(s){}
};

//比较函数：按成绩降序序（第k名学生说明需要排序）
bool cmp(const Student& a, const Student& b) {
	return a.score > b.score;
}

int main() {
	//学生人数n，第k名学生
	int n, k;
	cin >> n >> k;

	vector<Student> allStudent;

	for (int i = 0; i < n; i++) {
		int ID;
		double score;
		cin >> ID >> score;
		allStudent.push_back(Student(ID, score));
	}

	sort(allStudent.begin(), allStudent.end(), cmp);

	//k从1开始，所以下标取k-1
	printf("%d %g\n", allStudent[k-1].ID,allStudent[k-1].score);

	return 0;
}