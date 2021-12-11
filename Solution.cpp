
#include <deque>
using namespace std;

/*
 This interface is implemented internally by leetcode.com and should not be implemented
 by the person solving the problem. However, the problem must be solved only by applying this interface.
 
 If the participant tries to implement it on the website, then the test cases on leetcode.com will not be successful.
 */

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};

class Solution {
public:

    int depthSumInverse(vector<NestedInteger>& nestedList) {

        deque<NestedInteger>* queue = new deque<NestedInteger>(nestedList.begin(), nestedList.end());

        int depth = 0;
        int sum_Values = 0;
        int sum_Values_x_Depth = 0;

        while (queue->size() > 0) {

            depth++;
            int size = queue->size();
            while (size-- > 0) {

                NestedInteger current = queue->front();
                queue->pop_front();
                if (current.isInteger()) {
                    sum_Values += current.getInteger();
                    sum_Values_x_Depth += current.getInteger() * depth;
                } else {
                    for (int i = 0; i < current.getList().size(); i++) {
                        queue->push_back(current.getList()[i]);
                    }
                }
            }
        }

        //at this point the value of 'depth' is equal to the maxim depth for the input list.
        return (depth + 1) * sum_Values - sum_Values_x_Depth;
    }
};
