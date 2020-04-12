# Problem Name: Delete Nodes And Return Forest
**Leetcode 1110, [Problem Link](https://leetcode.com/problems/delete-nodes-and-return-forest/)**


### Tutorial

Few things we should observe before going to the solution:
1. For a node **U**, if it's parent node **X** is not deleted, then node **U** can't be a root of a forest.
2. For a node **U**, if it's parent node **X** is deleted and node **U** is not deleted then node **U** must be the root of its forest.
3. If we store the values to be deleted in a Hash Table, then for any node we can easily determine whether it should be deleted or not by checking the node value in the hash table. If that specific node's value is set in the hash table, then we can be sure that this node should be deleted otherwise not. 

We will traverse all nodes in the tree and use a **forest_root** list where root of all forests will be stored.
We will start from the root of the tree and do a Depth First Search traversal that means traverse from top to bottom and left to right.
When we stand at a node **U**, if this node **U** is going to be deleted, then just erase the edge that starts from its parent to itself. Then move to the next node of the DFS traversal. 
If this node **U** is not going to be deleted, then we will check whether its parent is deleted or not. If its parent exists and is not deleted, then we don't need to do anything in this node **U**, because the forest where the current node **U** is standing its root is already added to the **forest_root** list. So we will simply move to the next node of the DFS traversal. 
If its parent node is deleted or not exists at all, then we can be sure that node **U** is the root of its forest. So we will store the node **U** in the **forest_root** nodes list and remove the edge that comes from its parent to itself. 

In this way, when will complete traversing all the nodes in the tree, then the root of each forest will be stored in the **forest_root** list.

Here, we can see that at each node **U**, we need its parent information like whether it is deleted or not. So when going to a new node, we will send its parent information as well. At each node we need to determine whether it should be deleted or not. So first of all we will create a hashtable from the **to_delete** values list and check in this hash table at each node. 

#### Time Complexity:
We need to traverse each node exactly once. So time complexity is similar to the number of nodes in the tree. If there **N** nodes in the tree, then time complexity is **O(N)**.

#### Space Complexity:
We will do DFS traversal which is a recursive algorithm. In the worst case, all the nodes may need to be inserted in the recursion stack. So space complexity is also **O(N)**.
