class MyCalendar {
private:
    vector<pair<int, int>> calendar;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        int l = 0, r = calendar.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (calendar[mid].first >= end) r = mid;
            else if (calendar[mid].second <= start) l = mid + 1;
            else return false;
        }
        calendar.insert(calendar.begin() + l, {start, end});
        return true;
    }
};