// lab1 sem 4 DSnA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include"map.h"
#include"RBTree.h"
int main()
{
    std::cout << "Hello World!\n";
    Map<int, int> rbtree;

    RBTree<int, int> tree;
    List<int> keys;
    List<int>* values;
    
    auto keуy = rbtree.getkeys();

    rbtree.insert(10, 10);
    rbtree.insert(13, 13);
    rbtree.insert(8, 8);
    rbtree.insert(5, 5);
    rbtree.insert(17, 17);
    rbtree.insert(12, 12);
    rbtree.insert(9, 9);
    rbtree.insert(11, 11);
    rbtree.insert(4, 4);
    rbtree.insert(3, 3);
    rbtree.insert(7, 7);


    cout << rbtree.find(10) << endl;

    auto c = tree.findElem(10)->getColor();
    cout << c << endl;
    cout << rbtree.find(13) << endl;
    cout<<rbtree.find(5)<<endl;

auto key = rbtree.getkeys();
    cout << "at 0 is " << key->head->data << endl;
    values = rbtree.getValues();
    //array.clear();
    rbtree.print();
    rbtree.clear();
    key = rbtree.getkeys();
    rbtree.print();
   
}

