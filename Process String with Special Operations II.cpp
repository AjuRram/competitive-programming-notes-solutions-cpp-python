class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        const long long LIM = (long long)1e15 + 1;

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                len[i + 1] = min(LIM, len[i] + 1);
            } else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            } else if (ch == '#') {
                len[i + 1] = min(LIM, len[i] * 2);
            } else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        long long pos = k;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long prevLen = len[i];
            long long curLen = len[i + 1];

            if ('a' <= ch && ch <= 'z') {
                if (pos == prevLen) return ch;
            } 
            else if (ch == '*') {
                // position unchanged
            } 
            else if (ch == '#') {
                if (prevLen > 0) pos %= prevLen;
            } 
            else { // '%'
                pos = curLen - 1 - pos;
            }
        }

        return '.';
    }
};