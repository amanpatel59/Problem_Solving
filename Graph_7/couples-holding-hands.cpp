class Solution {
public:
    void swapHere(unordered_map<int, int>& mp, int person1, int partner, int i,
                  vector<int>& row , int& count) {
        int partnerAt = mp[partner];
        swap(row[i + 1], row[partnerAt]);
        // carefull , these are the after swapping values
        mp[row[partnerAt]] = partnerAt;
        mp[row[i + 1]] = i + 1;

        count++;
    }
    int minSwapsCouples(vector<int>& row) {
        int count = 0;
        // stores the position of person
        unordered_map<int, int> mp;
        for (int i = 0; i < row.size(); i++)
            mp[row[i]] = i;

        for (int i = 0; i < row.size(); i += 2) {
            int person1 = row[i], person2 = row[i + 1];
            if (person1 % 2 == 0 and person2 != person1 + 1)
                swapHere(mp, person1, person1 + 1, i, row,count);
            else if (person1 % 2 != 0 and person2 != person1 - 1)
                swapHere(mp, person1, person1 - 1, i, row,count);
        }
        return count;
    }
};