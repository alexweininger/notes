/**
 * Tree
 */
class Tree {
	TreeNode root;

	public class TreeNode {
		TreeNode left;
		TreeNode right;
		int data;

		TreeNode(int data) {
			this.data = data;
		}
	}

	Tree() {
		this.root = null;
	}

	public void insert(TreeNode root, int data) {
		if (null == this.root) {
			this.root = new TreeNode(data);
		} else {
			while (root != null) {
				if (root.data < data) {
					root = root.right;
				} else if (root.data > data) {
					root = root.left;
				} else {
					return;
				}
			}
		}
	}

	public void print(TreeNode root) {
		if (null == root)
			return;
		System.out.println(root.data);
		print(root.left);
		print(root.right);
	}

	public static void main(String[] args) {
		Tree tree = new Tree();
		tree.insert(tree.root, 4);
		tree.insert(tree.root, 8);
		tree.insert(tree.root, 1);
		tree.insert(tree.root, 3);
		tree.insert(tree.root, 2);
		tree.insert(tree.root, 10);
		tree.insert(tree.root, 19);
		tree.print(tree.root);
	}
}
