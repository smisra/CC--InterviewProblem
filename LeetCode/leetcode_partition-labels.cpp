/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        if(S.size() == 0){
            return ans;
        }
        
        vector<int> rightBoundOfChar(26, 0);
        for(int i = 0; i < S.size(); ++ i) {
            int indexOfChar = S[i] - 'a';
            rightBoundOfChar[indexOfChar] = i;
        }
        
        int curPartitionRightBound = rightBoundOfChar[(int)(S[0] - 'a')];
        for(int i = 0; i < S.size(); ++ i){
            int indexOfChar = S[i] - 'a';
            curPartitionRightBound = max(curPartitionRightBound, rightBoundOfChar[indexOfChar]);
            if(i == curPartitionRightBound) {
                ans.push_back( i + 1 );
            }
        }
        
        for(int i = ans.size() - 1; i > 0; -- i) {
            ans[i] = ans[i] - ans[i - 1];
        }
        
        return ans;
    }
};
