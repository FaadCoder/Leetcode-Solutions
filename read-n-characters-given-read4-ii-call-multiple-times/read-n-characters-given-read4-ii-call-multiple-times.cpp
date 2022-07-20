/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    int bufferPtr = 0;
    int bufferCount = 0;
    char buffer[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int idx=0;
        while(idx<n)
        {
            if(bufferPtr==0)
            {
                bufferCount=read4(buffer);
            }
            if(bufferCount==0)
                break;
            while(idx<n and bufferPtr<bufferCount)
                buf[idx++] = buffer[bufferPtr++];
            if(bufferPtr>=bufferCount)
                bufferPtr = 0;
        }
        return idx;
    }
};