#include <bits/stdc++.h>
using namespace std;

class mystring {
private:
    char* ch = nullptr;
    int len = 0;

public:
    mystring() : ch(nullptr), len(0) {}

    mystring(int _len, int c) : ch(nullptr), len(0) {
        if (_len > 0) {
            len = _len;
            ch = new char[len];
            for (int i = 0; i < len; ++i) ch[i] = static_cast<char>(c);
        }
    }

    mystring(string &c) : ch(nullptr), len(0) {
        len = static_cast<int>(c.length());
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, c.data(), len);
        }
    }

    // copy constructor
    mystring(const mystring& other) : ch(nullptr), len(other.len) {
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, other.ch, len);
        }
    }

    // move constructor
    mystring(mystring&& other) noexcept : ch(other.ch), len(other.len) {
        other.ch = nullptr;
        other.len = 0;
    }

    ~mystring() {
        delete[] ch;
        ch = nullptr;
        len = 0;
    }

    // copy assignment
    mystring& operator=(const mystring& other) {
        if (this == &other) return *this;
        char* newch = nullptr;
        if (other.len > 0) {
            newch = new char[other.len];
            memcpy(newch, other.ch, other.len);
        }
        delete[] ch;
        ch = newch;
        len = other.len;
        return *this;
    }

    // move assignment
    mystring& operator=(mystring&& other) noexcept {
        if (this == &other) return *this;
        delete[] ch;
        ch = other.ch;
        len = other.len;
        other.ch = nullptr;
        other.len = 0;
        return *this;
    }

    // index operator (0-based), returns '\0' if out of range
    char operator[](int idx) const {
        if (idx < 0 || idx >= len) return '\0';
        return ch[idx];
    }

    // comparison operator< : lexicographical by characters, then by length
    bool operator<(const mystring& rhs) const {
        int n = min(len, rhs.len);
        for (int i = 0; i < n; ++i) {
            if (ch[i] != rhs.ch[i]) return ch[i] < rhs.ch[i];
        }
        return len < rhs.len;
    }

    // ADD: concatenate rhs to this
    void ADD(const mystring& rhs) {
        if (rhs.len == 0) return;
        int newlen = len + rhs.len;
        char* newch = new char[newlen];
        if (len > 0) memcpy(newch, ch, len);
        memcpy(newch + len, rhs.ch, rhs.len);
        delete[] ch;
        ch = newch;
        len = newlen;
    }

    // out function: print the string content without newline
    void out() const {
        if (len > 0) cout.write(ch, len);
    }

    // get length
    int get_len() const { return len; }
};

// Allow implicit conversion from std::string as in sample
static mystring make_mystring_from_std(string &s) { return mystring(s); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str_in1, str_in2;
    int n, id;
    if (!(cin >> id)) return 0;
    if (id == 1) {
        mystring str1(100, 'a');
        str1.out();
        cout << "\n";
    } else if (id == 2) {
        cin >> str_in1;
        mystring str2 = make_mystring_from_std(str_in1);
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str2[x] << "\n";
        }
    } else if (id == 3) {
        cin >> str_in1 >> str_in2;
        mystring str2 = make_mystring_from_std(str_in1);
        mystring str3 = make_mystring_from_std(str_in2);
        cout << (int)(str2 < str3) << "\n";
    } else if (id == 4) {
        cin >> str_in1 >> str_in2;
        mystring str2 = make_mystring_from_std(str_in1);
        mystring str3 = make_mystring_from_std(str_in2);
        str2.ADD(str3);
        str2.out();
        cout << "\n";
    } else {
        cin >> str_in1 >> str_in2;
        mystring str2 = make_mystring_from_std(str_in1);
        mystring str3 = make_mystring_from_std(str_in2);
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str3[x] << "\n";
        }
        cout << str2.get_len() << " " << str3.get_len() << "\n";
        cout << (int)(str2 < str3) << "\n";
        str2.ADD(str3);
        str2.out();
        cout << "\n";
        cout << str2.get_len() << "\n";
    }
    return 0;
}

