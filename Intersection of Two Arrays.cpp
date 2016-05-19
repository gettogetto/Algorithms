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

