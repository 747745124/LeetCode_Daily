class PeekingIterator : public Iterator
{
public:
    vector<int> vec;
    int idx;
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        vec = nums;
        idx = 0;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return vec[idx];
    }
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        return vec[idx++];
    }

    bool hasNext() const
    {
        if (idx == vec.size())
        {
            return false;
        }
        return true;
    }
};