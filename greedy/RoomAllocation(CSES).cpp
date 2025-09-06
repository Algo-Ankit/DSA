#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
// CSES -> ROOM ALLOCATION
void roomAllocation()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> customers(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b; // a: arrival time, b: departure time
        customers[i] = {a, b, i};
    }
    sort(customers.begin(), customers.end()); // sorts on basis of arrival time
    // priority queue: (departure_time, room_number), min-heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
 
    vector<int> room(n);
    int room_count = 0;
 
    for (auto it : customers)
    {
        int arrival = get<0>(it);
        int departure = get<1>(it);
        int index = get<2>(it);
        if (!pq.empty() && pq.top().first < arrival)
        {
            int roomno = pq.top().second;
            room[index] = roomno; // assign room number to customer
            pq.pop();
            pq.push({departure, roomno}); // reassign the room with new departure time.
        }
        else
        {
            room_count++;
            room[index] = room_count;         // assign new room number to customer
            pq.push({departure, room_count}); // add new room with departure time
        }
    }
 
    // Print total number of rooms used
    cout << room_count << endl;
 
    // Print room number assigned to each customer (in original order)
    for (int i = 0; i < n; ++i)
    {
        cout << room[i] << " ";
    }
    cout << endl;
}
 
int getMaxBeauty(const string &s, int n)
{
    int freq[26] = {};
    int len = s.length();
    for (char c : s)
    {
        freq[c - 'a']++;
    }
    int maxfreq = 0;
    for (int i = 0; i < 26; i++)
    {
        maxfreq = max(maxfreq, freq[i]);
    }
    if (maxfreq == len && n == 1)
    { // because freq can be recovered for allowed moved >=2
        return len - 1;
    }
    else
        return min(maxfreq + n, len);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    roomAllocation();
    return 0;
}