using System;

namespace BST
{
    public class Tree
    {
        public int? value { get; private set; }
        public Tree left;
        public Tree right;
        public Tree parent;
        public int nodeCount;
        private int? rootValue = null;

        public int NodeCount
        {
            get
            {
                if (parent == null)
                {
                    return nodeCount;
                }
                else
                {
                    return -1;
                }
            }
        }

        public Tree()
        {
            value = null;
            left = null;
            right = null;
            parent = null;
            nodeCount = 0;
        }

        public void Push(int elem)
        {
            if (value == null || value == elem)
            {
                if (value == elem)
                {
                    nodeCount--;
                }

                value = elem;
            }

            if (value > elem)
            {
                if (left == null)
                {
                    left = new Tree();
                }
                Push(elem, left, this);
            }

            if (value < elem)
            {
                if (right == null)
                {
                    right = new Tree();
                }
                Push(elem, right, this);
            }

            nodeCount++;
        }

        private void Push(int elem, Tree node, Tree parent)
        {
            if (node.value == null || node.value == elem)
            {
                node.value = elem;
                node.parent = parent;
                return;
            }

            if (node.value > elem)
            {
                if (node.left == null)
                {
                    node.left = new Tree();
                }
                Push(elem, node.left, node);
            }

            if (node.value < elem)
            {
                if (node.right == null)
                {
                    node.right = new Tree();
                }
                Push(elem, node.right, node);
            }
        }

        public Tree Find(int elem)
        {
            Tree parent = this;
            while (parent.parent != null)
            {
                parent = parent.parent;
            }

            if (parent.value == elem)
            {
                return this;
            }

            if (parent.value > elem)
            {
                if (left == null)
                {
                    return null;
                }
                return Find(elem, parent.left);
            }

            if (value < elem)
            {
                if (right == null)
                {
                    return null;
                }
                return Find(elem, parent.right);
            }

            return null;
        }

        private Tree Find(int elem, Tree node)
        {
            if (node.value == elem)
            {
                return node;
            }

            if (node.value > elem)
            {
                if (node.left == null)
                {
                    return null;
                }

                return Find(elem, node.left);
            }

            if (node.value < elem)
            {
                if (node.right == null)
                {
                    return null;
                }
                return Find(elem, node.right);
            }

            return null;
        }

        public override string ToString()
        {
            if (left == null && right != null)
            {
                return String.Format("{0} <- {1} -> {2}", "null", value, right.value);
            }
            else if (left != null && right == null)
            {
                return String.Format("{0} <- {1} -> {2}", left.value, value, "null");
            }
            else if (left == null && right == null)
            {
                return String.Format("{0} <- {1} -> {2}", "null", value, "null");
            }
            else
            {
                return String.Format("{0} <- {1} -> {2}", left.value, value, right.value);
            }
        }

        public bool DeleteRight(int elem)
        {
            Tree treeElem = Find(elem);
            if (treeElem == null)
            {
                return false;
            }

            return DelRght(treeElem);
        }

        private bool DelRght(Tree elem)
        {
            if (elem.left == null && elem.right == null)
            {
                if (elem.parent.left == elem)
                {
                    elem.parent.left = null;
                }
                else
                {
                    elem.parent.right = null;
                }

                return true;
            }
            else if (elem.left != null && elem.right == null)
            {
                elem.left.parent = elem.parent;
                elem.parent.left = elem.left;

                return true;
            }
            else if (elem.left == null && elem.right != null)
            {
                elem.right.parent = elem.parent;
                elem.parent.right = elem.right;

                return true;
            }
            else
            {
                Tree newElem = elem.right;

                while (newElem.left != null)
                {
                    newElem = newElem.left;
                }

                DeleteRight((int)newElem.value);

                elem.value = newElem.value;

                return true;
            }
        }

        public bool DeleteLeft(int elem)
        {
            Tree treeElem = Find(elem);
            if (treeElem == null)
            {
                return false;
            }

            return DelLeft(treeElem);
        }

        private bool DelLeft(Tree elem)
        {
            if (elem.left == null && elem.right == null)
            {
                if (elem.parent.left == elem)
                {
                    elem.parent.left = null;
                }
                else
                {
                    elem.parent.right = null;
                }

                return true;
            }
            else if (elem.left != null && elem.right == null)
            {
                elem.left.parent = elem.parent;
                elem.parent.left = elem.left;

                return true;
            }
            else if (elem.left == null && elem.right != null)
            {
                elem.right.parent = elem.parent;
                elem.parent.right = elem.right;

                return true;
            }
            else
            {
                Tree newElem = elem.left;

                while (newElem.right != null)
                {
                    newElem = newElem.right;
                }

                DeleteRight((int)newElem.value);

                elem.value = newElem.value;

                return true;
            }
        }

