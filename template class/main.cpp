#include <iostream>

using namespace std;
template <typename T>
class weight{
private :
    T kg;
public :
    void setData(T x){
    kg = x;
    }
    T getData(){
    return kg;
        }
};
int main()
{
    weight <int>obj1;
    obj1.setData(15);
    weight <float>obj2;
    obj2.setData(19.15);
    cout<<obj1.getData()<<endl<<obj2.getData();
    return 0;
}
