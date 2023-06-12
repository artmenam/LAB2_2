#include <iostream>


#include "test.h"
#include "SequenceLinkedList.h"
#include "SequenceArray.h"

using namespace std;

template<typename T>
void printSequence(Sequence<T> *sequence) {
    cout << "[";
    for (int i = 0; i < sequence->GetSize(); i++) {
        cout << sequence->Get(i) << (i + 1 == sequence->GetSize() ? "" : ", ");
    }
    cout << "]";
    cout << endl;
}


template<typename T>
void testSequence() {
    Sequence<T> *sequence;
    int choice;
    int index;
    T value;

    cout << "Choose:" << endl;
    cout << "1. LinkedListSequence" << endl;
    cout << "2. ArraySequence" << endl;
    cout << "3. AutoTest" << endl;
    cin >> choice;


    switch (choice) {
        case 1:
            sequence = new ListSequence<T>();
            break;
        case 2:
            sequence = new ArraySequence<T>();
            break;

        case 3:
            test();
            cout << "Success" << endl;
            return;
        default:
            cout << "Invalid choice" << endl;
            return;
    }

    Sequence<T> *subSequence = nullptr;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Print current sequence" << endl;
        cout << "2. Append" << endl;
        cout << "3. Get subsequence" << endl;
        cout << "4. Prepend" << endl;
        cout << "5. Insert at" << endl;
        cout << "6. Map (multiply by 2)" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current array: ";
                printSequence(sequence);
                break;
            case 2:
                cout << "Enter value to append: ";
                cin >> value;
                sequence->Append(value);
                cout << "Array after append: ";
                printSequence(sequence);
                break;
            case 3:
                try {
                    cout << "Enter start index: ";
                    cin >> index;
                    cout << "Enter end index: ";
                    cin >> value;
                    subSequence = sequence->Substring(index, value);
                    cout << "Subsequence: ";
                    printSequence(subSequence);
                    delete subSequence;
                    break;
                } catch (...) {
                    cout << "Error" << endl;
                    break;
                }
            case 4:
                cout << "Enter value to prepend: ";
                cin >> value;
                sequence->Prepend(value);
                cout << "Array after prepend: ";
                printSequence(sequence);
                break;
            case 5:
                try {
                    cout << "Enter index to insert at: ";
                    cin >> index;
                    cout << "Enter value to insert: ";
                    cin >> value;
                    sequence->InsertAt(value, index);
                    cout << "Array after insert: ";
                    printSequence(sequence);
                    break;
                } catch (...) {
                    cout << "Error" << endl;
                    break;
                }
            case 6:
                sequence->Map([](T value) { return value * 2; });
                cout << "Array after map: ";
                printSequence(sequence);
                break;
            case 0:
                delete sequence;
                return;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}

int main() {
    testSequence<int>();
    return 0;
}

