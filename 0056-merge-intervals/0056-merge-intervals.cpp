class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	for(int i=0;i<n;i++){
		int first=arr[i][0];
		int end=arr[i][1];
		if(!ans.empty() && end <= ans.back()[1]){
			continue;
		}
		else{
			for(int j=i+1;j<n;j++){
				if(end>=arr[j][0]){
					end=max(end,arr[j][1]);
				}
				else{
					break;
				}
			}
		}
                ans.push_back({first, end});
        }
	return ans;
    }
};