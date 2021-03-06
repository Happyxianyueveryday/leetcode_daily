
// 本题属于卡特兰数的相关题目，主要是含有n个结点的二叉搜索树的种类问题，本算法需要非常熟悉，具体解题算法思路如下所示
// 1. n个结点的二叉树的结点值范围为: 1,2,...,n，首先选择一个值作为树的根节点，这里有n种选择
// 2. 对于每一种选择，计算方法如下：假设k作为树的根节点，则以k为根节点的二叉搜索树的种类=左子树的种类*右子树的种类，其中左子树的结点数为k-1，值分别为1,2,...,k-1，右子树的结点数为n-k，值分别为k+1,...,n

class Solution {
public:
    int numTrees(int n) {
        int res[n+1];    //n个结点的树的种类数
        memset(res,0,(n+1)*sizeof(int));
        res[0]=1;        //0个结点的树的种类为1
        res[1]=1;        //1个结点的树的种类为1

        for(int i=2;i<n+1;i++)
        {
            for(int k=0;k<i;k++)   //左子树结点个数为0到k-1
            {
                res[i]+=res[k]*res[i-k-1];
            }
        }

        return res[n];
    }
};