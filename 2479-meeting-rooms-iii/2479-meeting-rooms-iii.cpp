class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Room usage count
        vector<int> count(n, 0);

        // Min-heap: {endTime, room}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        // Min-heap for available rooms
        priority_queue<int, vector<int>, greater<>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // Free up rooms whose meetings have ended
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                count[room]++;
                busy.push({end, room});
            } else {
                auto [endTime, room] = busy.top(); busy.pop();
                count[room]++;
                busy.push({endTime + duration, room});
            }
        }

        // Find the room with max count and smallest index
        int maxCount = -1, result = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                result = i;
            }
        }

        return result;
    }
};
