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

public class flatten_binary_tree_to_linked_list {
    
    TreeNode prev = null;
    
    public void flatten(TreeNode root) {
        
        if(root == null){
            return;
        }
        flatten(root.right);
        flatten(root.left);

        root.left = prev;
        root.left = null;
        prev = root;
        

    }
}
