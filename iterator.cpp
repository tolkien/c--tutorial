#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ifstream word_file("COPYING");
	istream_iterator<string> start(word_file), end;
	vector<string> words(start, end);

	cout << "\n\nwords as read\n";
	for (auto str : words)
		cout << str << "\t";

	sort(words.begin(), words.end());
	cout << "\n\nwords as sorted\n";
	for (vector<string>::iterator str = words.begin(); str != words.end(); ++str)
		cout << *str << "\t";
	cout << endl;

	return 0;
}