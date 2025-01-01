vector<int> intersection(vector<int> &arr1, vector<int> &arr2)
{
    set<int> s1(arr1.begin(), arr1.end());
    set<int> s2(arr2.begin(), arr2.end());
    vector<int> ans;
    for (auto i : s1)
    {
        if (s2.find(i) != s2.end())
        {
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                           vector<int> &arr3)
{
    vector<int> inter1_2 = intersection(arr1, arr2);
    return intersection(arr3, inter1_2);
}