        static public string CLR(Tree elem)
        {
            string path = "";

            path = elem.value.ToString();

            if (elem.left == null && elem.right == null)
            {
                return path;
            }
            else
            {
                if (elem.left != null)
                {
                    path += " " + CLR(elem.left);
                }
                if (elem.right != null)
                {
                    path += " " + CLR(elem.right);
                }

                return path;
            }
        }

        static public string LRC(Tree elem)
        {
            string path = "";

            if (elem.left == null && elem.right == null)
            {
                return elem.value.ToString();
            }
            else
            {
                if (elem.left != null)
                {
                    path += LRC(elem.left) + " ";
                }
                if (elem.right != null)
                {
                    path += LRC(elem.right) + " ";
                }

                path += elem.value.ToString();
                return path;
            }
        }

        static public string LCR(Tree elem)
        {
            string path = "";

            if (elem.left == null && elem.right == null)
            {
                return elem.value.ToString();
            }
            else
            {
                if (elem.left != null)
                {
                    path += LCR(elem.left) + " ";
                }

                path += elem.value.ToString() + " ";

                if (elem.right != null)
                {
                    path += LCR(elem.right) + " ";
                }

                return path;
            }
        }

        static public int Deep(Tree elem)
        {
            int deep = 0;

            while (elem.parent != null)
            {
                deep++;
                elem = elem.parent;
            }

            return deep;
        }

        static public int Height(Tree elem)
        {
            int height = 1;

            while (elem.left != null)
            {
                height++;
                elem = elem.left;
            }

            while (elem.right != null)
            {
                height++;
                elem = elem.right;
            }

            return height;
        }

        static public int Level(Tree elem)
        {
            int deep = Deep(elem);

            while (elem.parent != null)
            {
                elem = elem.parent;
            }

            return Height(elem) - deep;
        }

        public void Print()
        {
            Console.WriteLine();
            Tree node = this;
            while (node.parent != null)
            {
                node = node.parent;
            }

            rootValue = node.value;

            Console.Write("\u2514 ");
            Prnt(node);
            Console.WriteLine();
        }

        private void Prnt(Tree elem)
        {
            int deep = Deep(elem);

            Console.WriteLine(elem.value);

            //Console.WriteLine(" Deep = " + deep);

            Console.Write("  ");
            if (elem.left != null)
            {
                for (int i = 0; i < deep; i++)
                {
                    if (elem.left.value < rootValue)
                    {
                        if (i % 2 == 0)
                        {
                            Console.Write("\u2502    ");
                        }
                        else
                        {
                            Console.Write("     ");
                        }
                    }
                    else
                    {
                        Console.Write("     ");
                    }
                }
                Console.Write("\u251C L: ");
                Prnt(elem.left);
            }
            else if (elem.left == null && elem.right != null)
            {
                for (int i = 0; i < deep; i++)
                {
                    if (elem.right.value < rootValue)
                    {
                        Console.Write("\u2502    ");
                    }
                    else
                    {
                        Console.Write("     ");
                    }
                }
                Console.Write("\u251C L: ");
                Console.WriteLine("-");
                Console.Write("  ");
            }

            if (elem.right != null)
            {
                for (int i = 0; i < deep; i++)
                {
                    if (elem.right.value < rootValue)
                    {
                        if (i % 2 == 0)
                        {
                            Console.Write("\u2502    ");
                        }
                        else
                        {
                            Console.Write("     ");
                        }
                    }
                    else
                    {
                        Console.Write("     ");
                    }
                }

                Console.Write("\u2514 R: ");
                Prnt(elem.right);
            }
            else if (elem.left != null && elem.right == null)
            {
                for (int i = 0; i < deep; i++)
                {
                    if (elem.left.value < rootValue)
                    {
                        Console.Write("\u2502    ");
                    }
                    else
                    {
                        Console.Write("     ");
                    }
                }
                Console.Write("\u2514 R: ");

                Console.WriteLine("-");
                Console.Write("  ");
            }
        }

        public Tree[] GetLeafs(int[] elems)
        {
            Tree[] leafs = { };

            for (int i = 0; i < elems.Length; i++)
            {
                Tree node = Find(elems[i]);

                if (node != null && node.left == null && node.right == null)
                {
                    Array.Resize(ref leafs, leafs.Length + 1);
                    leafs[leafs.Length - 1] = node;
                }
            }

            return leafs;
        }

        public int[] GetNodes(int from, int rootNode)
        {
            Tree root = Find(rootNode);
            int[] nodes = { };

            Tree node = Find(from);
            while (node.parent != root.parent)
            {
                Array.Resize(ref nodes, nodes.Length + 1);
                nodes[nodes.Length - 1] = (int)node.value;
                node = node.parent;
            }

            Array.Resize(ref nodes, nodes.Length + 1);
            nodes[nodes.Length - 1] = (int)node.value;

            return nodes;
        }
    }
}
