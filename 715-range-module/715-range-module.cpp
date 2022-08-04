struct SegmentTreeNode
{
    int low, high;
    bool tracked;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int _low, int _high, bool _tracked = false, SegmentTreeNode *_left = NULL, SegmentTreeNode *_right = NULL):
        low(_low), high(_high), tracked(_tracked), left(_left), right(_right) {}
};

class SegmentTree
{
    private:
        SegmentTreeNode * root;

    void updateRangeHelper(SegmentTreeNode *root, int start, int end, bool tracked)
    {
        if (root->low == start and root->high == end)
        {
            root->tracked = tracked;
            root->left = NULL;
            root->right = NULL;
            return;
        }

        int mid = root->low + (root->high - root->low) / 2;

        if (!root->left)
        {
            root->left = new SegmentTreeNode(root->low, mid, root->tracked);
            root->right = new SegmentTreeNode(mid + 1, root->high, root->tracked);
        }

        if (end <= mid)
            updateRangeHelper(root->left, start, end, tracked);
        else if (start > mid)
            updateRangeHelper(root->right, start, end, tracked);
        else
        {
            updateRangeHelper(root->left, start, mid, tracked);
            updateRangeHelper(root->right, mid + 1, end, tracked);
        }

        root->tracked = root->left->tracked and root->right->tracked;
    }

    bool queryRangeHelper(SegmentTreeNode *root, int start, int end)
    {
        if (!root->left)
            return root->tracked;

        if (root->low == start and root->high == end)
            return root->tracked;

        int mid = root->low + (root->high - root->low) / 2;

        if (end <= mid)
            return queryRangeHelper(root->left, start, end);
        if (start > mid)
            return queryRangeHelper(root->right, start, end);

        return queryRangeHelper(root->left, start, mid) and queryRangeHelper(root->right, mid + 1, end);
    }

    public:

        SegmentTree(int low, int high)
        {
            root = new SegmentTreeNode(low, high);
        }

    void updateRange(int start, int end, bool tracked)
    {
        updateRangeHelper(root, start, end, tracked);
    }

    bool queryRange(int start, int end)
    {
        return queryRangeHelper(root, start, end);
    }
};

class RangeModule
{

    SegmentTree * tree;

    public:
        RangeModule()
        {
            tree = new SegmentTree(1, 1e9);
        }

    void addRange(int left, int right)
    {
        tree->updateRange(left, right - 1, true);
    }

    bool queryRange(int left, int right)
    {
        return tree->queryRange(left, right - 1);
    }

    void removeRange(int left, int right)
    {
        return tree->updateRange(left, right - 1, false);
    }
};

/**
 *Your RangeModule object will be instantiated and called as such:
 *RangeModule* obj = new RangeModule();
 *obj->addRange(left,right);
 *bool param_2 = obj->queryRange(left,right);
 *obj->removeRange(left,right);
 */