// lab1 sem 4 DSnA.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"List.h"
#include <iostream>
#include"RBTree.h"
#include"map.h"

int main()
{
    std::cout << "Hello World!\n";
    Map<int, int> array;
    List<int>* keys;
    List<int>* values;
    array.insert(10, 10);
    array.insert(13, 13);
    array.insert(8, 8);
    array.insert(5, 5);
    array.insert(17, 17);
    array.insert(12, 12);
    array.insert(9, 9);
    array.insert(11, 11);
    array.insert(4, 4);
    array.insert(3, 3);
    //array.clear();
    //array.remove(10);
    array.insert(7, 7);
    cout<<"asd " <<array.find(5)<<endl;
    keys = array.getkeys();
    cout<<array.getkeys();
    values = array.getValues();
    cout << array.getValues();
    //array.clear();
    array.print();
    array.clear();
    array.print();
   
}

