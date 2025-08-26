// InventorySystem.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Inventory.h"
#include "Item.h"


int main()
{
    std::cout << "Hello World!\n";

    Inventory<Item> inventory(3);
    Item car("자동차", 100);
    Item mouse("마우스", 10);
    Item keyboard("키보드", 30);

    cout << "AddItem Test" << endl;
    inventory.AddItem(car);
    inventory.AddItem(mouse);
    inventory.AddItem(keyboard);
    cout << "inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "inventory's Size : " << inventory.GetSize() << endl;
    inventory.PrintAll_Items();


    cout << "RemoveLastItem Test" << endl;
    inventory.RemoveLastItem();
    cout << "inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "inventory's Size : " << inventory.GetSize() << endl;
    inventory.PrintAll_Items();


    cout << "RemoveLastItem afetr AddItem Test" << endl;
    inventory.AddItem(keyboard);
    cout << "inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "inventory's Size : " << inventory.GetSize() << endl;
    inventory.PrintAll_Items();


    cout << "AddItem Resize Test" << endl;
    Item ballpen("볼펜", 5);
    inventory.AddItem(ballpen);
    cout << "inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "inventory's Size : " << inventory.GetSize() << endl;
    inventory.PrintAll_Items();

    cout << "Resize Test" << endl;
    cout << "Resize 6"<< endl;
    cout << "before inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "before inventory's Size : " << inventory.GetSize() << endl;
    inventory.Resize(6);
    cout << "after inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "after inventory's Size : " << inventory.GetSize() << endl;
    inventory.PrintAll_Items();

    cout << "Resize 2" << endl;
    cout << "before inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "before inventory's Size : " << inventory.GetSize() << endl;
    inventory.Resize(2);
    cout << "after inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "after inventory's Size : " << inventory.GetSize() << endl;
    inventory.PrintAll_Items();

    cout << "Resize 5" << endl;
    cout << "before inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "before inventory's Size : " << inventory.GetSize() << endl;
    inventory.Resize(5);
    cout << "after inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "after inventory's Size : " << inventory.GetSize() << endl;
    inventory.PrintAll_Items();

    cout << "AddItem" << endl;
    Item rice("쌀", 10);
    inventory.AddItem(rice);
    inventory.AddItem(keyboard);
    inventory.AddItem(ballpen);
    cout << "inventory's Capacity : " << inventory.GetCapacity_() << endl;
    cout << "inventory's Size : " << inventory.GetSize() << endl;
    inventory.PrintAll_Items();

    cout << "Constructor copy test" << endl;
    cout << "New Inventory : secondinventory" << endl;
    Inventory<Item> secondinventory(inventory);
    secondinventory.PrintAll_Items();
    cout << "secondinventory's Capacity : " << secondinventory.GetCapacity_() << endl;
    cout << "secondinventory's Size : " << secondinventory.GetSize() << endl;

    cout << "Assign function test" << endl;
    cout << "New Inventory : secondinventory" << endl;
    Inventory<Item> Thirdinventory;
    Thirdinventory.Assign(inventory);
    Thirdinventory.PrintAll_Items();
    cout << "secondinventory's Capacity : " << Thirdinventory.GetCapacity_() << endl;
    cout << "secondinventory's Size : " << Thirdinventory.GetSize() << endl;

    cout << "Sort test" << endl;
    Thirdinventory.SortItems();
    Thirdinventory.PrintAll_Items();

    cout << "inventory" << endl;
    inventory.PrintAll_Items();
    cout << "secondinventory" << endl;
    secondinventory.PrintAll_Items();
    cout << "Thirdinventory" << endl;
    Thirdinventory.PrintAll_Items();

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
