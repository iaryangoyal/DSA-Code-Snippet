#### Merge overlapping Intervals ####

# Example - I/P : an array intervals be [[1,3], [2,4], [5,7], [6,8]]. The intervals [1,3] and [2,4] overlap with each other,
# so they should be merged and become [1, 4]. Similarly, [5, 7] and [6, 8] should be merged and become [5, 8]

def mergeIntervals(intervals):

    if len(intervals) == 0 or len(intervals) == 1:
        return intervals

    intervals.sort(key=lambda x:x[0])
    result = [intervals[0]]

    for interval in intervals[1:]:
        # result[-1] stores the last element of the 2D list result
        if interval[0] <= result[-1][1]:
            result[-1][1] = max(result[-1][1], interval[1])
        else:
            result.append(interval)

    print(result) 
    # O/P : [[1, 6], [8, 10], [15, 19]]
    return result
 
# Driver code
arrayOfIntervals = [[1,3],[2,6],[8,10],[15,19], [16, 18]]
mergeIntervals(arrayOfIntervals)