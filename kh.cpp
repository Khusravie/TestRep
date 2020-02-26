#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int Nod(int a, int b)
{
	while (a && b)
		if (a >= b)
			a %= b;
		else
			b %= a;
	return a | b;
}

bool Check(double begin, double end, int m, int k)
{
	double e = cos(k * M_PI / m);
	if ((e > begin) && (e < end))
		return true;
	else
		return false;
}

int main() {
	double c = 0, d = 0.5, b = 0.5, begin = 0, end = 0;
	int m[11] = {30, 18, 24, 12, 14, 16, 7, 8, 9, 10, 11}, counter = 0;
	begin = (-c * d - sqrt((b * b + c * c - 1) * (b * b + d * d - 1))) / (1 - (b * b));
	end = (-c * d + sqrt((b * b + c * c - 1) * (b * b + d * d - 1))) / (1 - (b * b));
	cout << begin << '\n' << end << '\n';
	for (int i = 0; i < 11; ++i) {
		counter = 0;
		for (int k = 2; k <= (m[i] / 2); k++) {
			if (Nod(k, m[i]) == 1)
				if (!Check(begin, end, m[i], k))
					counter++;
		}
		if (counter)
			cout << m[i] << " " << "false" << endl;
		else
			cout << m[i] << " " << "true" << endl;
	}
	return 0;
}
