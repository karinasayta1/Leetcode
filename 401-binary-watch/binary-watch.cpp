class Solution {
public:

     vector<string> result;
    int totalOn;

    void backtrack(int index, int count, int hour, int minute) {
        
        if (count > totalOn)
            return;

        if (index == 10) {
            if (count == totalOn && hour < 12 && minute < 60) {
                
                string time = to_string(hour) + ":";
                
                if (minute < 10)
                    time += "0";
                
                time += to_string(minute);
                
                result.push_back(time);
            }
            return;
        }

        if (index < 4) {
            backtrack(index + 1, count + 1, hour + (1 << index), minute);
        } else {
            backtrack(index + 1, count + 1, hour, minute + (1 << (index - 4)));
        }

        backtrack(index + 1, count, hour, minute);
    }

    
    vector<string> readBinaryWatch(int turnedOn) {
        totalOn = turnedOn;
        backtrack(0, 0, 0, 0);
        return result;
    }
};