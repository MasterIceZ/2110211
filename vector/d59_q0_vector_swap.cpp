#include <iostream>
#include <vector>

using namespace std;

void vector_swap(vector<int> &v1,vector<int> &v2, int start1, int end1, int start2, int end2) {
	vector<int> helper1, helper2;
	for(int i=0; i<start1; ++i) {
		helper1.emplace_back(v1[i]);
	}
	for(int i=start2; i<end2; ++i) {
		helper1.emplace_back(v2[i]);
	}
	for(int i=end1; i<(int) v1.size(); ++i) {
		helper1.emplace_back(v1[i]);
	}
	for(int i=0; i<start2; ++i) {
		helper2.emplace_back(v2[i]);
	}
	for(int i=start1; i<end1; ++i) {
		helper2.emplace_back(v1[i]);
	}
	for(int i=end2; i<(int) v2.size(); ++i) {
		helper2.emplace_back(v2[i]);
	}
	v1 = helper1;
	v2 = helper2;
}

int main() {
	//read input
	int n,c;
	vector<int>v1,v2;
	cin >> n; //number of v1
	for (int i = 0;i < n;i++) {
		cin >> c;
		v1.push_back(c);
	}
	cin >> n; //number of v2
	for (int i = 0;i < n;i++) {
		cin >> c;
		v2.push_back(c);
	}
	int s1,e1,s2,e2; //position
	cin >> s1 >> e1 >> s2 >> e2;
	//call the function
	vector_swap(v1,v2,s1,e1,s2,e2);
	//display content of the stack
	cout << "v1 has " << v1.size() << endl;
	for (auto &x : v1) { cout << x << " "; }
	cout << endl;
	//display content of the stack
	cout << "v2 has " << v2.size() << endl;
	for (auto &x : v2) { cout << x << " "; }
	cout << endl;
}
