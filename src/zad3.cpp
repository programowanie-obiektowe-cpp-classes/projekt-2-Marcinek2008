#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <print>

struct Claim {
    int id;
    int x, y;
    int w, h;
};



int main() {
    std::ifstream file("input2.txt");
    if (!file) {
        throw std::runtime_error("Nie mozna otworzyc pliku");
    }
    std::vector<Claim> claims;
    std::string line;
    while (std::getline(file, line)) {
        int id, x, y, w, h;
        char ch1, ch2, ch3, ch4;
        std::stringstream ss(line);
        ss >> ch1 >> id >> ch2 >> x >> ch3 >> y >> ch4 >> w >> ch4 >> h;
        claims.push_back({ id, x, y, w, h });
    }

    int rozmiar = 1000;
    std::vector<std::vector<int>> plotno(rozmiar, std::vector<int>(rozmiar, 0));

    for (const auto& c : claims) {
        for (int i = 0; i < c.w; ++i) {
            for (int j = 0; j < c.h; ++j) {
                plotno[c.x + i][c.y + j] +=1;
            }
        }
    }
    int nakladanie = 0;
    for (int i = 0; i < rozmiar; ++i)
        for (int j = 0; j < rozmiar; ++j)
            if (plotno[i][j] > 1)
                nakladanie++;

    std::println("{}", nakladanie);
    for (const auto& c : claims) {
        bool ok = true;
        for (int i = 0; i < c.w && ok; ++i) {
            for (int j = 0; j < c.h && ok; ++j) {
                if (plotno[c.x + i][c.y + j] > 1) {
                    ok = false;
                }
            }
        }
        if (ok) {
            std::println("{}",c.id);
            break;
        }
    }

    return 0;
}
