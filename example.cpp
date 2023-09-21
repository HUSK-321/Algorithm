#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<int> vec;

    cout << "===============\n";

    cout << "vector size     : " << vec.size() << '\n';
    cout << "vector capacity : " << vec.capacity() << '\n';

    //...
    vec.push_back(0);
    //...

    cout << "===============\n";

    cout << "vector size     : " << vec.size() << '\n';
    cout << "vector capacity : " << vec.capacity() << '\n';

    //...
    for(int i = 0; i < 2; i++)
        vec.push_back(0);
    //...

    cout << "===============\n";

    cout << "vector size     : " << vec.size() << '\n';
    cout << "vector capacity : " << vec.capacity() << '\n';

    //...
    for(int i = 0; i < 2; i++)
        vec.push_back(0);
    //...

    cout << "===============\n";

    cout << "vector size     : " << vec.size() << '\n';
    cout << "vector capacity : " << vec.capacity() << '\n';

    //...
    for(int i = 0; i < 4; i++)
        vec.push_back(0);
    //...

    cout << "===============\n";

    cout << "vector size     : " << vec.size() << '\n';
    cout << "vector capacity : " << vec.capacity() << '\n';

        //...
    for(int i = 0; i < 8; i++)
        vec.push_back(0);
    //...

    cout << "===============\n";

    cout << "vector size     : " << vec.size() << '\n';
    cout << "vector capacity : " << vec.capacity() << '\n';

}