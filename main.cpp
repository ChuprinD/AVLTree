#include <iostream>
#include <conio.h>
#include "AVLTree.h"

using namespace std;

int main()
    {
    node* AVLTree = nullptr;

    int item = 0;
    int num = 0;
    bool exit = 1;

    while (exit)
        {
        system("CLS");
        cout << "0  - exit\n";
        cout << "1  - inserting an item\n";
        cout << "2  - search for an item by key\n";
        cout << "3  - find the min item\n";
        cout << "4  - delete an item with a min key\n";
        cout << "5  - delete an item\n";
        cout << "6  - print tree\n";
        cin >> num;
        switch (num)
            {
            case 0:
                exit = 0;
                break;
            case 1:
                cout << "Enter item\n";
                cin >> item;
                AVLTree = insert(AVLTree, item);
                break;

            case 2:
                cout << "Enter item\n";
                cin >> item;
                cout << find(AVLTree, item) << '\n';
                break;

            case 3:
                cout << find_min(AVLTree) << '\n';
                break;

            case 4:
                AVLTree = remove_min(AVLTree);
                break;

            case 5:
                cout << "Enter item\n";
                cin >> item;
                AVLTree = remove(AVLTree, item);
                break;

            case 6:
                print(AVLTree, 0);
                break;
            }
        cout << "Push any button to continue\n";
        _getch();
        }

    }
