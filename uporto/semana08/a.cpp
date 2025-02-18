i#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream arquivo("caso_extremo.txt");
    int n = 1000;
    arquivo << n << " " << (n*(n-1))/2 << "\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            arquivo << i << " " << j << "\n";
        }
    }
    arquivo << "1\n1\n1000\n";
    arquivo.close();
    cout << "Arquivo gerado com sucesso!" << endl;
    return 0;
}
