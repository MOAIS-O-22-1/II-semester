#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void countsymbols(const string& a)
{
    // ������� ����� ��� ������ ������ a
    istringstream iss(a);

    // ������ ��� �������� ������������ ����
    vector<string> sym_words;

    // ���������� ����� �� ������
    string word;
    while (iss >> word)
    {
        // ���������, �������� �� ����� ������������
        if (word.size() > 1 && equal(word.begin(), word.begin() + word.size() / 2, word.rbegin()))
        {
            // ���� ����� �����������, ��������� ��� � ������
            sym_words.push_back(word);
        }
    }

    // ������� �� ����� ��������� ������������ �����
    cout << "Symmetric words: ";
    for (const auto& w : sym_words)
    {
        cout << w << " ";
    }
    cout << endl;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    countsymbols(sentence);
}