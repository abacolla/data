
#include <iostream>
#include "workOn.h"

using namespace std;

int counter() {
    static int count;
    ++count;
    return count;
}


int main(int argc, char *argv[]) {

    for (int x = 0; x < 5; ++x) {
        cout << counter() << " ";
    }
    cout << endl;

    EmployeeStatic me;
    EmployeeStatic you;

    cout << me.getEmpNo() << endl;
    cout << you.getEmpNo() << endl << endl;

    cout << "resource counting" << endl;
    cout << StaticPerson::GetNoPeople() << endl;
    StaticPerson him;
    cout << him.GetNoPeople() << endl;
    StaticPerson* her = new StaticPerson;
    cout << StaticPerson::GetNoPeople() << endl;
    delete her;
    cout << StaticPerson::GetNoPeople() << endl;

    return 0;
}
