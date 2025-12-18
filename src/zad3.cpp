#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <print>

struct Point {
	double x, y;
	double vx, vy;
};

int main() {
	std::ifstream file("input3.txt");
	if (!file) {
		throw std::runtime_error("Nie mozna otworzyc pliku");
	}
	std::vector<Point> punkty;
	std::string line;

	while (std::getline(file, line)) {
		for (char& c : line) {
			if (!(isdigit(c) || c == '-'))
				c = ' ';
			
		}

		std::stringstream ss(line);
		Point p;
		ss >> p.x >> p.y >> p.vx >> p.vy;
		punkty.push_back(p);
	}

	double popPole = 100000000000000000;
	int t = 0;

	while (true) {
		for (auto& p : punkty) {
			p.x += p.vx;
			p.y += p.vy;
		}
		t += 1;

		double minX = punkty[0].x;
		double minY = punkty[0].y;
		double maxX = punkty[0].x;
		double maxY = punkty[0].y;
		for (auto& p : punkty) {
			minX = std::min(minX, p.x);
			minY = std::min(minY, p.y);
			maxX = std::max(maxX, p.x);
			maxY = std::max(maxY, p.y);
		}

		double pole = (maxX - minX) * (maxY - minY);

		if (pole > popPole) {
			for (auto& p : punkty) {
				p.x -= p.vx;
				p.y -= p.vy;
			}
			t -= 1;
			break;
		}
		popPole = pole;
	}
		double minX = punkty[0].x;
		double minY = punkty[0].y;
		double maxX = punkty[0].x;
		double maxY = punkty[0].y;
	for (const auto& p : punkty) {
		minX = std::min(minX, p.x);
		maxX = std::max(maxX, p.x);
		minY = std::min(minY, p.y);
		maxY = std::max(maxY, p.y);
	}

	int szerokosc = int(maxX - minX + 1);
	int wysokosc = int(maxY - minY + 1);

	std::vector<std::string> siatka(wysokosc, std::string(szerokosc, '.'));

	for (const auto& p : punkty) {
		int x = int(p.x - minX);
		int y = int(p.y - minY);
		if (x >= 0 && x < szerokosc && y >= 0 && y < wysokosc)
			siatka[y][x] = '#';
	}


	for (const auto& wiersz : siatka)
	{
		std::println("{}", wiersz);
	}
	std::println("Czas: {}", t);
	return 0;
}