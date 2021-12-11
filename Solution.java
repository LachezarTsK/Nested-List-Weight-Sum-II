
import java.util.List;
import java.util.LinkedList;

public class Solution {

    public int depthSumInverse(List<NestedInteger> nestedList) {

        LinkedList<NestedInteger> queue = new LinkedList<>();
        queue.addAll(nestedList);
        int depth = 0;

        int sum_Values = 0;
        int sum_Values_x_Depth = 0;

        while (!queue.isEmpty()) {

            depth++;
            int size = queue.size();
            while (size-- > 0) {

                NestedInteger current = queue.removeFirst();
                if (current.isInteger()) {
                    sum_Values += current.getInteger();
                    sum_Values_x_Depth += current.getInteger() * depth;
                } else {
                    queue.addAll(current.getList());
                }
            }
        }

        //at this point the value of 'depth' is equal to the maxim depth for the input list.
        return (depth + 1) * sum_Values - sum_Values_x_Depth;
    }
}

/*
 This interface is implemented internally by leetcode.com and should not be implemented
 by the person solving the problem. However, the problem must be solved only by applying this interface.
 
 If the participant tries to implement it on the website, then the test cases on leetcode.com will not be successful.
 */
interface NestedInteger {
    
    // Constructor initializes an empty nested list.
    public NestedInteger();

    // Constructor initializes a single integer.
    public NestedInteger(int value);
    
    // @return true if this NestedInteger holds a single integer, rather than a nested list.
    public boolean isInteger();

    // @return the single integer that this NestedInteger holds, if it holds a single integer
    // Return null if this NestedInteger holds a nested list
    public Integer getInteger();

    // Set this NestedInteger to hold a single integer.
    public void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    public void add(NestedInteger ni);

    // @return the nested list that this NestedInteger holds, if it holds a nested list
    // Return empty list if this NestedInteger holds a single integer
    public List<NestedInteger> getList();
}
