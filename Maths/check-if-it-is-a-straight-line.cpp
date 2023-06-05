/*

https://leetcode.com/problems/check-if-it-is-a-straight-line

Intuition
Make the equation of line and check for each point.

Approach
The equation of a line if two points are given is given by:
y-y1 = m * (x-x1),
where x1,y1 are coordinates of a point and m is the slope of the line, m is given by:
(y2-y1)/(x2-x1), where (x1,y1) and (x2,y2) are the coordinates of two points.

But before this lets consider the corner cases when slope evaluates to 0 or 1.
If m==0 then the line is parallel to x-axis so all the points should have same y coordinate.
If m==Infinity(when x2-x1==0) then the line is parallel to y-axis so all the points should have same x coordinate.

Complexity
Time complexity: O(n)
Space complexity: O(1)


*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n==1) return true;
        double x1=coordinates[0][0];
        double y1=coordinates[0][1];
        double x2=coordinates[1][0];
        double y2=coordinates[1][1];
        double m;
        if(x2-x1==0){
            double X=coordinates[0][0];
            for(int i=0;i<n;i++){
                if(coordinates[i][0]!=X) return false;
            }
            return true;
        }
        else if(y2-y1==0){
            double Y=coordinates[0][1];
            for(int i=0;i<n;i++){
                if(coordinates[i][1]!=Y) return false;
            }
            return true;
        }
        m=(y2-y1)/(x2-x1);
        for(int i=1;i<n;i++){
            double y=(m*(coordinates[i][0]-x1))+y1;
            if((double)coordinates[i][1]!=y) return false;
        }
        return true;
    }
};
