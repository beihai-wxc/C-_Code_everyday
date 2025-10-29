#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	int ID;
	double score;
	Student(int i = 0, double s = 0.0):ID(i),score(s){}
};

//�ȽϺ��������ɼ������򣨵�k��ѧ��˵����Ҫ����
bool cmp(const Student& a, const Student& b) {
	return a.score > b.score;
}

int main() {
	//ѧ������n����k��ѧ��
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

	//k��1��ʼ�������±�ȡk-1
	printf("%d %g\n", allStudent[k-1].ID,allStudent[k-1].score);

	return 0;
}