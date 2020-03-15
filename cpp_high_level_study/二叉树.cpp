#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

class TreeNode
{
public: 
	int val;
	TreeNode* lchild;
	TreeNode* rchild;
	//TreeNode* parent;	
    //TreeNode(int value):val(value){}
};
class treeNode
{
public:
    int val;
    treeNode* lchild;
    treeNode* rchild;
    treeNode* parent;

};

//class BinaryTree
//{
//public:
//	BinaryTree(int rootValue);
//	~BinaryTree();
//	void inOrderTraversal()
//private:
//	TreeNode* root;
//};
//
//void visit(TreeNode* node)
//{
//
//}
// 采用递归的方式实现中序遍历
//DFS for recursion
void inOrderTraversal(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrderTraversal(root->lchild);
	cout << root->val << endl;
	inOrderTraversal(root->rchild);
}
// DFS for non-recursion
vector<int>preOrderTraversal(TreeNode* root)
{
	vector<int>result;
	if (root == NULL)
	{
		return result ;
	}
	stack<TreeNode*>s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* top = s.top();
		s.pop();
		result.push_back(top->val);
		if (top->rchild != NULL)
		{
			s.push(top->rchild);
		}
		if (top->lchild != NULL)
		{
			s.push(top->lchild);
		}
	}
	return result;
}

