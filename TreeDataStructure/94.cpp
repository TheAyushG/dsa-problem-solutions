//moris trvercel
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

    vector<int> result;

    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            result.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* leftchild = curr->left;
            while(leftchild->right != NULL){
                leftchild = leftchild->right; 
            }

            leftchild->right = curr;
            TreeNode* temp = curr;
            curr = curr->left;
            temp->left = NULL;
        }
  
    }
        
    return result;
    }
};



// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;                  // to store result
//         stack<TreeNode*> st;              // stack to simulate recursion
//         TreeNode* curr = root;

//         while(curr != NULL || !st.empty()) {
//             // 1. Go as left as possible
//             while(curr != NULL) {
//                 st.push(curr);
//                 curr = curr->left;
//             }

//             // 2. Process the node
//             curr = st.top(); 
//             st.pop();
//             res.push_back(curr->val);

//             // 3. Move to right subtree
//             curr = curr->right;
//         }
//         return res;
//     }
// };
