#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <print>
#include <algorithm>

int main() {
    std::ifstream file("input1.txt");
    if (!file) {
        throw std::runtime_error("Nie mozna otworzyc pliku");
    }
    std::vector<std::string> ids;
    std::string line;

    while (std::getline(file, line)) {
        ids.push_back(line);
    }

    int n_dwa = 0;
    int n_trzy = 0;

    for (const auto& s : ids) {
        bool czy_dwa = false;
        bool czy_trzy = false;
        for (char c = 'a'; c <= 'z'; c++) {
            int f = std::count(s.begin(), s.end(), c);
            if (f == 2) czy_dwa = true;
            if (f == 3) czy_trzy = true;
        }
        if (czy_dwa) 
            n_dwa++;
        if (czy_trzy) 
            n_trzy++;
    }
    int wynik = n_dwa * n_trzy;
    std::println("{}", wynik);


    for (int i = 0; i < ids.size(); ++i) {
        for (int j = i + 1; j < ids.size(); ++j) {
            int rozny = 0;
            std::string znak;

            for (int k = 0; k < ids[i].size(); ++k) {
                if (ids[i][k] == ids[j][k]) {
                    znak.push_back(ids[i][k]);
                }
                else {
                    rozny++;
                    if (rozny > 1)
                        break;
                }
            }

            if (rozny == 1) {
                std::println("{}", znak);
                return 0;
            }
        }
    }

    return 0;
}