// Start of function Node
function Node(data) {
    this.data = data;
    this.left = null;
    this.right = null;
}; // End of function Node

// Start of function BinarySearchTree
function BinarySearchTree() {
    this.insert = function(root, data) {
        if (root === null) {
            this.root = new Node(data);
            
            return this.root;
        }
        
        if (data <= root.data) {
            if (root.left) {
                this.insert(root.left, data);
            } else {
                root.left = new Node(data);
            }
        } else {
            if (root.right) {
                this.insert(root.right, data);
            } else {
                root.right = new Node(data);
            }
        }
        
        return this.root;
    };
    
    // Start of function levelOrder
    this.levelOrder = function(root) {
        // Add your code here
        // To print values separated by spaces use process.stdout.write(someValue + ' ')      
        var q=Array(); // queue output so we can print it on a single line.
        function depth(root) {
            if (root === null) return (0);
            if (root.left === null && root.right === null) {
                return 1;
            }
            else return (1 + Math.max(depth(root.left), depth(root.right)));
        }

        function printLevelOrder(n, root) {

            if(n == 0) q.push(root.data);
        
            if (root.left != null) printLevelOrder(n - 1, root.left);
            if (root.right != null) printLevelOrder(n - 1, root.right);
        }
        var d = depth(root);
        for (var i = 0; i <= d; i++) {
            printLevelOrder(i, root);
        }
        console.log(q.join(' '));
  
	}; // End of function levelOrder