// Convergent series
// Sums the series 1 / (1 + n^2) term by term, printing each term and the
// running total, and stops once a term drops to 0.01 or below.

#include <iostream>
using namespace std;

int main()
{
    double x = 0;
    double s;

    for (int n = 1; ; n++) {
        s = 1.0 / (1 + n * n);
        x = x + s;
        cout << "n= " << n + 1 << ",s =" << s << ",x= " << x << endl;

        if (s <= 0.01) {
            break;
        }
    }

    return 0;
}
