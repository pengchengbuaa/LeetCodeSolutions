class TreeNode(var _value: Int) {
  var value: Int = _value
  var left: TreeNode = null
  var right: TreeNode = null

  def this(v: Int, l: TreeNode, r: TreeNode) {
    this(v)
    this.left = l;
    this.right = r;
  }
}

//value :(node value, sum value)
case class SumTreeNode(value: (Int, Int), left: SumTreeNode = null, right: SumTreeNode = null)

object Solution {

  def SumTree(root: TreeNode): SumTreeNode = {
    if (root == null) null
    if (root.left == null && root.right == null) return SumTreeNode((root.value, root.value))

    val leftSumT = if (root.left == null) null else SumTree(root.left)
    val rightSumT = if (root.right == null) null else SumTree(root.right)

    if (root.left == null) return SumTreeNode(
      if (rightSumT.value._2 > 0)
        (root.value, rightSumT.value._2 + root.value)
      else
        (root.value, root.value), null, rightSumT)

    if (root.right == null) return SumTreeNode(
      if (leftSumT.value._2 > 0)
        (root.value, leftSumT.value._2 + root.value)
      else
        (root.value, root.value), leftSumT, null)

    val maxChindT = math.max(leftSumT.value._2, rightSumT.value._2)
    SumTreeNode(if (maxChindT > 0) (root.value, root.value + maxChindT) else (root.value, root.value),
      leftSumT,
      rightSumT)
  }

  def maxSumTree(sumT: SumTreeNode): Int = {
    if (sumT.left == null && sumT.right == null) return sumT.value._2

    val leftMax = if (sumT.left == null) 0 else maxSumTree(sumT.left)
    val rightMax = if (sumT.right == null) 0 else maxSumTree(sumT.right)

    if (sumT.left == null) return math.max(sumT.value._2, rightMax)
    if (sumT.right == null) return math.max(sumT.value._2, leftMax)

    val NodeIncludeSum = sumT.left.value._2 + sumT.right.value._2 + sumT.value._1

    math.max(sumT.value._2,math.max(NodeIncludeSum, math.max(leftMax, rightMax)))

  }

  def maxPathSum(root: TreeNode): Int = {
    val sumTree = SumTree(root)
    maxSumTree(sumTree)
  }

  def main(args: Array[String]): Unit = {
    val t = new TreeNode(1, new TreeNode(2),
      new TreeNode(3))

    val t2 = new TreeNode(-10, new TreeNode(9),
      new TreeNode(20, new TreeNode(15), new TreeNode(7)))

    val t3 = new TreeNode(-2, new TreeNode(1), null)

    val t4 = new TreeNode(1,new TreeNode(-2), new TreeNode(3))
    println(maxPathSum(t))
    println(maxPathSum(t2))
    println(maxPathSum(t3))
    println(maxPathSum(t4))
  }

}

