class Logger
{
    unordered_map<string, int> messageToLastTimeHashMap;
    public:
        Logger()
        {
            messageToLastTimeHashMap.clear();
        }

    bool shouldPrintMessage(int timestamp, string message)
    {
        bool didPrintMessage = false;
        if (!messageToLastTimeHashMap.count(message) or(timestamp - messageToLastTimeHashMap[message] >= 10))
        {
            messageToLastTimeHashMap[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 *Your Logger object will be instantiated and called as such:
 *Logger* obj = new Logger();
 *bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */