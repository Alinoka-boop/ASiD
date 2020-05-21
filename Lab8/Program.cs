using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BST;
//В данном решении объединено первое и второе задание 
//В Tree.cs представлены основные операции с деревьями 
//ссылка на гитхаб https://github.com/Alinoka-boop/ASiD
namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            Tree tree = new Tree();
            int[] elems = { 20, 5, 40, 50 };//исходные данные 
            for (int i = 0; i < elems.Length; i++)
            {
                tree.Push(elems[i]);
            }

            tree.Print();

            Tree[] leafs = tree.GetLeafs(elems);
            int[] mTRN = { };                               
            int[] lTRN = { };                               
            int[] lVal = { }, rVal = { };
            int[,] deep = new int[leafs.Length, 2];
            int[,] rootDeep = new int[leafs.Length, 2];
            int rootLength = 0;
            int maxL = -1, maxR = -1;
            int wayLength;

            Tree root = tree.Find(elems[0]);
            int rootNode = elems[0];

            if (root.left == null || root.right == null)
            {
                for (int i = 0; i < leafs.Length; i++)
                {
                    rootDeep[i, 0] = (int)leafs[i].value;
                    rootDeep[i, 1] = Tree.Deep(leafs[i]) + 1;
                }

                for (int i = 0; i < rootDeep.GetLength(0); i++)
                {
                    if (rootLength < rootDeep[i, 1])
                    {
                        rootLength = rootDeep[i, 1];
                    }
                }

                while (!((root.left != null && root.right != null) || (root.left == null && root.right == null)))
                {
                    if (root.left != null)
                    {
                        root = root.left;
                        rootNode = (int)root.value;
                        continue;
                    }

                    root = root.right;
                    rootNode = (int)root.value;
                }
            }

            for (int i = 0; i < leafs.Length; i++)
            {
                deep[i, 0] = (int)leafs[i].value;
                deep[i, 1] = Tree.Deep(leafs[i]);

                if (deep[i, 0] > rootNode)
                {
                    Array.Resize(ref mTRN, mTRN.Length + 1);
                    Array.Resize(ref rVal, rVal.Length + 1);
                    mTRN[mTRN.Length - 1] = deep[i, 0];
                    rVal[rVal.Length - 1] = deep[i, 1];
                    if (maxR < rVal[rVal.Length - 1])
                    {
                        maxR = rVal[rVal.Length - 1];
                    }
                }
                else
                {
                    Array.Resize(ref lTRN, lTRN.Length + 1);
                    Array.Resize(ref lVal, lVal.Length + 1);
                    lTRN[lTRN.Length - 1] = deep[i, 0];
                    lVal[lVal.Length - 1] = deep[i, 1];
                    if (maxL < lVal[lVal.Length - 1])
                    {
                        maxL = lVal[lVal.Length - 1];
                    }
                }
            }

            wayLength = maxL + maxR - 1;
            int[] wayNodes = { };

            if (wayLength < rootLength)
            {
                for (int i = 0; i < rootDeep.GetLength(0); i++)
                {
                    if (rootDeep[i, 1] == rootLength)
                    {
                        int[] nodes = tree.GetNodes(rootDeep[i, 0], elems[0]);
                        Array.Resize(ref wayNodes, wayNodes.Length + nodes.Length);
                        for (int j = wayNodes.Length - nodes.Length, k = 0; j < wayNodes.Length; j++, k++)
                        {
                            wayNodes[j] = nodes[k];
                        }
                    }
                }
            }
            else if (wayLength == rootLength)
            {
                for (int i = 0; i < rootDeep.GetLength(0); i++)
                {
                    if (rootDeep[i, 1] == rootLength)
                    {
                        int[] nodes = tree.GetNodes(rootDeep[i, 0], elems[0]);
                        Array.Resize(ref wayNodes, wayNodes.Length + nodes.Length);
                        for (int j = wayNodes.Length - nodes.Length, k = 0; j < wayNodes.Length; j++, k++)
                        {
                            wayNodes[j] = nodes[k];
                        }
                    }
                }

                for (int i = 0; i < mTRN.Length; i++)
                {
                    if (rVal[i] == maxR)
                    {
                        int[] nodes = tree.GetNodes(mTRN[i], rootNode);
                        Array.Resize(ref wayNodes, wayNodes.Length + nodes.Length);
                        for (int j = wayNodes.Length - nodes.Length, k = 0; j < wayNodes.Length; j++, k++)
                        {
                            wayNodes[j] = nodes[k];
                        }
                    }
                }

                for (int i = 0; i < lTRN.Length; i++)
                {
                    if (lVal[i] == maxL)
                    {
                        int[] nodes = tree.GetNodes(lTRN[i], rootNode);
                        Array.Resize(ref wayNodes, wayNodes.Length + nodes.Length);
                        for (int j = wayNodes.Length - nodes.Length, k = 0; j < wayNodes.Length; j++, k++)
                        {
                            wayNodes[j] = nodes[k];
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < mTRN.Length; i++)
                {
                    if (rVal[i] == maxR)
                    {
                        int[] nodes = tree.GetNodes(mTRN[i], rootNode);
                        Array.Resize(ref wayNodes, wayNodes.Length + nodes.Length);
                        for (int j = wayNodes.Length - nodes.Length, k = 0; j < wayNodes.Length; j++, k++)
                        {
                            wayNodes[j] = nodes[k];
                        }
                    }
                }

                for (int i = 0; i < lTRN.Length; i++)
                {
                    if (lVal[i] == maxL)
                    {
                        int[] nodes = tree.GetNodes(lTRN[i], rootNode);
                        Array.Resize(ref wayNodes, wayNodes.Length + nodes.Length);
                        for (int j = wayNodes.Length - nodes.Length, k = 0; j < wayNodes.Length; j++, k++)
                        {
                            wayNodes[j] = nodes[k];
                        }
                    }
                }
            }

            Array.Sort(wayNodes);
            wayNodes = wayNodes.Distinct().ToArray();

            foreach (int i in wayNodes)
                Console.Write(i + " ");

            if (wayNodes.Length < 2)
            {
                Console.WriteLine("Невозможно удалить, так как элементов в пути меньше 2-ух");
            }
            else
            {
                tree.DeleteRight(wayNodes[1]);
            }

            tree.Print();

            Console.WriteLine(Tree.CLR(tree));

            Console.ReadKey();
        }
    }
}
