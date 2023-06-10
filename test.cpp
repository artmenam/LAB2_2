#include <iostream>
#include <cassert>

#include "SequenceLinkedList.h"
#include "SequenceArray.h"
#include "test.h"


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

int pow2(int n) {
    return n * n;
}


template <typename Sequence>
void TestAppend(Sequence& sequence) {

    for (int i = 0; i < 5; i++) {
        sequence.Append(i);

        assert(sequence.Get(i) == i);
    }

}

template <typename Sequence>
void TestPrepend(Sequence& sequence) {

    for (int i = 0; i < 5; i++) {
        sequence.Prepend(i);

        assert(sequence.Get(0) == i);
    }

    printSequence(&sequence);

}

template <typename Sequence, typename T>
void TestGetSubSequence(Sequence& sequence, T item) {

    for (int i = 0; i < 10; i++) {
        sequence.Append(item);
    }

    Sequence* subSequence = sequence.Substring(2, 6);

    assert(subSequence->GetSize() == 5);


    printSequence(subSequence);


    delete subSequence;

}

template <typename Sequence>
void TestInsertAt(Sequence& sequence) {


    for (int i = 4; i < 7; i++) {
        sequence.Append(i);
    }

    for (int i = 3; i > 0; i--) {
        sequence.InsertAt(i, 0);
    }

    for (int i = 0; i < sequence.GetSize(); i++) {
        assert(sequence.Get(i) == i + 1);
    }

}



template <typename Sequence>
void TestMap(Sequence& sequence) {

    for (int i = 0; i < 5; i++) {
        sequence.Append(i);
    }

    sequence.Map(pow2);

    for (int i = 0; i < 5; i++) {
        assert(sequence.Get(i) == pow2(i));
    }
    printSequence(&sequence);

}



void test () {


    ListSequence<int> *linkedListSequence = new ListSequence<int>();
    ArraySequence<int> *arraySequence = new ArraySequence<int>();
    TestAppend(*linkedListSequence);
    TestAppend(*arraySequence);
    delete linkedListSequence;
    delete arraySequence;


    linkedListSequence = new ListSequence<int>();
    arraySequence = new ArraySequence<int>();
    TestGetSubSequence(*linkedListSequence, 1);
    TestGetSubSequence(*arraySequence, 1);
    delete linkedListSequence;
    delete arraySequence;


    linkedListSequence = new ListSequence<int>();
    arraySequence = new ArraySequence<int>();
    TestPrepend(*linkedListSequence);
    TestPrepend(*arraySequence);
    delete linkedListSequence;
    delete arraySequence;

    linkedListSequence = new ListSequence<int>();
    arraySequence = new ArraySequence<int>();
    TestInsertAt(*linkedListSequence);
    TestInsertAt(*arraySequence);
    delete linkedListSequence;
    delete arraySequence;



    linkedListSequence = new ListSequence<int>();
    arraySequence = new ArraySequence<int>();
    TestMap(*linkedListSequence);
    delete linkedListSequence;
    TestMap(*arraySequence);
    delete arraySequence;

}

