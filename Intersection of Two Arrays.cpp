/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

vector< int > intersection( vector < int > & nums1, vector < int > & nums2 ) {
	unordered_map < int, bool > um;
	for( auto i : nums1 ) um[i] = 1;
	vector < int > res;
	for( auto i : nums2 ) {
		if( um[i] ) {
			um[i] = 0;
			res.push_back( i );
		}
	}
	return res;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> m(nums1.begin(), nums1.end());
	vector<int> res;
	for (auto a : nums2)
		if (m.count(a)) {
			res.push_back(a);
			m.erase(a);//erase by key
		}
	return res;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = (int)nums1.size(), n2 = (int)nums2.size();
    int i1 = 0, i2 = 0;
    vector<int> res;
    while(i1 < n1 && i2 < n2){
        if(nums1[i1] == nums2[i2]) {
            res.push_back(nums1[i1]);
            i1++;
            i2++;
        }
        else if(nums1[i1] > nums2[i2]){
            i2++;
        }
        else{
            i1++;
        }
        while(i1 > 0 && i1 < n1 && nums1[i1] == nums1[i1 - 1]) i1++;
        while(i2 > 0 && i2 < n2 && nums2[i2] == nums2[i2 - 1]) i2++;
    }
    return res;
}

