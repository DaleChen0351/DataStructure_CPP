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
// ���õݹ�ķ�ʽʵ���������
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

//�ռ��ʱ�临�Ӷȶ���O(n)��
// BFS �������
//ΪɶҪ��queue����Ϊ�Ƚ��ȳ������Կ��԰������������ά�������һά���Ե���ʽ
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
// ���������
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
//ȷ���Ƿ���ƽ�������
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
//��������ķ�ʽ���ᵼ���ظ����������������ȣ���˲�����������˼·��
//һ�ָĽ��ķ�ʽ�ǣ����Կ������ö�̬�淶��˼�룬��TreeNode��ָ����Ϊkey���ڵ��Ӧ�������Ϊvalue��һ�����ֽڵ��Լ���������ˣ�ֱ�ӷ��ؽ��������
//level������ÿ���ڵ�ֻ����һ��
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
	//û�ҵ�
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

//ȷ��һ�����Ƿ�����һ����������
	//ȷ���������Ƿ���ȣ�Ҫ�Ƚϸ��ڵ��ַ��ֵ�Ƿ���ȣ��ٵݹ�Ƚ����������Ե����������Ƿ����
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
	return matchTree(root1->lchild, root2->lchild) && matchTree(root1->rchild, root2->rchild);//����ķֽ�
	
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
	//����������
	TreeNode nodeA = { 1,NULL,NULL };
	TreeNode nodeB = { 2,NULL,NULL };
	TreeNode nodeC = { 3,NULL,NULL };
	TreeNode nodeD = { 4,NULL,NULL };
	TreeNode nodeE = { 5,NULL,NULL };
	TreeNode nodeF = { 6,NULL,NULL };
	TreeNode nodeG = { 7,NULL,NULL };
	TreeNode nodeH = { 8,NULL,NULL };
	
	//������ϵ
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
	cout << "���õݹ�ķ�ʽʵ�ֶ����������������" << endl;

	inOrderTraversal(&nodeA);

	cout << "ȷ��һ�������Ƿ���ƽ���������" << endl;
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
	//����һ ��������ƽ�������
	if (leftlevel == -1)
	{
		return -1;
	}
	//�������� ��������ƽ�������
	int rightlevel = is_balancedTreeHelper(root->rchild);
	if (rightlevel == -1)
	{
		return -1;
	}
	//������ ��������������ƽ�������������£������������Ĳ����ֵ����1������ƽ�������
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


//����ͬʱ������С�����ֵ�����ҽ���ʼֵ��ΪINT����MIN�������������нڵ��ֵ����

void test_62()
{
	//����������
	TreeNode nodeA = { 1,NULL,NULL };
	TreeNode nodeB = { 2,NULL,NULL };
	TreeNode nodeC = { 3,NULL,NULL };
	TreeNode nodeD = { 4,NULL,NULL };
	TreeNode nodeE = { 5,NULL,NULL };
	TreeNode nodeF = { 6,NULL,NULL };
	TreeNode nodeG = { 7,NULL,NULL };
	TreeNode nodeH = { 8,NULL,NULL };

	//������ϵ
	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeC;
	nodeB.lchild = &nodeD;
	//nodeD.lchild = &nodeE;

	cout << "���õݹ�ķ�ʽʵ�ֶ����������������" << endl;
	inOrderTraversal(&nodeA);

	cout << "ȷ��һ�������Ƿ���ƽ���������" << endl;
	bool ret_b = is_BalancedBinaryTree(&nodeA);
	cout << "the result is " << ret_b << endl;

	cout << "ȷ��һ�������Ƿ���ƽ���������" << endl;
	bool ret_c = is_BalancedBinaryTree_2(&nodeA);
	cout << "the result is " << ret_c << endl;

	cout << "ȷ��һ�������Ƿ���ƽ���������" << endl;
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
    //����������
    TreeNode nodeA = { 1,NULL,NULL };
    TreeNode nodeB = { 2,NULL,NULL };
    TreeNode nodeC = { 3,NULL,NULL };
    TreeNode nodeD = { 4,NULL,NULL };
    TreeNode nodeE = { 5,NULL,NULL };
    TreeNode nodeF = { 6,NULL,NULL };
    TreeNode nodeG = { 7,NULL,NULL };
    TreeNode nodeH = { 8,NULL,NULL };

    //������ϵ
    nodeA.lchild = &nodeB;
    nodeA.rchild = &nodeC;
    nodeB.lchild = &nodeD;
    //nodeD.lchild = &nodeE;

    cout << "�ö����������Ϊ�� " << Depth(&nodeA) << endl;
}
//Tree path
void pathSumHelper(TreeNode* root, vector<int>path, vector<vector<int>>&answer, int sum)
{
    if (root == NULL)//ĳ��path���������ı�־
    {
        return;
    }
    path.push_back(root->val);
    if (root->val == sum)//���е�·������ֻ�е����һ���ڵ�������ʣ����Ǹ�sumֵʱ���ſ��Ա����뵽path��
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
    if (first > last)//û�нڵ���Ҫ��������
    {
        return NULL;
    }
    if (first == last)// ����Ҷ�ӽ�㼶����
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
    if (num.size() == 1) //����Ǳ����ô��
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
    //����������
    TreeNode nodeA = { 1,NULL,NULL };
    TreeNode nodeB = { 2,NULL,NULL };
    TreeNode nodeC = { 3,NULL,NULL };
    TreeNode nodeD = { 4,NULL,NULL };
    TreeNode nodeE = { 5,NULL,NULL };
    TreeNode nodeF = { 6,NULL,NULL };
    TreeNode nodeG = { 7,NULL,NULL };
    TreeNode nodeH = { 8,NULL,NULL };

    //������ϵ
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
    cout <<"�����������ƽ�����������"<<endl;
    inOrderTraversal(root);

}
treeNode* inOrderSuccessor(treeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    //�����ҽڵ�����
    if (node->rchild)
    {
        // �����ҽڵ�����ߵ��Ǹ��ڵ�
    }

    treeNode* parent = node->parent;

}