#include "library.h"
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> test;
    test.pushBack(13, 11);
    test.pushBack(12, 11);
    int i = test.getFront();
    cout << "I IS: " << i << endl;
    test.popFront();
    i = test.getFront();
    cout << "I IS: " << i << endl;

}
