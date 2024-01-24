#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cstdint>

using namespace std;

struct town
{
    long int x = 0, y = 0;
    std::vector<uint16_t> v;
};

int tcount = 0;
std::vector<town> tt;
long int max_len = 0;
uint16_t tstart = 0, tend = 0;
int result = -1;

long int distance(uint16_t i, uint16_t j)
{
    long int d = std::abs(tt[i].x - tt[j].x);
    d += std::abs(tt[i].y - tt[j].y);
    return d;
}

int main()
{
    cin >> tcount;

    tt.resize(tcount);
    for(int i = 0; i < tcount; ++i)
    {
        town& t = tt[i];
        cin >> t.x >> t.y;
    }

    cin >> max_len;
    cin >> tstart >> tend;

    for(uint16_t i = 0; i < tcount; ++i)
        for(uint16_t j = i + 1; j < tcount; ++j)
        {
            if(i == j)
                continue;
            long int d = distance(i, j);
            if(d > max_len)
                continue;
            tt[i].v.push_back(j);
            tt[j].v.push_back(i);
        }

    vector<bool> mark(tcount, false);
    size_t deep = 0;
    unordered_set<uint16_t> ring;

    ring.insert(tstart - 1);
    while(!ring.empty())
    {
        bool finish = false;
        for(uint16_t v : ring)
        {
            if(v == tend - 1)
            {
                finish = true;
                result = deep;
                break;
            }
            mark[v] = true;
        }

        if(finish)
            break;

        unordered_set<uint16_t> rr;
        for(uint16_t v : ring)
        {
            const town& t = tt[v];
            for(uint16_t r : t.v)
                if(!mark[r])
                    rr.insert(r);
        }

        ++deep;
        swap(ring, rr);
    }

    cout << result << endl;

    /*for(int i = 0; i < tcount; ++i)
        cout << tx[i] << " ";
    cout << endl;*/

    /*for(auto& t : tt)
        cout << t.x << " " << t.y << endl;
    cout << max_len << endl;
    cout << start << " " << end << endl;*/

	return 0;
}
