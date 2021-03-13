#include "library.h"
#include "Queue.h"

using namespace std;

int main() {
    Queue test;
    test.pushBack(12);
    test.pushBack(13);
    int i = test.getFront();
    cout << "I IS: " << i << endl;
    test.pushBack(14);
    test.popFront();
    i = test.getFront();
    cout << "I IS: " << i << endl;
}
