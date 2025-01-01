class Solution {
public:
    vector<int> grayCode(int n) {
        int x = 1;
        vector<int> codes{0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < x; j++) {
                codes.push_back(codes[x - 1 - j] ^ x);
            }

            x <<= 1;
        }

        return codes;
    }
};