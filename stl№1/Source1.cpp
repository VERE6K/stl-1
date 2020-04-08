#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//структура по ученику
const struct student {
	string name{};
	double avg{};
};

//функция сортировки вектора через bool пееменную пузырьком
vector<student> wsortbyavg(vector<student> vec) {
	if (vec.size() > 1) {
		while (true) {
			bool mist = false;
			for (int i = 0; i < vec.size() - 1; ++i) {
				if (vec[i].avg < vec[i + 1].avg) {
					mist = true;
					swap(vec[i], vec[i + 1]);
				}
			}
			if (mist == false)
				break;
		}
	}
	return vec;
}


//функция заполнения вектора
vector<student> filling() {
	vector<student> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		student new_s{};
		int sum{};
		cin >> new_s.name;
		{
			string last_name{};
			cin >> last_name;
			new_s.name = new_s.name + ' ' + last_name;
		}
		for (int j = 0; j < 3; ++j) {
			int mark = 0;
			cin >> mark;
			sum += mark;
		}
		new_s.avg = double(sum) / 3;
		vec.push_back(new_s);
	}
	return vec;
}

//объединение функция в main
int main() {
	vector<student> v = wsortbyavg(filling());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i].name << ' ' << endl;
}