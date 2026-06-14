class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0)
            return 0;

        int s1cnt = 0, s2cnt = 0;
        int index = 0;

        // index -> {s1cnt when first seen, s2cnt when first seen}
        unordered_map<int, pair<int, int>> mp;

        while (true) {
            s1cnt++;

            // Scan one copy of s1
            for (char c : s1) {
                if (c == s2[index]) {
                    index++;
                    if (index == s2.size()) {
                        s2cnt++;
                        index = 0;
                    }
                }
            }

            // Used all copies of s1
            if (s1cnt == n1)
                return s2cnt / n2;

            // Cycle detected
            if (mp.count(index)) {
                auto [preS1, preS2] = mp[index];

                // Before cycle
                int prefixS1 = preS1;
                int prefixS2 = preS2;

                // Cycle length
                int cycleS1 = s1cnt - preS1;
                int cycleS2 = s2cnt - preS2;

                int remainingS1 = n1 - prefixS1;

                int cycles = remainingS1 / cycleS1;

                int ansS2 = prefixS2 + cycles * cycleS2;

                int restS1 = remainingS1 % cycleS1;

                // Simulate leftover
                int idx = index;
                for (int i = 0; i < restS1; i++) {
                    for (char c : s1) {
                        if (c == s2[idx]) {
                            idx++;
                            if (idx == s2.size()) {
                                ansS2++;
                                idx = 0;
                            }
                        }
                    }
                }

                return ansS2 / n2;
            }

            mp[index] = {s1cnt, s2cnt};
        }
    }
};
