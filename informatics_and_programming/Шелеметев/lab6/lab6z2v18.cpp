#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void countsymbols(const string& a)
{
    // Создаем поток для чтения строки a
    istringstream iss(a);

    // Вектор для хранения симметричных слов
    vector<string> sym_words;

    // Перебираем слова из потока
    string word;
    while (iss >> word)
    {
        // Проверяем, является ли слово симметричным
        if (word.size() > 1 && equal(word.begin(), word.begin() + word.size() / 2, word.rbegin()))
        {
            // Если слово симметрично, добавляем его в вектор
            sym_words.push_back(word);
        }
    }

    // Выводим на экран найденные симметричные слова
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