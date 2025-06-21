class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;

        for (char ch : word) {
            freqMap[ch]++;
        }

        vector<int> freqs;
        for (auto& entry : freqMap) {
            freqs.push_back(entry.second);
        }

        sort(freqs.begin(), freqs.end());

        int n = freqs.size();
        int result = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int deletions = 0;

            // Delete all characters before i completely
            for (int j = 0; j < i; ++j) {
                deletions += freqs[j];
            }

            // For characters after i, reduce them if needed
            for (int j = i + 1; j < n; ++j) {
                if (freqs[j] - freqs[i] > k) {
                    deletions += freqs[j] - (freqs[i] + k);
                }
            }

            result = min(result, deletions);
        }

        return result;
    }
};
