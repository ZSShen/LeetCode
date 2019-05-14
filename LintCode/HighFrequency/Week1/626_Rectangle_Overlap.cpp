/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param l1: top-left coordinate of first rectangle
     * @param r1: bottom-right coordinate of first rectangle
     * @param l2: top-left coordinate of second rectangle
     * @param r2: bottom-right coordinate of second rectangle
     * @return: true if they are overlap or false
     */
    bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2) {
        // write your code here

        /**
         *
         *   ------
         *   |    |
         *   |  |-----|  => Too complicated, too many cases to consider.
         *   |--|-|   |
         *      |     |
         *      |-----|
         *
         *                         -----
         *   ------   ------       |   |
         *   |    |   |    |       |   |
         *   |----|   |----|       -----
         *        (1st)            (2nd)
         *                              -----
         *                              |   |
         *                              |   |
         *                              -----
         */

        // 1st boundary case
        if (r1.x < l2.x || r2.x < l1.x) {
            return false;
        }

        // 2nd boundary case
        if (r1.y > l2.y || r2.y > l1.y) {
            return false;
        }

        return true;
    }
};