class RLEIterator
{
    vector<int> encoding;
    int currentIdx = 0;
    public:
        RLEIterator(vector<int> &encoding)
        {
            this->encoding = encoding;
            currentIdx = 0;
        }

    int next(int n)
    {
        while (currentIdx < encoding.size())
        {
            if (encoding[currentIdx] >= n)
            {
                encoding[currentIdx] -= n;
                return encoding[currentIdx + 1];
            }
            else
            {
                n -= encoding[currentIdx];
                currentIdx += 2;
            }
        }
        return -1;
    }
};

/**
 *Your RLEIterator object will be instantiated and called as such:
 *RLEIterator* obj = new RLEIterator(encoding);
 *int param_1 = obj->next(n);
 */