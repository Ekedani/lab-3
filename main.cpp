#include "library.h"
#include "Queue.h"

using namespace std;

int main() {
    Queue test;
    test.pushBack(12);
    int i = test.getFront();
    cout << "I IS: " << i << endl;
}
