#include <list>
#include <iostream>
using namespace std;

void printList(const list<int>& lst) {
    for (int n : lst) cout << n << " ";
    cout << endl;
}

void customSort(list<int>& lst) {
    bool swapped;
    do {
        swapped = false;
        for (auto it = lst.begin(); it != prev(lst.end()); ++it) {
            if (*it > *next(it)) {
                swap(*it, *next(it));
                swapped = true;
            }
        }
    } while (swapped);
}

list<int> mergeLists(const list<int>& list1, const list<int>& list2) {
    list<int> mergedList;
    auto it1 = list1.begin();
    auto it2 = list2.begin();

    while (it1 != list1.end() && it2 != list2.end()) {
        if (*it1 < *it2) {
            mergedList.push_back(*it1);
            ++it1;
        } else {
            mergedList.push_back(*it2);
            ++it2;
        }
    }

    while (it1 != list1.end()) {
        mergedList.push_back(*it1);
        ++it1;
    }

    while (it2 != list2.end()) {
        mergedList.push_back(*it2);
        ++it2;
    }

    return mergedList;
}

int main() {
    list<int> myList = {31, 4, 9, 2, 45};
    cout << "Original list: ";
    printList(myList);

    customSort(myList);
    cout << "Sorted list: ";
    printList(myList);

    list<int> list1 = {1, 3, 5, 7};
    list<int> list2 = {2, 4, 6, 8};
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    list<int> mergedList = mergeLists(list1, list2);
    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
