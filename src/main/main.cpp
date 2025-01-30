#include "../includes/Menu.h"
using namespace std;

int main(){
 Menu menu;

 bool run = true;
    while (run) {
        run = menu.nextState(0);
    }
    return 0;
}
