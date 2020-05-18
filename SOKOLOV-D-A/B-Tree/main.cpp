#include "B_Tree.h"
#include "B_Tree_Printer.h"

int main()
{
    BTreePrinter printer;
    B_Tree t(5);

    srand(2934);

    for (int i = 1; i < 25; i++)
    {
        int p = rand() % 100;
        t.add_data(i);
        
    }
    printer.print(t);
    void* sear = t.search(56);
    t.delete_data(2);
    printer.print(t);
    t.delete_data(7);
    printer.print(t);
    system("pause");
    return 0;
}
