class TreeNode(var _value: Int) {
  var value: Int = _value
  var left: TreeNode = null
  var right: TreeNode = null

  def this(v: Int, l: TreeNode, r: TreeNode) {
    this(v)
    this.left = l
    this.right = r
  }
}

object Solution {

  def Symmm(left: TreeNode, right: TreeNode): Boolean = {
    if (left == null && right == null) true
    else if (left == null || right == null) false
    else {
      val a = (left.value == right.value);
      Symmm(left.left, right.right) && Symmm(left.right, right.left) && a
    }
  }

  def isSymmetric(root: TreeNode): Boolean = {
    if (root == null) true
    else Symmm(root.left, root.right)
  }

  def main(args: Array[String]): Unit = {

    var s = new TreeNode(1,
      new TreeNode(2, new TreeNode(3), new TreeNode(4)),
      new TreeNode(2, new TreeNode(4), new TreeNode(3)))

    println(isSymmetric(s))
  }
}
