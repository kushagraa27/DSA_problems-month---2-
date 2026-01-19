// problem: 452. Minimum Number of Arrows to Burst Balloons
// difficulty: medium
// topic: array, greedy, sorting

// Approach:
// We use a greedy strategy to minimize the number of arrows.
// Each balloon is represented as an interval [start, end].
//
// First, we sort all balloons in ascending order of their end positions.
// This allows us to always shoot an arrow at the earliest possible end point,
// which can burst the maximum number of overlapping balloons.
//
// We shoot the first arrow at the end position of the first balloon.
// Then, for each remaining balloon:
// - If its start position is greater than the position of the last arrow,
//   it means the balloon cannot be burst by the current arrow.
//   So, we shoot a new arrow at the end of this balloon.
// - Otherwise, the current arrow already bursts this balloon.
//
// Finally, we return the total number of arrows used.

// time: O(n log n)
// space: O(1)
// link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
      sort(points.begin(),points.end(),
            [](const vector<int> &a,const vector<int> &b){
                return a[1]<b[1];
            });
            int arrows = 1;
            int lastarrow = points[0][1];
            for(int i=1;i<points.size();i++)
            {
                if(points[i][0]>lastarrow)
                {
                    arrows++;
                    lastarrow= points[i][1];
                }
            }
            return arrows;
    }
};

