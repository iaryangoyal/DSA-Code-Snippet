# Function to find the maximum sum of a contiguous subarray
# in a given integer array
def kadaneAlgo(inputArray):
 
    # stores the maximum sum of the subarray found so far
    max_so_far = 0
 
    # stores the maximum sum of subarray ending at the current position
    max_ending_here = 0
 
    for i in inputArray:
        # update the maximum sum of subarray "ending" at index `i` (by adding the
        # current element to maximum sum ending at previous index `i-1`)
        max_ending_here = max_ending_here + i
 
        # if the maximum sum is negative, set it to 0 
        max_ending_here = max(max_ending_here, 0)
 
        # update the result if the current sublist sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here)
 
    return max_so_far
 
 
inputArray = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

# O/P : 6
print("Maximum contiguous sum is ", kadaneAlgo(inputArray))