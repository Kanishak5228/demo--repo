#include <iostream>
#include <cstdlib>
#include <ctime>

#define ll long long int

using namespace std;

void transmission(ll& i, ll& N, ll& tf, ll& tt) {
    while (i <= tf) {
        int z = 0;

        for (int k = i; k < i + N && k <= tf; k++) {
            cout << "Sending frame " << k << endl;
            tt++;
        }

        for (int k = i; k < i + N && k <= tf; k++) {
            int f = rand() % 2;
            if (!f) {
                cout << "Frame acknowledgement for frame " << k << endl;
                z++;
            } else {
                cout << "Timeout for frame " << k << " not received" << endl;
                cout << "Retransmit window" << endl;
                break;
            }
        }

        cout << "\n";
        i = i + z;
    }
}

int main() {
    ll tf, n, tt = 0;
    srand(time(NULL));

    cout << "Number of frames: ";
    cin >> tf;
    cout << "Window size: ";
    cin >> n;

    ll i = 1;

    transmission(i, n, tf, tt);

    cout << "Frames sent and resent: " << tt << endl;

    return 0;
}