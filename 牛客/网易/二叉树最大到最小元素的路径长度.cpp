/*��һ�ö�����������ÿ�������Ȩֵ��Ȩֵ������ͬ�������һ���㷨���Ȩֵ����Ҷ�ڵ㵽Ȩֵ��С��Ҷ�ڵ�ľ��롣������ÿ���ߵľ���Ϊ1��һ���ڵ㾭���������ߵ�����һ���ڵ�Ϊ�������ڵ�֮��ľ��롣
�����������ĸ��ڵ�root���뷵��������롣*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

//��һ�ö�����������ÿ�������Ȩֵ��Ȩֵ������ͬ�������һ���㷨���Ȩֵ����Ҷ�ڵ㵽Ȩֵ��С��Ҷ�ڵ�ľ��롣
//������ÿ���ߵľ���Ϊ1��һ���ڵ㾭���������ߵ�����һ���ڵ�Ϊ�������ڵ�֮��ľ��롣
//�����������ĸ��ڵ�root���뷵��������롣


#include<iostream>
using namespace std;
#include<vector>



//1ע��� Ȩֵ����Ҷ�ӽڵ㵽Ȩֵ��С��Ҷ�ӽڵ�,�������еĽڵ�,��Ҷ�ӽ��
//2.������������������ڵ��λ��,������ڵ㵽���ǵ�·��,������ظ���·���ͼ�ȥ�ظ���·���ĳ���.

class Tree {
    void Inorder(TreeNode *root, vector<int>&v, int &small, int &big){
        //������������С��Ҷ�ڵ������Ҷ�ڵ������
        if (!root)
            return;
        Inorder(root->left, v, small, big);
        v.push_back(root->val);
        if (root->left == NULL&&root->right == NULL){    //Ҷ�ӽڵ�   //���ű����Ĺ����ߣ���һ��Ҷ�ӽ�㣬samll=big��v�����ֵ��
            if (small == -1 || big == -1)
                small = big = (int)v.size() - 1;
            else{                                                    //�ڶ���Ҷ�ӽ�㣬samll=big��=-1��v�����е�һ���ڵ㵽���ڶ���Ҷ�ӽ���·��ֵ���Ƚϸı�samll��big��ֵ
                if (root->val<v[small]) small = (int)v.size() - 1;
                if (root->val>v[big])   big = (int)v.size() - 1;
            }
        }
        Inorder(root->right, v, small, big);
    }
public:
    int getDis(TreeNode* root) {
        int small = -1, big = -1;
        vector<int>v;
        Inorder(root, v, small, big);  //v����Ϊ��������Ľڵ�ֵ
        TreeNode * p = root;
        vector<int>v1, v2;
        int pos;
        while (true) {    //Ѱ��·��
            pos = (int)(find(v.begin(), v.end(), p->val) - v.begin());//�ҵ����ڵ������
            v1.push_back(v[pos]);  //�洢���Ǹ��ڵ㵽��СĿ��ڵ��·��ֵ
            if (small>pos)         //�����Ƚ�
                p = p->right;
            else if (small<pos)
                p = p->left;
            else
                break;
        }
        p = root;
        while (true) {
            pos = (int)(find(v.begin(), v.end(), p->val) - v.begin());
            v2.push_back(v[pos]);
            if (big>pos)
                p = p->right;
            else if (big<pos)
                p = p->left;
            else
                break;
        }
        int i, j;
        for (i = 0, j = 0; j<v2.size() - 1 && i<v1.size() - 1; ++i, ++j) {   //ȥ��
            if (!(v1[i] == v2[j] && v1[i + 1] == v2[j + 1]))
                break;
        }
        return (int)v1.size() - 1 + (int)v2.size() - 1 - 2 * i;  //iΪǰ���м�����ͬ��
    }
};
