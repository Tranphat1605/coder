#include <bits/stdc++.h>
using namespace std;
typedef int StationID;
typedef int CustomerID ;
typedef long long Money;
typedef long long SessionID;


typedef struct timelot {
    int start;
    int end;
}timelot;

bool cmp(timelot a, timelot b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

struct Status {
    bool trong;
    bool dangsac;
    bool baotri;
    bool dattruoc;
};

typedef struct Tru{
    int TruID;
    timelot time;
    Status status;
};
struct Tram {
    StationID id;
    Tru tru;
    vector <int> Toado;
};