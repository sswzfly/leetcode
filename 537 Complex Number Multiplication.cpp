class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int x1, x2, y1, y2;
        x1 = x2 = y1 = y2 = 0;
        string ax, ay;
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == '+') {
                ax = a.substr(0, i);
                ay = a.substr(i+1, a.length()-i-2);
                break;
            }
        }
        string bx, by;
        for(int i = 0; i < b.length(); i++) {
            if(b[i] == '+') {
                bx = b.substr(0, i);
                by = b.substr(i+1, b.length()-i-2);
            }
        }
        sscanf(ax.c_str(), "%d", &x1);
        sscanf(ay.c_str(), "%d", &y1);
        sscanf(bx.c_str(), "%d", &x2);
        sscanf(by.c_str(), "%d", &y2);
        int x = x1*x2 - y1*y2;
        int y = x1*y2 + x2*y1;
        int offset = 0;
        char ans[256];
        offset += sprintf(ans+offset, "%d+%di", x, y);
        ans[offset] = '\0';
        printf("%s\n", ans);
        return (const char*)ans;
    }
};
