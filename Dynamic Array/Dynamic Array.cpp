

#include <iostream>
#include "List.h"
using namespace std;

void PressToContinue() {
    cout << endl << endl << "~~~~~~ Press any button to continue ~~~~~~" << endl;
    cin.get();
}

int main()
{
    //LinkedList

    List integers;

    cout << endl << "Welcome to The Doubly Linked list:" << endl << endl;

    cout << "Currently the list is empty" << endl << endl;
    integers.PrintList();

#pragma region Adding Methods

    cout << "Adding Methods: " << endl << "\tPushFront(value)"
        << endl << "\tPushBack(value)" << endl << "\tInsert(nodeToBeInsertedAfter, value)";

    PressToContinue();

    cout << "\tCalled PushFront() 5 times" << endl << endl;
    for (int i = 0; i < 5; i++) {
        integers.PushFront((i * 10) + 4);
    }

    integers.PrintList();
    PressToContinue();

    cout << "\tCalled PushBack() 5 times" << endl << endl;
    for (int i = 0; i < 5; i++) {
        integers.PushBack((i * 10) + 7);
    }

    integers.PrintList();
    PressToContinue();

    cout << "\tCalled Insert() where 19 is to be inserted after 34" << endl << endl;
    integers.Insert(34, 19);
    cout << "\tCalled Insert() where 234 is to be inserted after 7" << endl << endl;
    integers.Insert(7, 234);
    cout << "\tCalled Insert() where 401 is to be inserted after 19" << endl << endl;
    integers.Insert(19, 401);

    integers.PrintList();
    PressToContinue();

#pragma endregion

#pragma region Removal Methods

    cout << "Removal Methods: " << endl << "\tPopFront()"
        << endl << "\tPopBack()" << endl << "\tRemove(value)";

    PressToContinue();

    cout << "\tCalled PopFront() 2 times" << endl << endl;
    for (int i = 0; i < 2; i++) {
        integers.PopFront();
    }

    integers.PrintList();
    PressToContinue();

    cout << "\tCalled PopBack() 2 times" << endl << endl;
    for (int i = 0; i < 2; i++) {
        integers.PopBack();
    }

    integers.PrintList();
    PressToContinue();

    cout << "\tCalled Remove() on 7 and 24" << endl << endl;
    integers.Remove(7);
    integers.Remove(24);

    integers.PrintList();
    PressToContinue();


#pragma endregion

#pragma region Sorting

    cout << "Sorting Methods: " << endl << "\tInsertionSort()" << endl;
    integers.InsertionSort();

    integers.PrintList();
    PressToContinue();

#pragma endregion

    cout << "This is all the functionality of this Doubly Linked List" << endl << endl;
    cin.get();
    integers.Clear();
}
