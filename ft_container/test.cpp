#include <iostream>
#include <vector>

using namespace std;

int main(){
    int ari[] = {5,4,3,2,1,6};
    // int *it;
    // for (it = &ari[0]; it != &ari[5]; it++){
    //     printf("%d\n", *it);
    // }
    vector<int> vi(&ari[0], &ari[5]);
    vector<int> :: iterator it;
    for (it = vi.begin(); it != vi.end(); it++){
        printf("%d\n", *it);
    }
    return 0;
}