//空间和时间复杂度都是O(n)的
// BFS 广度优先
//为啥要用queue？因为先进先出，所以可以按层遍历，将二维遍历变成一维线性的形式
vector<int> levelTraversal(TreeNode* root)
{
	queue<TreeNode*>q;
	vector<int>result;
	if (root == NULL)
	{
		return result;
	}
	q.push(root);
	while (!q.empty())
	{
		TreeNode* front = q.front();
		q.pop();
		result.push_back(front->val);
		if (front->lchild != NULL)
		{
			q.push(front->lchild);
		}
		if (front->rchild != NULL)
		{
			q.push(front->rchild);
		}
	}
	return result;
}
// 求树的深度
int level(TreeNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	int leftlevel = level(node->lchild);
	int rightlevel = level(node->rchild);
	return leftlevel > rightlevel ? leftlevel + 1 : rightlevel + 1;
}
//确定是否是平衡二叉树
bool is_BalancedBinaryTree(TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	
	int leftlevel = level(root->lchild);
	int rightlevel = level(root->rchild);
	int diff_level = abs(leftlevel - rightlevel);
	if (diff_level <2 && is_BalancedBinaryTree(root->lchild) && is_BalancedBinaryTree(root->rchild))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//采用上面的方式，会导致重复计算各级子树的深度，因此不是理想的设计思路。
//一种改进的方式是，可以考虑利用动态规范的思想，想TreeNode的指针作为key，节点对应的深度作为value，一旦发现节点以及被计算过了，直接返回结果，这样
//level函数对每个节点只计算一次
map<TreeNode*, int>m;
bool is_BalancedBinaryTree_2(TreeNode* root)
{
	int leftlevel;
	int rightlevel;
	if (root == NULL)
	{
		return true;
	}
	map<TreeNode*, int>::iterator pos = m.find(root->lchild);
	//没找到
	if (pos == m.end())
	{
		leftlevel = level(root->lchild);
		m.insert(make_pair(root->lchild,leftlevel));
	}
	else
	{
		leftlevel = (*pos).second;
	}

	pos = m.find(root->rchild);
	if (pos == m.end())
	{
		rightlevel = level(root->rchild);
		m.insert(make_pair(root->rchild, rightlevel));
	}
	else
	{
		rightlevel = (*pos).second;
	}
	//diff calc
	int diff_level = abs(leftlevel - rightlevel);
	if (diff_level < 2 && is_BalancedBinaryTree(root->lchild) && is_BalancedBinaryTree(root->rchild))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//确定一个树是否是另一个树的子树
	//确定两课树是否相等，要比较根节点地址和值是否相等，再递归比较两课树各自的左右子树是否相等
bool matchTree(TreeNode* root1, TreeNode* root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if (root1 != root2)
	{
		return false;
	}
	if (root1->val != root2->val)
	{
		return false;
	}
	return matchTree(root1->lchild, root2->lchild) && matchTree(root1->rchild, root2->rchild);//问题的分解
	
}

bool subTree(TreeNode*root1, TreeNode* root2)
{
    if (root2 == NULL)
    {
        return true;
    }
}

void test_61()
{
	//创建二叉树
	TreeNode nodeA = { 1,NULL,NULL };
	TreeNode nodeB = { 2,NULL,NULL };
	TreeNode nodeC = { 3,NULL,NULL };
	TreeNode nodeD = { 4,NULL,NULL };
	TreeNode nodeE = { 5,NULL,NULL };
	TreeNode nodeF = { 6,NULL,NULL };
	TreeNode nodeG = { 7,NULL,NULL };
	TreeNode nodeH = { 8,NULL,NULL };
	
	//建立关系
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;
	nodeB.rchild = &nodeC;
	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;
	nodeF.rchild = &nodeG;
	nodeG.lchild = &nodeH;

	//vector<int> ret = preOrderTraversal(&nodeA);
	vector<int> ret = levelTraversal(&nodeA);

	for (vector<int>::iterator it = ret.begin(); it != ret.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "采用递归的方式实现二叉树的中序遍历：" << endl;

	inOrderTraversal(&nodeA);

	cout << "确定一棵子树是否是平衡二叉树：" << endl;
	bool ret_b = is_BalancedBinaryTree(&nodeA);
	cout << "the result is " << ret_b << endl;
}

void vector_printer(vector<int>v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}


int is_balancedTreeHelper(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftlevel = is_balancedTreeHelper(root->lchild);
	//条件一 左子树是平衡二叉树
	if (leftlevel == -1)
	{
		return -1;
	}
	//条件二： 右子树是平衡二叉树
	int rightlevel = is_balancedTreeHelper(root->rchild);
	if (rightlevel == -1)
	{
		return -1;
	}
	//条件三 当左右子树都是平衡二叉树的情况下，且左右子树的差绝对值大于1，则不是平衡二叉树
	if (abs(leftlevel - rightlevel) > 1)
	{
		return -1;
	}
	else
	{
		return leftlevel > rightlevel ? leftlevel + 1 : rightlevel + 1;
	}
	


}
bool is_balancedTree(TreeNode* root)
{
	return is_balancedTreeHelper(root) != -1;
}


//可以同时传入最小、最大值，并且将初始值设为INT——MIN，其左子树所有节点的值必须

void test_62()
{
	//创建二叉树
	TreeNode nodeA = { 1,NULL,NULL };
	TreeNode nodeB = { 2,NULL,NULL };
	TreeNode nodeC = { 3,NULL,NULL };
	TreeNode nodeD = { 4,NULL,NULL };
	TreeNode nodeE = { 5,NULL,NULL };
	TreeNode nodeF = { 6,NULL,NULL };
	TreeNode nodeG = { 7,NULL,NULL };
	TreeNode nodeH = { 8,NULL,NULL };

	//建立关系
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeC;
	nodeB.lchild = &nodeD;
	//nodeD.lchild = &nodeE;

	cout << "采用递归的方式实现二叉树的中序遍历：" << endl;
	inOrderTraversal(&nodeA);

	cout << "确定一棵子树是否是平衡二叉树：" << endl;
	bool ret_b = is_BalancedBinaryTree(&nodeA);
	cout << "the result is " << ret_b << endl;

	cout << "确定一棵子树是否是平衡二叉树：" << endl;
	bool ret_c = is_BalancedBinaryTree_2(&nodeA);
	cout << "the result is " << ret_c << endl;

	cout << "确定一棵子树是否是平衡二叉树：" << endl;
	bool ret_d = is_balancedTree(&nodeA);
	cout << "the result is " << ret_d << endl;

}

int Depth(TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    int leftH = Depth(root->lchild);
    int rightH = Depth(root->rchild);

    return leftH > rightH ? leftH + 1 : rightH + 1;
}

void test_63()
{
    //创建二叉树
    TreeNode nodeA = { 1,NULL,NULL };
    TreeNode nodeB = { 2,NULL,NULL };
    TreeNode nodeC = { 3,NULL,NULL };
    TreeNode nodeD = { 4,NULL,NULL };
    TreeNode nodeE = { 5,NULL,NULL };
    TreeNode nodeF = { 6,NULL,NULL };
    TreeNode nodeG = { 7,NULL,NULL };
    TreeNode nodeH = { 8,NULL,NULL };

    //建立关系
    nodeA.lchild = &nodeB;
    nodeA.rchild = &nodeC;
    nodeB.lchild = &nodeD;
    //nodeD.lchild = &nodeE;

    cout << "该二叉树的深度为： " << Depth(&nodeA) << endl;
}
//Tree path
void pathSumHelper(TreeNode* root, vector<int>path, vector<vector<int>>&answer, int sum)
{
    if (root == NULL)//某条path遍历结束的标志
    {
        return;
    }
    path.push_back(root->val);
    if (root->val == sum)//所有的路径，都只有到最后一个节点等于最后剩余的那个sum值时，才可以被加入到path中
    {
        answer.push_back(path);
    }
    pathSumHelper(root->lchild, path, answer, sum - root->val);
    pathSumHelper(root->rchild, path, answer, sum - root->val);
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<int> path;
    vector<vector<int>> result;
    pathSumHelper(root, path, result, sum);
    return result;

}

TreeNode* helper(const vector<int>& num, int first, int last)
{
    TreeNode* parent = NULL;
    if (first > last)//没有节点需要被建立了
    {
        return NULL;
    }
    if (first == last)// 到了叶子结点级别了
    {
        parent = new TreeNode();
        parent->val = num[last];
        return parent;
    }
    int mid = (first + last) / 2;
    parent = new TreeNode();
    parent->val = num[mid];
    TreeNode* left = helper(num, first, mid - 1);
    TreeNode* right = helper(num, mid + 1, last);

    parent->lchild = left;
    parent->rchild = right;
    return parent;
}

TreeNode* sortedArrayToBST(const vector<int> & num)
{
    TreeNode* root = NULL;
    if (num.size() == 0)
    {
        return NULL;
    }
    if (num.size() == 1) //这个是必须的么？
    {
        root = new TreeNode();
        root->val = num[0];
        return root;
    }
    int first = 0; 
    int last = num.size() - 1;
    root = helper(num, first, last);
    return root;
}

void test_04()
{
    //创建二叉树
    TreeNode nodeA = { 1,NULL,NULL };
    TreeNode nodeB = { 2,NULL,NULL };
    TreeNode nodeC = { 3,NULL,NULL };
    TreeNode nodeD = { 4,NULL,NULL };
    TreeNode nodeE = { 5,NULL,NULL };
    TreeNode nodeF = { 6,NULL,NULL };
    TreeNode nodeG = { 7,NULL,NULL };
    TreeNode nodeH = { 8,NULL,NULL };

    //建立关系
    nodeA.lchild = &nodeB;
    nodeA.rchild = &nodeF;
    nodeB.rchild = &nodeC;
    nodeC.lchild = &nodeD;
    nodeC.rchild = &nodeE;

    nodeF.rchild = &nodeG;
    nodeG.lchild = &nodeH;

    vector<int>ret = preOrderTraversal(&nodeA);
    vector_printer(ret);

    cout << endl;

    vector<vector<int>> ret2 = pathSum(&nodeA, 14);
    for (vector<vector<int>>::iterator it = ret2.begin(); it != ret2.end(); it++)
    {
        vector_printer(*it);
        cout << endl;
    }
}

void test_05()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }

    TreeNode* root = sortedArrayToBST(v);
    vector<int>ret = preOrderTraversal(root);
    vector_printer(ret);
    cout <<"采用中序遍历平衡二叉搜索树"<<endl;
    inOrderTraversal(root);

}
treeNode* inOrderSuccessor(treeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    //存在右节点的情况
    if (node->rchild)
    {
        // 返回右节点最左边的那个节点
    }

    treeNode* parent = node->parent;

}