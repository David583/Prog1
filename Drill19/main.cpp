#include <iostream>
#include <vector>

template<typename T> struct S {
    public:
        S (T something) : val(something) { };
        T get();
        const T get() const;
        S& operator=(const T&);
    private:
        T val;
};
template<typename T>
T S<T>::get() {
    return this->val;
}
template<typename T>
const T S<T>::get() const {
    return this->val;
}
template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}
using namespace std;

template<typename T> 
void read_val(T& v) {
    cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    os << "}" << endl;

    return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }
    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }
    return is;
}


int main() {
    int x;
    read_val(x);
    S<int> i = x;
    char xx;
    read_val(xx);
    S<char> c = xx;
    double xxx;
    read_val(xxx);
    S<double> d = xxx;
    string meow;
    read_val(meow);
    S<string> s = meow;
    vector<int> sx = {1, 2, 3};
    S<vector<int>> vec = sx;

    cout << i.get() << endl;
    cout << c.get() << endl;
    cout << d.get() << endl;
    cout << s.get() << endl;
    cin >> sx;
    cout << sx;
    cout << endl;

}