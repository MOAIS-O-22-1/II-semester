#include <iostream>
#include <fstream>

using namespace std;

class InvalidAction : public exception {
    public:
        const char* what() const noexcept override {
            return "File cannot be modified!";
        }
};

int main() {

    try {
        fstream file;
        file.open("input.txt", ios_base::in);

        if (file << "") throw InvalidAction();

        file.close();
    }

    catch (const InvalidAction& e) {
        cout << e.what() << endl;
    }

    return 0;

}