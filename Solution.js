
/**
 @param {NestedInteger[]} nestedList
 @return {number}
 */
var depthSumInverse = function (nestedList) {

    const queue = [];
    queue.push(...nestedList);
    let depth = 0;

    let sum_Values = 0;
    let sum_Values_x_Depth = 0;

    while (queue.length > 0) {

        depth++;
        let size = queue.length;
        while (size-- > 0) {

            const current = queue.shift();
            if (current.isInteger()) {
                sum_Values += current.getInteger();
                sum_Values_x_Depth += current.getInteger() * depth;
            } else {
                queue.push(...current.getList());
            }
        }
    }

    //at this point the value of 'depth' is equal to the maxim depth for the input list.
    return (depth + 1) * sum_Values - sum_Values_x_Depth;
};

/*
 This interface is implemented internally by leetcode.com and should not be implemented
 by the person solving the problem. However, the problem must be solved only by applying this interface.
 
 If the participant tries to implement it on the website, then the test cases on leetcode.com will not be successful.
 */
function NestedInteger() {

    /*
     Return true if this NestedInteger holds a single integer, rather than a nested list.
     @return {boolean}
     */
    this.isInteger = function () {};

    /*  
     Return the single integer that this NestedInteger holds, if it holds a single integer
     Return null if this NestedInteger holds a nested list
     @return {integer}
     */
    this.getInteger = function () {};

    /*   
     Set this NestedInteger to hold a single integer equal to value.
     @return {void}
     */
    this.setInteger = function (value) {};

    /* 
     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
     @return {void}
     */
    this.add = function (elem) {};

    /*
     Return the nested list that this NestedInteger holds, if it holds a nested list
     Return null if this NestedInteger holds a single integer
     @return {NestedInteger[]}
     */
    this.getList = function () {};
}
