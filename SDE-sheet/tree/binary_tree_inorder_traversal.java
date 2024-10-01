import java.util.*;


class TreeNode {
         int val;
         TreeNode left;
         TreeNode right;
         TreeNode() {}
         TreeNode(int val) { this.val = val; }
         TreeNode(int val, TreeNode left, TreeNode right) {
             this.val = val;
             this.left = left;
             this.right = right;
         }
}

public class binary_tree_inorder_traversal {
    List<Integer> ls = new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {
        rec(root);
        return ls;
    }

    void rec(TreeNode root){
        if(root == null){
            return;
        }
        rec(root.left);
        ls.add(root.val);
        rec(root.right);
    }
}
